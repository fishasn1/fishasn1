#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "tokenizer.h"

tokenizer_t* 
tokenizer_create(char *stream) {
        tokenizer_t *tokenizer = malloc(sizeof(tokenizer_t));
        tokenizer->stream = stream;
        tokenizer->pos = 0;
        tokenizer->line_num = 1;
        tokenizer->column = 0;
        return tokenizer;
}


void 
token_free(token_t *token) {
        if (token != NULL) {
                if (token->value != NULL) {
                        free(token->value);
                }
                free(token);
        }
}

bool 
is_eol(char ch) {
        if (ch == '\r' || ch == '\n') {
                return true;
        }
        return false;
}

bool 
is_digit(char ch) {
        if (ch >= '0' && ch <= '9') {
                return true;
        }
        return false;
}

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
is_lower_case(char ch) {
        if (ch >= 'a' && ch <= 'z') {
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
                if ((ch == '\r' && peek_char(tokenizer) != '\n') 
                                || ch == '\n') {
                        tokenizer->line_num++;
                        tokenizer->column = 0;
                } else {
                        tokenizer->column++;
                }
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
        token->type = TOKEN_UNKNOWN;
        token->value = NULL;

        /* skip white spaces */
        current = next_char(tokenizer);
        while(is_white_space(current)) {
                current = next_char(tokenizer);
        }

        if (is_eof(current)) {
                token->type = TOKEN_END_OF_FILE;
                return token;
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
                token->type = TOKEN_KEYWORD_ABSENT;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, ABSTRACT_SYNTAX) == 0) {
                token->type = TOKEN_KEYWORD_ABSTRACT_SYNTAX;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, ALL) == 0) {
                token->type = TOKEN_KEYWORD_ALL;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, APPLICATION) == 0) {
                token->type = TOKEN_KEYWORD_APPLICATION;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, AUTOMATIC) == 0) {
                token->type = TOKEN_KEYWORD_AUTOMATIC;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, BEGIN) == 0) {
                token->type = TOKEN_KEYWORD_BEGIN;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, BIT) == 0) {
                token->type = TOKEN_KEYWORD_BIT;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, BMPString) == 0) {
                token->type = TOKEN_KEYWORD_BMPString;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, BOOLEAN) == 0) {
                token->type = TOKEN_KEYWORD_BOOLEAN;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, BY) == 0) {
                token->type = TOKEN_KEYWORD_BY;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, CHARACTER) == 0) {
                token->type = TOKEN_KEYWORD_CHARACTER;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, CHOICE) == 0) {
                token->type = TOKEN_KEYWORD_CHOICE;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, CLASS) == 0) {
                token->type = TOKEN_KEYWORD_CLASS;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, COMPONENT) == 0) {
                token->type = TOKEN_KEYWORD_COMPONENT;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, COMPONENTS) == 0) {
                token->type = TOKEN_KEYWORD_COMPONENTS;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, CONSTRAINED) == 0) {
                token->type = TOKEN_KEYWORD_CONSTRAINED;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, CONTAINING) == 0) {
                token->type = TOKEN_KEYWORD_CONTAINING;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, DATE) == 0) {
                token->type = TOKEN_KEYWORD_DATE;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, DATE_TIME) == 0) {
                token->type = TOKEN_KEYWORD_DATE_TIME;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, DEFAULT) == 0) {
                token->type = TOKEN_KEYWORD_DEFAULT;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, DEFINITIONS) == 0) {
                token->type = TOKEN_KEYWORD_DEFINITIONS;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, DURATION) == 0) {
                token->type = TOKEN_KEYWORD_DURATION;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, EMBEDDED) == 0) {
                token->type = TOKEN_KEYWORD_EMBEDDED;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, ENCODED) == 0) {
                token->type = TOKEN_KEYWORD_ENCODED;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, ENCODING_CONTROL) == 0) {
                token->type = TOKEN_KEYWORD_ENCODING_CONTROL;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, END) == 0) {
                token->type = TOKEN_KEYWORD_END;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, ENUMERATED) == 0) {
                token->type = TOKEN_KEYWORD_ENUMERATED;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, EXCEPT) == 0) {
                token->type = TOKEN_KEYWORD_EXCEPT;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, EXPLICIT) == 0) {
                token->type = TOKEN_KEYWORD_EXPLICIT;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, EXPORTS) == 0) {
                token->type = TOKEN_KEYWORD_EXPORTS;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, EXTENSIBILITY) == 0) {
                token->type = TOKEN_KEYWORD_EXTENSIBILITY;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, EXTERNAL) == 0) {
                token->type = TOKEN_KEYWORD_EXTERNAL;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, FALSE) == 0) {
                token->type = TOKEN_KEYWORD_FALSE;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, FROM) == 0) {
                token->type = TOKEN_KEYWORD_FROM;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, GeneralizedTime) == 0) {
                token->type = TOKEN_KEYWORD_GeneralizedTime;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, GeneralString) == 0) {
                token->type = TOKEN_KEYWORD_GeneralString;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, GraphicString) == 0) {
                token->type = TOKEN_KEYWORD_GraphicString;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, IA5String) == 0) {
                token->type = TOKEN_KEYWORD_IA5String;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, IDENTIFIER) == 0) {
                token->type = TOKEN_KEYWORD_IDENTIFIER;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, IMPLICIT) == 0) {
                token->type = TOKEN_KEYWORD_IMPLICIT;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, IMPLIED) == 0) {
                token->type = TOKEN_KEYWORD_IMPLIED;
        } else if (strcmp((const char*)buffer, IMPORTS) == 0) {
                token->type = TOKEN_KEYWORD_IMPORTS;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, INCLUDES) == 0) {
                token->type = TOKEN_KEYWORD_INCLUDES;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, INSTANCE) == 0) {
                token->type = TOKEN_KEYWORD_INSTANCE;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, INSTRUCTIONS) == 0) {
                token->type = TOKEN_KEYWORD_INSTRUCTIONS;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, INTEGER) == 0) {
                token->type = TOKEN_KEYWORD_INTEGER;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, INTERSECTION) == 0) {
                token->type = TOKEN_KEYWORD_INTERSECTION;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, ISO646String) == 0) {
                token->type = TOKEN_KEYWORD_ISO646String;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, MAX) == 0) {
                token->type = TOKEN_KEYWORD_MAX;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, MIN) == 0) {
                token->type = TOKEN_KEYWORD_MIN;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, MINUS_INFINITY) == 0) {
                token->type = TOKEN_KEYWORD_MINUS_INFINITY;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, NOT_A_NUMBER) == 0) {
                token->type = TOKEN_KEYWORD_NOT_A_NUMBER;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, _NULL) == 0) {
                token->type = TOKEN_KEYWORD_NULL;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, NumericString) == 0) {
                token->type = TOKEN_KEYWORD_NumericString;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, OBJECT) == 0) {
                token->type = TOKEN_KEYWORD_OBJECT;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, ObjectDescriptor) == 0) {
                token->type = TOKEN_KEYWORD_ObjectDescriptor;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, OCTET) == 0) {
                token->type = TOKEN_KEYWORD_OCTET;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, OF) == 0) {
                token->type = TOKEN_KEYWORD_OF;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, OID_IRI) == 0) {
                token->type = TOKEN_KEYWORD_OID_IRI;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, OPTIONAL) == 0) {
                token->type = TOKEN_KEYWORD_OPTIONAL;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, PATTERN) == 0) {
                token->type = TOKEN_KEYWORD_PATTERN;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, PDV) == 0) {
                token->type = TOKEN_KEYWORD_PDV;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, PLUS_INFINITY) == 0) {
                token->type = TOKEN_KEYWORD_PLUS_INFINITY;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, PRESENT) == 0) {
                token->type = TOKEN_KEYWORD_PRESENT;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, PrintableString) == 0) {
                token->type = TOKEN_KEYWORD_PrintableString;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, PRIVATE) == 0) {
                token->type = TOKEN_KEYWORD_PRIVATE;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, REAL) == 0) {
                token->type = TOKEN_KEYWORD_REAL;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, RELATIVE_OID) == 0) {
                token->type = TOKEN_KEYWORD_RELATIVE_OID;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, RELATIVE_OID_IRI) == 0) {
                token->type = TOKEN_KEYWORD_RELATIVE_OID_IRI;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, SEQUENCE) == 0) {
                token->type = TOKEN_KEYWORD_SEQUENCE;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, SET) == 0) {
                token->type = TOKEN_KEYWORD_SET;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, SETTINGS) == 0) {
                token->type = TOKEN_KEYWORD_SETTINGS;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, SIZE) == 0) {
                token->type = TOKEN_KEYWORD_SIZE;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, STRING) == 0) {
                token->type = TOKEN_KEYWORD_STRING;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, SYNTAX) == 0) {
                token->type = TOKEN_KEYWORD_SYNTAX;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, T61String) == 0) {
                token->type = TOKEN_KEYWORD_T61String;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, TAGS) == 0) {
                token->type = TOKEN_KEYWORD_TAGS;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, TeletexString) == 0) {
                token->type = TOKEN_KEYWORD_TeletexString;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, TIME) == 0) {
                token->type = TOKEN_KEYWORD_TIME;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, TIME_OF_DAY) == 0) {
                token->type = TOKEN_KEYWORD_TIME_OF_DAY;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, TRUE) == 0) {
                token->type = TOKEN_KEYWORD_TRUE;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, TYPE_IDENTIFIER) == 0) {
                token->type = TOKEN_KEYWORD_TYPE_IDENTIFIER;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, UNION) == 0) {
                token->type = TOKEN_KEYWORD_UNION;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, UNIQUE) == 0) {
                token->type = TOKEN_KEYWORD_UNIQUE;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, UNIVERSAL) == 0) {
                token->type = TOKEN_KEYWORD_UNIVERSAL;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, UniversalString) == 0) {
                token->type = TOKEN_KEYWORD_UniversalString;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, UTCTime) == 0) {
                token->type = TOKEN_KEYWORD_UTCTime;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, UTF8String) == 0) {
                token->type = TOKEN_KEYWORD_UTF8String;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, VideotexString) == 0) {
                token->type = TOKEN_KEYWORD_VideotexString;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, VisibleString) == 0) {
                token->type = TOKEN_KEYWORD_VisibleString;
                token->value = buffer;
        } else if (strcmp((const char*)buffer, WITH) == 0) {
                token->type = TOKEN_KEYWORD_WITH;
                token->value = buffer;
        } else {
                token->type = TOKEN_UNKNOWN;
                token->value = buffer;
                tokenizer->pos = start_pos;
        }
        return token;
}

token_t*
match_identifier(tokenizer_t *tokenizer) {
        unsigned char current;
        unsigned int index = 0;
        unsigned int start_pos = tokenizer->pos;
        /*
         * TODO: Dynamically resize buffer if it's so small to hold 
         *       chars
         */
        unsigned char *buffer = malloc(1024);
        token_t *token = malloc(sizeof(token_t));
        token->type = TOKEN_UNKNOWN;
        token->value = NULL;

        /* skip white spaces */
        current = next_char(tokenizer);
        while(is_white_space(current)) {
                current = next_char(tokenizer);
        }

        if (is_eof(current)) {
                token->type = TOKEN_END_OF_FILE;
                return token;
        }

        if (is_lower_case(current)) {
                buffer[index] = current;
                index++;
                current = next_char(tokenizer);
                while (is_digit(current) || is_letter(current)
                        || current == '-') {
                        if (current == '-' && 
                                        peek_char(tokenizer) == '-') {
                                token->type = TOKEN_IDENTIFIER;
                                buffer[index] = '\0';
                                tokenizer->pos -= 1;
                                token->value = buffer;
                                return token;
                        }

                        if (current == '-' &&
                            (is_white_space(peek_char(tokenizer)) ||
                            is_eof(peek_char(tokenizer)))) {
                                token->type = TOKEN_ERROR;
                                buffer[index] = current;
                                buffer[index+1] = '\0';
                                token->value = buffer;
                                return token;

                        }

                        buffer[index] = current;
                        index++;
                        current = next_char(tokenizer);
                }

                token->type = TOKEN_IDENTIFIER;
                buffer[index] = '\0';
                token->value = buffer;
        } else {
                tokenizer->pos = start_pos;
        }

        return token;
}

token_t*
match_type_reference(tokenizer_t *tokenizer) {
        unsigned char current;
        unsigned int index = 0;
        /*
         * TODO: Dynamically resize buffer if it's so small to hold 
         *       chars
         */
        unsigned char *buffer = malloc(1024);
        token_t *token = malloc(sizeof(token_t));
        token->type = TOKEN_UNKNOWN;
        token->value = NULL;

        /* skip white spaces */
        current = next_char(tokenizer);
        while(is_white_space(current)) {
                current = next_char(tokenizer);
        }

        if (is_eof(current)) {
                token->type = TOKEN_END_OF_FILE;
                return token;
        }

        if (is_upper_case(current)) {
                buffer[index] = current;
                index++;
                current = next_char(tokenizer);
                while (is_digit(current) || is_letter(current)
                        || current == '-') {
                        if (current == '-' && 
                                        peek_char(tokenizer) == '-') {
                                token->type = TOKEN_TYPE_REFERENCE;
                                buffer[index] = '\0';
                                tokenizer->pos -= 1;
                                token->value = buffer;
                                return token;
                        }

                        if (current == '-' &&
                            (is_white_space(peek_char(tokenizer)) ||
                            is_eof(peek_char(tokenizer)))) {
                                token->type = TOKEN_ERROR;
                                buffer[index] = current;
                                buffer[index + 1] = '\0';
                                token->value = buffer;
                                return token;

                        }

                        buffer[index] = current;
                        index++;
                        current = next_char(tokenizer);

                }

                token->type = TOKEN_TYPE_REFERENCE;
                buffer[index] = '\0';
                token->value = buffer;
        }

        return token;
}

token_t*
match_one_line_comment(tokenizer_t *tokenizer) {
        unsigned char current;
        unsigned int index = 0;
        unsigned int start_pos = tokenizer->pos;
        /*
         * TODO: Dynamically resize buffer if it's so small to hold 
         *       chars
         */
        unsigned char *buffer = malloc(1024);
        token_t *token = malloc(sizeof(token_t));
        token->type = TOKEN_UNKNOWN;
        token->value = NULL;

        /* skip white spaces */
        current = next_char(tokenizer);
        while(is_white_space(current)) {
                current = next_char(tokenizer);
        }

        if (is_eof(current)) {
                token->type = TOKEN_END_OF_FILE;
                token->value = NULL;
                return token;
        }

        if (current == '-' && peek_char(tokenizer) == '-') {
                current = next_char(tokenizer);
                current = next_char(tokenizer);
                while (!is_eol(current) && current != '-'
                                && !is_eof(current)) {
                        buffer[index] = current;
                        index++;
                        current = next_char(tokenizer);
                }

                if (current == '-') {
                        tokenizer->pos -= 1;
                }
                token->type = TOKEN_ONE_LINE_COMMENT;
                buffer[index] = '\0';
                token->value = buffer;
        } else {
                tokenizer->pos = start_pos;
        }
        return token;
}

token_t*
match_multi_line_comment(tokenizer_t *tokenizer) {
        unsigned char current;
        unsigned int index = 0;
        unsigned int start_pos = tokenizer->pos;
        unsigned int unmatch = 1;
        /*
         * TODO: Dynamically resize buffer if it's so small to hold 
         *       chars
         */
        unsigned char *buffer = malloc(1024);
        token_t *token = malloc(sizeof(token_t));
        token->type = TOKEN_UNKNOWN;
        token->value = NULL;

        /* skip white spaces */
        current = next_char(tokenizer);
        while(is_white_space(current)) {
                current = next_char(tokenizer);
        }

        if (is_eof(current)) {
                token->type = TOKEN_END_OF_FILE;
                token->value = NULL;
                return token;
        }

        if (current == '/' && peek_char(tokenizer) == '*') {
                current = next_char(tokenizer);
                current = next_char(tokenizer);
                bool match_done = false;
                while (!match_done) {
                        buffer[index] = current;
                        index++;
                        if (is_eof(current)) {
                                /* TODO: Raise error for not matching
                                 *       before end of file.
                                 */
                                token->type = TOKEN_ERROR;
                                token->value = NULL;
                                return token;
                        }

                        if (current == '/' && peek_char(tokenizer) == '*') {
                                unmatch++;
                        }

                        if (current == '*' && peek_char(tokenizer) == '/' 
                                        && unmatch == 1) {
                                buffer[index - 1] = '\0';
                                match_done = true;
                                break;
                        }

                        if (current == '*' && peek_char(tokenizer) == '/' && unmatch > 1) {
                                current = next_char(tokenizer);
                                buffer[index] = current;
                                index++;
                                unmatch--;
                        }

                        current = next_char(tokenizer);
                }
                token->type = TOKEN_MULTI_LINE_COMMENT;
                buffer[index] = '\0';
                token->value = buffer;
        } else {
                tokenizer->pos = start_pos;
        }
        return token;
}

token_t*
next_token(tokenizer_t *tokenizer) {
        token_t *token;
        token = match_one_line_comment(tokenizer);
        if (token->type == TOKEN_UNKNOWN) {
                token_free(token);
                token = match_multi_line_comment(tokenizer);
        }
        

        if (token->type == TOKEN_UNKNOWN) {
                token_free(token);
                token = match_identifier(tokenizer);
        }

        if (token->type == TOKEN_UNKNOWN) {
                token_free(token);
                token = match_reserved_words(tokenizer);
        }
        
        if (token->type == TOKEN_UNKNOWN) {
                token_free(token);
                token = match_type_reference(tokenizer);
        }
        return token;
}
