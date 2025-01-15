
#include "../../headers/utils.h"

// function determine the whole number and parse it into a double
void isNumber(char *cursor, FILE *file) {
  ungetc(*(cursor), file);

  TokenLiteral token;
  token.type = INT;
  token.value = 0;

  while ((*cursor = fgetc(file)) != EOF) {
    if (!isdigit(*(cursor))) {
      printf("%lf\n", token.value);
      ungetc(*(cursor), file);
      return;
    }

    token.value *= 10;
    token.value += ((double)*cursor - '0');
  }
}

// Function to read the whole token and determine whether it is a type or an
// identifier or a keyword
void identifyAlpha(char *cursor, FILE *file) {
  ungetc(*(cursor), file);
  TokenLiteral alpha;
  char *token = (char *)malloc(sizeof(char));
  token[0] = '\0';

  if (token == NULL) {
    free(token);
    token = NULL;
    perror("Memory allocation failed.\n");
    return;
  }

  while ((*cursor = fgetc(file)) != EOF) {
    if (!isalpha(*(cursor))) {
      if (!strcmp(token, "int")) {
        alpha.type = INT;
        printf("%s TYPE Found!!\n", alpha.type ? "INT" : "");
      } else if (!strcmp(token, "float")) {
        alpha.type = FLOAT;
        printf("FLOAT TYPE Found!!\n");
      } else {
        alpha.type = IDENTIFIER;
        printf("IDENTIFIER Found!!\n");
      }
      free(token);
      token = NULL;
      ungetc(*(cursor), file);
      return;
    }

    char *tmp = (char *)realloc(token, (strlen(token) + 2));
    if (tmp == NULL) {
      free(token);
      token = NULL;
      return;
    }

    token = tmp;

    size_t len = strlen(token);
    token[len] = *cursor;
    token[len + 1] = '\0';
  }
}

void lexer(FILE *file) {
  char cursor;

  while ((cursor = fgetc(file)) != EOF) {
    if (cursor == ':')
      printf("COLONS Found!!\n");
    else if (cursor == '=')
      printf("AFFECT FOUND!!\n");
    else if (cursor == ';')
      printf("SEMICOLONS Found!!\n");
    else if (isalpha(cursor))
      identifyAlpha(&cursor, file);
    else if (isdigit(cursor)) {
      printf("NUMBER found!!\n");
      isNumber(&cursor, file);
    }
  }
}
