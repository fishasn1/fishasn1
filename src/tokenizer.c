#include <string.h>
#include <stdio.h>

#include "tokenizer.h"

char next_char(tokenizer_t *tokenizer) {
        char ch;
        if (tokenizer->pos <= strlen(tokenizer->stream) - 1) {
                ch = tokenizer->stream[tokenizer->pos];
                tokenizer->pos++;
        } else {
                ch = 0;
        }
        return ch;
}

char peek_char(tokenizer_t *tokenizer) {
        char ch;
        if (tokenizer->pos + 1 <= strlen(tokenizer->stream) - 1) {
                ch = tokenizer->stream[tokenizer->pos + 1];
        } else {
                ch = 0;
        }
        return ch;
}
