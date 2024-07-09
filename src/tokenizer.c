#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "tokenizer.h"


bool 
is_letter(char ch) {
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
                return true;
        }

        return false;
}

bool 
is_upper_case(char ch) {
        if (ch >= 'A' && ch <= 'Z') {
                return true;
        }
        return false;
}

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
        } else if (strcmp((const char*)buffer, IA5String) == 0) {
                token->type = TOKEN_IA5String;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, IDENTIFIER) == 0) {
                token->type = TOKEN_IDENTIFIER;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, IMPLICIT) == 0) {
                token->type = TOKEN_IMPLICIT;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, IMPLIED) == 0) {
                token->type = TOKEN_IMPLIED;
        } else if (strcmp((const char*)buffer, IMPORTS) == 0) {
                token->type = TOKEN_IMPORTS;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, INCLUDES) == 0) {
                token->type = TOKEN_INCLUDES;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, INSTANCE) == 0) {
                token->type = TOKEN_INSTANCE;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, INSTRUCTIONS) == 0) {
                token->type = TOKEN_INSTRUCTIONS;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, INTEGER) == 0) {
                token->type = TOKEN_INTEGER;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, INTERSECTION) == 0) {
                token->type = TOKEN_INTERSECTION;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, ISO646String) == 0) {
                token->type = TOKEN_ISO646String;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, MAX) == 0) {
                token->type = TOKEN_MAX;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, MIN) == 0) {
                token->type = TOKEN_MIN;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, MINUS_INFINITY) == 0) {
                token->type = TOKEN_MINUS_INFINITY;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, NOT_A_NUMBER) == 0) {
                token->type = TOKEN_NOT_A_NUMBER;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, _NULL) == 0) {
                token->type = TOKEN_NULL;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, NumericString) == 0) {
                token->type = TOKEN_NumericString;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, OBJECT) == 0) {
                token->type = TOKEN_OBJECT;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, ObjectDescriptor) == 0) {
                token->type = TOKEN_ObjectDescriptor;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, OCTET) == 0) {
                token->type = TOKEN_OCTET;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, OF) == 0) {
                token->type = TOKEN_OF;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, OID_IRI) == 0) {
                token->type = TOKEN_OID_IRI;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, OPTIONAL) == 0) {
                token->type = TOKEN_OPTIONAL;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, PATTERN) == 0) {
                token->type = TOKEN_PATTERN;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, PDV) == 0) {
                token->type = TOKEN_PDV;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, PLUS_INFINITY) == 0) {
                token->type = TOKEN_PLUS_INFINITY;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, PRESENT) == 0) {
                token->type = TOKEN_PRESENT;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, PrintableString) == 0) {
                token->type = TOKEN_PrintableString;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, PRIVATE) == 0) {
                token->type = TOKEN_PRIVATE;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, REAL) == 0) {
                token->type = TOKEN_REAL;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, RELATIVE_OID) == 0) {
                token->type = TOKEN_RELATIVE_OID;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, RELATIVE_OID_IRI) == 0) {
                token->type = TOKEN_RELATIVE_OID_IRI;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, SEQUENCE) == 0) {
                token->type = TOKEN_SEQUENCE;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, SET) == 0) {
                token->type = TOKEN_SET;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, SETTINGS) == 0) {
                token->type = TOKEN_SETTINGS;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, SIZE) == 0) {
                token->type = TOKEN_SIZE;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, STRING) == 0) {
                token->type = TOKEN_STRING;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, SYNTAX) == 0) {
                token->type = TOKEN_SYNTAX;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, T61String) == 0) {
                token->type = TOKEN_T61String;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, TAGS) == 0) {
                token->type = TOKEN_TAGS;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, TeletexString) == 0) {
                token->type = TOKEN_TeletexString;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, TIME) == 0) {
                token->type = TOKEN_TIME;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, TIME_OF_DAY) == 0) {
                token->type = TOKEN_TIME_OF_DAY;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, TRUE) == 0) {
                token->type = TOKEN_TRUE;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, TYPE_IDENTIFIER) == 0) {
                token->type = TOKEN_TYPE_IDENTIFIER;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, UNION) == 0) {
                token->type = TOKEN_UNION;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, UNIQUE) == 0) {
                token->type = TOKEN_UNIQUE;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, UNIVERSAL) == 0) {
                token->type = TOKEN_UNIVERSAL;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, UniversalString) == 0) {
                token->type = TOKEN_UniversalString;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, UTCTime) == 0) {
                token->type = TOKEN_UTCTime;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, UTF8String) == 0) {
                token->type = TOKEN_UTF8String;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, VideotexString) == 0) {
                token->type = TOKEN_VideotexString;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, VisibleString) == 0) {
                token->type = TOKEN_VisibleString;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, WITH) == 0) {
                token->type = TOKEN_WITH;
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
