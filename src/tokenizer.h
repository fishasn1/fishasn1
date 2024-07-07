#ifndef TOKENIZER_H_
#define TOKENIZER_H_

typedef enum {
        TOKEN_ABSENT,
        TOKEN_ABSTRACT_SYNTAX,
        TOKEN_ALL,
        TOKEN_APPLICATION,
        TOKEN_AUTOMATIC
} TOKEN_TYPE_ENUM;

typedef struct {
        TOKEN_TYPE_ENUM type;
        char *value;
} token_t;

typedef struct {
    char *stream;
    unsigned int pos;
} tokenizer_t;

char next_char(tokenizer_t *tokenizer);
char peek_char(tokenizer_t *tokenizer);
#endif /* TOKENIZER_H_ */
