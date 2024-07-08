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

char 
next_char(tokenizer_t *tokenizer) {
        char ch;
        if (tokenizer->pos <= strlen(tokenizer->stream) - 1) {
                ch = tokenizer->stream[tokenizer->pos];
                tokenizer->pos++;
        } else {
                ch = 0;
        }
        return ch;
}

char 
peek_char(tokenizer_t *tokenizer) {
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
        } else if (strcmp((const char*)buffer, CHARACTER) == 0) {
                token->type = TOKEN_CHARACTER;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, CHOICE) == 0) {
                token->type = TOKEN_CHOICE;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, CLASS) == 0) {
                token->type = TOKEN_CLASS;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, COMPONENT) == 0) {
                token->type = TOKEN_COMPONENT;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, COMPONENTS) == 0) {
                token->type = TOKEN_COMPONENTS;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, CONSTRAINED) == 0) {
                token->type = TOKEN_CONSTRAINED;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, CONTAINING) == 0) {
                token->type = TOKEN_CONTAINING;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, DATE) == 0) {
                token->type = TOKEN_DATE;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, DATE_TIME) == 0) {
                token->type = TOKEN_DATE_TIME;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, DEFAULT) == 0) {
                token->type = TOKEN_DEFAULT;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, DEFINITIONS) == 0) {
                token->type = TOKEN_DEFINITIONS;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, DURATION) == 0) {
                token->type = TOKEN_DURATION;
                token->value = buffer;

        } else if (strcmp((const char*)buffer, EMBEDDED) == 0) {
                token->type = TOKEN_EMBEDDED;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, ENCODED) == 0) {
                token->type = TOKEN_ENCODED;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, ENCODING_CONTROL) == 0) {
                token->type = TOKEN_ENCODING_CONTROL;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, END) == 0) {
                token->type = TOKEN_END;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, ENUMERATED) == 0) {
                token->type = TOKEN_ENUMERATED;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, EXCEPT) == 0) {
                token->type = TOKEN_EXCEPT;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, EXPLICIT) == 0) {
                token->type = TOKEN_EXPLICIT;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, EXPORTS) == 0) {
                token->type = TOKEN_EXPORTS;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, EXTENSIBILITY) == 0) {
                token->type = TOKEN_EXTENSIBILITY;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, EXTERNAL) == 0) {
                token->type = TOKEN_EXTERNAL;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, FALSE) == 0) {
                token->type = TOKEN_FALSE;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, FROM) == 0) {
                token->type = TOKEN_FROM;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, GeneralizedTime) == 0) {
                token->type = TOKEN_GeneralizedTime;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, GeneralString) == 0) {
                token->type = TOKEN_GeneralString;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, GraphicString) == 0) {
                token->type = TOKEN_GraphicString;
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
