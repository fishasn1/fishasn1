#ifndef TOKENIZER_H_
#define TOKENIZER_H_
#include <stdbool.h>

#define ABSENT "ABSENT"
#define ABSTRACT_SYNTAX "ABSTRACT-SYNTAX"
#define ALL "ALL"
#define APPLICATION "APPLICATION"
#define AUTOMATIC "AUTOMATIC"
#define BEGIN "BEGIN"
#define BIT "BIT"
#define BMPString "BMPString"
#define BOOLEAN "BOOLEAN"
#define BY "BY"
#define CHARACTER "CHARACTER"
#define CHOICE "CHOICE"
#define CLASS "CLASS"
#define COMPONENT "COMPONENT"
#define COMPONENTS "COMPONENTS"
#define CONSTRAINED "CONSTRAINED"
#define CONTAINING "CONTAINING"
#define DATE "DATE"
#define DATE_TIME "DATE-TIME"
#define DEFAULT "DEFAULT"
#define DEFINITIONS "DEFINITIONS"
#define DURATION "DURATION"

typedef enum {
        TOKEN_ABSENT,
        TOKEN_ABSTRACT_SYNTAX,
        TOKEN_ALL,
        TOKEN_APPLICATION,
        TOKEN_AUTOMATIC,
        TOKEN_BEGIN,
        TOKEN_BIT,
        TOKEN_BMPString,
        TOKEN_BOOLEAN,
        TOKEN_BY,
        TOKEN_CHARACTER,
        TOKEN_CHOICE,
        TOKEN_CLASS,
        TOKEN_COMPONENT,
        TOKEN_COMPONENTS,
        TOKEN_CONSTRAINED,
        TOKEN_CONTAINING,
        TOKEN_DATE,
        TOKEN_DATE_TIME,
        TOKEN_DEFAULT,
        TOKEN_DEFINITIONS,
        TOKEN_DURATION,
        TOKEN_UNKNOWN
} TOKEN_TYPE_ENUM;

typedef struct {
        TOKEN_TYPE_ENUM type;
        unsigned char *value;
} token_t;

typedef struct {
    char *stream;
    unsigned int pos;
} tokenizer_t;

bool is_eof(char ch);
bool is_white_space(char ch);
char next_char(tokenizer_t *tokenizer);
char peek_char(tokenizer_t *tokenizer);

token_t*
next_token(tokenizer_t *tokenizer);
#endif /* TOKENIZER_H_ */
