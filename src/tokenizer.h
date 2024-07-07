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
