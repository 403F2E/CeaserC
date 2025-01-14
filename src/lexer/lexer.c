
#include "../../headers/utils.h"

void isNumber(char *cursor, FILE *file) {
  TokenLiteral token;
  token.type = INT;
  token.value = 0;

  while (*cursor != EOF) {
    if (!isdigit(*(cursor))) {
      printf("%lf\n", token.value);
      ungetc(*(cursor), file);
      return;
    }

    token.value *= 10;
    token.value += ((int)*cursor - '0');

    *cursor = fgetc(file);
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
    else if (cursor == 'i')
      printf("INT TYPE Found!!\n");
    else if (isdigit(cursor)) {
      isNumber(&cursor, file);
      printf("NUMBER FOUND!!\n");
    }
  }
}
