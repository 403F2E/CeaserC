
#include "../../include/core/token_list.h"
#include "../../include/lexer/tokenizer.h"

#include <stdbool.h>
#include <stddef.h>
#include <string.h>

typedef struct {
  const char *keyword;
  size_t length;
} Keyword;

static const Keyword keywords[] = {{"bit", 3},          {"bits", 4},
                                   {"byte", 4},         {"word", 4},
                                   {"poly", 4},         {"lattice", 7},
                                   {"field", 5},        {"group", 5},
                                   {"type", 4},         {"struct", 6},
                                   {"qubit", 5},        {"qureg", 5},
                                   {"qcircuit", 8},     {"qgate", 5},
                                   {"measure", 7},      {"superpose", 9},
                                   {"if", 2},           {"else", 4},
                                   {"elif", 4},         {"try", 3},
                                   {"catch", 5},        {"finally", 7},
                                   {"match", 5},        {"case", 4},
                                   {"for", 3},          {"while", 5},
                                   {"dowhile", 7},      {"apply", 5},
                                   {"transform", 9},    {"permute", 7},
                                   {"round", 5},        {"with", 4},
                                   {"assert", 6},       {"assume", 6},
                                   {"return", 6},       {"yield", 5},
                                   {"add_mod", 7},      {"mul_mod", 7},
                                   {"exp_mod", 7},      {"inv_mod", 7},
                                   {"sample", 6},       {"compress", 8},
                                   {"decompress", 10},  {"hash", 4},
                                   {"@verifiable", 11}, {"@constant_time", 14},
                                   {"@pure", 5},        {"@leak_free", 10},
                                   {"prove", 5},        {"invariant", 9},
                                   {"requires", 8},     {"secret", 6},
                                   {"public", 6},       {"zeroize", 7},
                                   {"constant", 8},     {"volatile", 8},
                                   {"aligned", 7},      {"namespace", 9},
                                   {"import", 6},       {"export", 6},
                                   {"use", 3},          {"as", 2},
                                   {"opaque", 6},       {"true", 4},
                                   {"false", 5},        {"infinity", 8}};

static TOKENTYPE lookup_keyword(Lexer *lexer) {
  size_t length = lexer->current - lexer->start;

  size_t count = sizeof(keywords) / sizeof(keywords[0]);

  for (size_t i = 0; i < count; i++) {
    if (keywords[i].length != length)
      continue;

    if (memcmp(lexer->start, keywords[i].keyword, length) == 0) {
      return TOKEN_KEYWORD;
    }
  }

  return TOKEN_IDENTIFIER;
}

// Checking the start of the keyword/identifier
static bool is_identifier_start(char c) {
  return c == '_' || c == '@' || isalpha((unsigned char)c);
}

// Checking the current char if is alphanum
static bool is_identifier_char(char c) {
  return isalnum((unsigned char)c) || c == '_';
}

// Consume spaces, tabs, newlines, comments
static void skip_whitespace(Lexer *lexer) {
  while (*lexer->current != '\0') {
    switch (*lexer->current) {
    case ' ':
    case '\t':
    case '\r':
      lexer->current++;
      lexer->column++;
      break;

    case '\n':
      lexer->current++;
      lexer->line++;
      lexer->column = 1;
      break;

    default:
      return;
    }
  }
}

static Token scan_identifier(Lexer *lexer) {
  while (is_identifier_char(*lexer->current)) {
    lexer->current++;
    lexer->column++;
  }

  return tokenize(lexer, lookup_keyword(lexer));
}

// function determine the whole number
static Token scan_number(Lexer *lexer) {
  while (isdigit(*lexer->current)) {
    lexer->current++;
    lexer->column++;
  }

  return tokenize(lexer, TOKEN_NUMERIC);
}

/*** The process to identify symbols ***/
// checks is included in the standard symbols
static bool issymbol(char cursor) {
  return (cursor == ':' || cursor == ';' || cursor == '=' || cursor == '(' ||
          cursor == ')' || cursor == '{' ||
          cursor == '}'); // symbols currently identified
}
// checks if included in the standard escape sequence list
static bool isescape_sequence(char cursor) {
  const char escapeseq[] = "\"\'\v\b\r\\";
  return strchr(escapeseq, cursor) != NULL;
}
// tokenize the symbol
static Token scan_operator(Lexer *lexer) {
  char current = *lexer->current;

  lexer->current++;
  lexer->column++;

  if (issymbol(current))
    return tokenize(lexer, TOKEN_SYMBOL);
  else if (isescape_sequence(*lexer->current))
    return tokenize(lexer, TOKEN_ESCSEQ);
  else
    return tokenize(lexer, TOKEN_UNKNOWN);
}

static Token scan_string(Lexer *lexer) {
  lexer->current++;
  lexer->column++;

  while (*lexer->current != '"' && *lexer->current != '\0') {
    lexer->current++;
    lexer->column++;
  }

  if (*lexer->current == '"') {
    lexer->current++;
    lexer->column++;
  }

  return tokenize(lexer, TOKEN_STRING);
}

/*
 * lexer function
 */
TokenList *lexer_scan(Lexer lexer) {
  TokenList *tokens = create_token_list();

  if (!tokens)
    return NULL;

  while (*lexer.current != '\0') {
    skip_whitespace(&lexer);

    lexer.start = lexer.current;

    Token token;

    if (is_identifier_start(*lexer.current))
      token = scan_identifier(&lexer);

    else if (isdigit(*lexer.current))
      token = scan_number(&lexer);

    else if (*lexer.current == '"')
      token = scan_string(&lexer);

    else
      token = scan_operator(&lexer);

    push_token_list(tokens, token);
  }

  push_token_list(tokens, tokenize(&lexer, TOKEN_EOF));

  return tokens;
}
