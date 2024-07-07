#include <string.h>
#include <stdio.h>
#include <stdbool.h>

#include "tokenizer.h"


bool 
is_white_space(char ch) {
        if (ch == 9 || ch == 10 || ch == 11 || ch == 12 || ch == 13 ||
                        ch == 32) {
                return true;
        }
        return false;
}

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
