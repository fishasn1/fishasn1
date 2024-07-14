#include <assert.h>
#include <string.h>
#include <stdio.h>

#include "tokenizer.h"

int main(int argc, char **argv) {
        char *stream = "12345. 12345.1 12345.123.67  12345.1e123E\
                        333.1e--123 123456e123 123456e-123 123456E123\
                        0123 0.000 0 0.00002";
        tokenizer_t *tokenizer = tokenizer_create(stream);

        token_t *token;

        token = next_token(tokenizer);
        assert(token->type == TOKEN_REAL_NUMBER);
        assert(strcmp((const char *)token->value, "12345.") == 0);

        token = next_token(tokenizer);
        assert(token->type == TOKEN_REAL_NUMBER);
        assert(strcmp((const char*)token->value, "12345.1") == 0);

        token = next_token(tokenizer);
        assert(token->type == TOKEN_ERROR);
        assert(strcmp((const char*)token->value, "12345.123.67") == 0);

        token = next_token(tokenizer);
        assert(token->type == TOKEN_ERROR);
        assert(strcmp((const char*)token->value, "12345.1e123E") == 0);

        token = next_token(tokenizer);
        assert(token->type == TOKEN_ERROR);
        assert(strcmp((const char*)token->value, "333.1e--123") == 0);

        token = next_token(tokenizer);
        assert(token->type == TOKEN_REAL_NUMBER);
        assert(strcmp((const char*)token->value, "123456e123") == 0);

        token = next_token(tokenizer);
        assert(token->type == TOKEN_REAL_NUMBER);
        assert(strcmp((const char*)token->value, "123456e-123") == 0);

        token = next_token(tokenizer);
        assert(token->type == TOKEN_REAL_NUMBER);
        assert(strcmp((const char*)token->value, "123456E123") == 0);

        token = next_token(tokenizer);
        assert(token->type == TOKEN_ERROR);
        assert(strcmp((const char*)token->value, "0123") == 0);

        token = next_token(tokenizer);
        assert(token->type == TOKEN_ERROR);
        assert(strcmp((const char*)token->value, "0.000") == 0);

        token = next_token(tokenizer);
        assert(token->type == TOKEN_NUMBER);
        assert(strcmp((const char*)token->value, "0") == 0);

        token = next_token(tokenizer);
        assert(token->type == TOKEN_REAL_NUMBER);
        assert(strcmp((const char*)token->value, "0.00002") == 0);

        return 0;
}
