#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "tokenizer.h"


bool 
is_eof(char ch) {
        if (ch == '\0') {
                return true;
        }
        return false;
}

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
        if (tokenizer->pos <= strlen(tokenizer->stream) - 1) {
                ch = tokenizer->stream[tokenizer->pos];
        } else {
                ch = 0;
        }
        return ch;
}

token_t*
match_reserved_words(tokenizer_t *tokenizer) {
        unsigned char current;
        unsigned char *buffer;
        unsigned int start_pos = tokenizer->pos;
        unsigned int index = 0;
        token_t *token = malloc(sizeof(token_t));

        /* skip white spaces */
        current = next_char(tokenizer);
        while(is_white_space(current)) {
                current = next_char(tokenizer);
        }

        /* 
         * Check reserved words first 
         */
        buffer = (unsigned char*)malloc(50);
        while(!(is_white_space(current) || is_eof(current))) {
                buffer[index] = current;
                index++;
                current = next_char(tokenizer);
        }

        buffer[index] = '\0';
        
        if (strcmp((const char*)buffer, ABSENT) == 0) {
                token->type = TOKEN_ABSENT;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, ABSTRACT_SYNTAX) == 0) {
                token->type = TOKEN_ABSTRACT_SYNTAX;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, ALL) == 0) {
                token->type = TOKEN_ALL;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, APPLICATION) == 0) {
                token->type = TOKEN_APPLICATION;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, AUTOMATIC) == 0) {
                token->type = TOKEN_AUTOMATIC;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, BEGIN) == 0) {
                token->type = TOKEN_BEGIN;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, BIT) == 0) {
                token->type = TOKEN_BIT;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, BMPString) == 0) {
                token->type = TOKEN_BMPString;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, BOOLEAN) == 0) {
                token->type = TOKEN_BOOLEAN;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, BY) == 0) {
                token->type = TOKEN_BY;
                token->value = buffer;
        } else {
                token->type = TOKEN_UNKNOWN;
                token->value = buffer;
                tokenizer->pos = start_pos;
        }
        return token;
}

token_t*
next_token(tokenizer_t *tokenizer) {
        token_t *token = match_reserved_words(tokenizer);

        return token;
}
