
#include "../../include/core/token_list.h"
#include "../../include/lexer/tokenizer.h"

static struct {
  const char *name;
  enum TOKENTYPE type;
} keywords[] = {
#define X(type, name) {name, type},
    KEYWORD_LIST
#undef X
};

static enum TOKENTYPE lookup_keyword(struct Lexer *lexer) {
  size_t length = lexer->current - lexer->start;

  size_t count = sizeof(keywords) / sizeof(keywords[0]);

  for (size_t i = 0; i < count; i++) {
    if (strlen(keywords[i].name) != length)
      continue;

    if (memcmp(lexer->start, keywords[i].name, length) == 0) {
      return keywords[i].type;
    }
  }

  return TOKEN_IDEN;
}

// Checking the start of the keyword/identifier
static bool is_identifier_start(char c) {
  return c == '_' || isalpha((unsigned char)c) || c == '@';
}

// Checking the current char if is alphanum
static bool is_identifier_char(char c) {
  return isalnum((unsigned char)c) || c == '_';
}

// Consume spaces, tabs, newlines, comments
static void skip_whitespace(struct Lexer *lexer) {
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

static struct Token scan_identifier(struct Lexer *lexer) {

  do {
    lexer->current++;
    lexer->column++;
  } while (is_identifier_char(*lexer->current));

  return tokenize(lexer, lookup_keyword(lexer));
}

// function determine the whole number
static struct Token scan_numeric(struct Lexer *lexer) {
  do {
    lexer->current++;
    lexer->column++;
  } while (isdigit(*lexer->current) || *lexer->current == '.' ||
           *lexer->current == '_');

  return tokenize(lexer, TOKEN_NUMERIC);
}

/*** The process to identify symbols ***/
// checks is included in the standard symbols
static struct {
  const char *name;
  enum TOKENTYPE type;
} symbols[] = {
#define X(type, name) {name, type},
    SYMBOL_LIST
#undef X
};

static enum TOKENTYPE lookup_symbol(struct Lexer *lexer) {
  size_t length = lexer->current - lexer->start;

  size_t count = sizeof(symbols) / sizeof(symbols[0]);

  for (size_t i = 0; i < count; i++) {
    if (memcmp(lexer->start, symbols[i].name, length) == 0) {
      return symbols[i].type;
    }
  }

  return TOKEN_UNKNOWN;
}

// tokenize the symbol
static struct Token scan_operator(struct Lexer *lexer) {
  do {
    lexer->current++;
    lexer->column++;
  } while (*lexer->current == '=');

  return tokenize(lexer, lookup_symbol(lexer));
}

static struct Token scan_string(struct Lexer *lexer) {
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
struct TokenList *lexer_scan(struct Lexer *lexer) {
  struct TokenList *tokens = create_token_list();

  if (!tokens)
    return NULL;

  while (*lexer->current != '\0') {
    skip_whitespace(lexer);

    lexer->start = lexer->current;

    struct Token token;

    if (is_identifier_start(*lexer->current))
      token = scan_identifier(lexer);

    else if (isdigit(*lexer->current))
      token = scan_numeric(lexer);

    else if (*lexer->current == '"')
      token = scan_string(lexer);

    else
      token = scan_operator(lexer);

    push_token_list(tokens, token);
  }

  push_token_list(tokens, tokenize(lexer, TOKEN_EOF));

  return tokens;
}
