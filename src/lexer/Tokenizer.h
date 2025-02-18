
#pragma once

// List of Keyword of the language
typedef enum {
  DEF,
  CLASS,
  EXIT,
} TypeKeyword;

// List of Sepcial Symbols of the language
typedef enum {
  AFFECT,
  COLON,
  SEMI,
  OPEN_PAREN,
  CLOSE_PAREN,
} TypeSeparator;

// List of Comaprison Keyword of the language
typedef enum {
  EQUAL,
  GTHAN,
  ITHAN,
  GT_EQUAL,
  IT_EQUAL,
} TypeComparison;

// List of Types built for the variable of the languge
typedef enum {
  IDENTIFIER,
  INT,
  FLOAT,
  CHAR,
  STRING,
  BOOL,
} TypeLiteral;

// building the structs for each token type
typedef struct {
  TypeKeyword type;
} TokenKeyword;

typedef struct {
  TypeSeparator type;
} TokenSeparator;

typedef struct {
  TypeComparison type;
} TokenComparison;

typedef struct {
  TypeLiteral type;
  double value;
} TokenLiteral;

typedef struct {
  // til finding the listing method for sendin to the parser
} TokensList;
