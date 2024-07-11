#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "tokenizer.h"

void 
test_is_digit() {
        assert(is_digit('0') == true);
        assert(is_digit('5') == true);
        assert(is_digit('9') == true);
        assert(is_digit('a') == false);
}

void
test_is_letter() {
        char A = 'A';
        char Z = 'Z';
        char a = 'a';
        char z = 'z';
        char ch6 = '6';

        assert(is_letter(A) == true);
        assert(is_letter(Z) == true);
        assert(is_letter(a) == true);
        assert(is_letter(z) == true);
        assert(is_letter(ch6) == false);
}

void 
test_is_upper_case() {
        char a = 'A';
        char z = 'Z';
        char ch6 = '6';

        assert(is_upper_case(a) == true);
        assert(is_upper_case(z) == true);
        assert(is_upper_case(ch6) == false);
}

void test_one_line_comment_token() {
        char *stream = "Name --\r----A comment";
        tokenizer_t *tokenizer = tokenizer_create(stream);

        token_t *token;

        token = next_token(tokenizer);
        assert(token->type == TOKEN_TYPE_REFERENCE);
        assert(strcmp((const char *)token->value, "Name") == 0);

        token = next_token(tokenizer);
        assert(token->type == TOKEN_ONE_LINE_COMMENT);
        assert(strcmp((const char *)token->value, "") == 0);

        token = next_token(tokenizer);
        assert(token->type == TOKEN_ONE_LINE_COMMENT);
        assert(strcmp((const char *)token->value, "") == 0);

        token = next_token(tokenizer);
        assert(token->type == TOKEN_ONE_LINE_COMMENT);
        assert(strcmp((const char *)token->value, "A comment") == 0);
}

void test_multi_line_comment_token() {
        char *stream = "/* A multi-line comment\r\n*/";
        char *stream2 = "/* A multi-line comment \r\n/* inner comment */*/";
        char *stream3 = "/* A multi-line comment \r\n/* inner comment */";
        tokenizer_t *tokenizer = tokenizer_create(stream);
        tokenizer_t *tokenizer2 = tokenizer_create(stream2);
        tokenizer_t *tokenizer3 = tokenizer_create(stream3);

        token_t *token;

        token = next_token(tokenizer);
        assert(token->type == TOKEN_MULTI_LINE_COMMENT);
        assert(strcmp((const char *)token->value, " A multi-line comment\r\n") == 0);

        token = next_token(tokenizer2);
        assert(token->type == TOKEN_MULTI_LINE_COMMENT);
        assert(strcmp((const char *)token->value, " A multi-line comment \r\n/* inner comment */") == 0);

        token = next_token(tokenizer3);
        assert(token->type == TOKEN_ERROR);
}

void 
test_identifer_token() {
        char *stream = "name name2 product-ID invalid- another \
                withComment--A comment--";

        tokenizer_t *tokenizer = tokenizer_create(stream);

        token_t *token;

        token = next_token(tokenizer);
        assert(token->type == TOKEN_IDENTIFIER);
        assert(strcmp((const char *)token->value, "name") == 0);

        token = next_token(tokenizer);
        assert(token->type == TOKEN_IDENTIFIER);
        assert(strcmp((const char *)token->value, "name2") == 0);

        token = next_token(tokenizer);
        assert(token->type == TOKEN_IDENTIFIER);
        assert(strcmp((const char *)token->value, "product-ID") == 0);

        token = next_token(tokenizer);
        assert(token->type == TOKEN_ERROR);

        token = next_token(tokenizer);
        assert(token->type == TOKEN_IDENTIFIER);
        assert(strcmp((const char *)token->value, "another") == 0);

        token = next_token(tokenizer);
        assert(token->type == TOKEN_IDENTIFIER);
        assert(strcmp((const char *)token->value, "withComment") == 0);

        token = next_token(tokenizer);
        assert(token->type == TOKEN_ONE_LINE_COMMENT);
        assert(strcmp((const char *)token->value, "A comment") == 0);

        token = next_token(tokenizer);
        assert(token->type == TOKEN_ONE_LINE_COMMENT);
        assert(strcmp((const char *)token->value, "") == 0);

        token = next_token(tokenizer);
        assert(token->type == TOKEN_END_OF_FILE);
}


void 
test_type_reference_token() {
        char *stream = "Name Name2 Product-ID Invalid- Another \
                WithComment--A comment--";

        tokenizer_t *tokenizer = tokenizer_create(stream);

        token_t *token;

        token = next_token(tokenizer);
        assert(token->type == TOKEN_TYPE_REFERENCE);
        assert(strcmp((const char *)token->value, "Name") == 0);

        token = next_token(tokenizer);
        assert(token->type == TOKEN_TYPE_REFERENCE);
        assert(strcmp((const char *)token->value, "Name2") == 0);

        token = next_token(tokenizer);
        assert(token->type == TOKEN_TYPE_REFERENCE);
        assert(strcmp((const char *)token->value, "Product-ID") == 0);

        token = next_token(tokenizer);
        assert(token->type == TOKEN_ERROR);

        token = next_token(tokenizer);
        assert(token->type == TOKEN_TYPE_REFERENCE);
        assert(strcmp((const char *)token->value, "Another") == 0);

        token = next_token(tokenizer);
        assert(token->type == TOKEN_TYPE_REFERENCE);
        assert(strcmp((const char *)token->value, "WithComment") == 0);

        token = next_token(tokenizer);
        assert(token->type == TOKEN_ONE_LINE_COMMENT);
        assert(strcmp((const char *)token->value, "A comment") == 0);

        token = next_token(tokenizer);
        assert(token->type == TOKEN_ONE_LINE_COMMENT);
        assert(strcmp((const char *)token->value, "") == 0);

        token = next_token(tokenizer);
        assert(token->type == TOKEN_END_OF_FILE);
}

void 
test_reserved_words_token() {
        char *stream = "ABSENT ABSTRACT-SYNTAX ALL APPLICATION \
                            AUTOMATIC BEGIN BIT BMPString BOOLEAN BY \
                            CHARACTER CHOICE CLASS COMPONENT COMPONENTS \
                            CONSTRAINED CONTAINING DATE DATE-TIME DEFAULT \
                            DEFINITIONS DURATION EMBEDDED ENCODED \
                            ENCODING-CONTROL END ENUMERATED EXCEPT \
                            EXPLICIT EXPORTS EXTENSIBILITY EXTERNAL \
                            FALSE FROM GeneralizedTime GeneralString \
                            GraphicString IA5String IDENTIFIER IMPLICIT \
                            IMPLIED IMPORTS INCLUDES INSTANCE \
                            INSTRUCTIONS INTEGER INTERSECTION \
                            ISO646String MAX MIN MINUS-INFINITY \
                            NOT-A-NUMBER NULL NumericString OBJECT \
                            ObjectDescriptor OCTET OF OID-IRI OPTIONAL \
                            PATTERN PDV PLUS-INFINITY PRESENT \
                            PrintableString PRIVATE REAL RELATIVE-OID \
                            RELATIVE-OID-IRI SEQUENCE SET SETTINGS SIZE \
                            STRING SYNTAX T61String TAGS TeletexString \
                            TIME TIME-OF-DAY TRUE TYPE-IDENTIFIER UNION \
                            UNIQUE UNIVERSAL UniversalString UTCTime \
                            UTF8String VideotexString VisibleString WITH";

        tokenizer_t *tokenizer = tokenizer_create(stream);

        token_t *token;

        /* Test reversed words */
        token = next_token(tokenizer);
        assert(token->type == TOKEN_KEYWORD_ABSENT);

        token = next_token(tokenizer);
        assert(token->type == TOKEN_KEYWORD_ABSTRACT_SYNTAX);

        token = next_token(tokenizer);
        assert(token->type == TOKEN_KEYWORD_ALL);

        token = next_token(tokenizer);
        assert(token->type == TOKEN_KEYWORD_APPLICATION);

        token = next_token(tokenizer);
        assert(token->type == TOKEN_KEYWORD_AUTOMATIC);

        token = next_token(tokenizer);
        assert(token->type == TOKEN_KEYWORD_BEGIN);

        token = next_token(tokenizer);
        assert(token->type == TOKEN_KEYWORD_BIT);

        token = next_token(tokenizer);
        assert(token->type == TOKEN_KEYWORD_BMPString);

        token = next_token(tokenizer);
        assert(token->type == TOKEN_KEYWORD_BOOLEAN);

        token = next_token(tokenizer);
        assert(token->type == TOKEN_KEYWORD_BY);

        token = next_token(tokenizer);
        assert(token->type == TOKEN_KEYWORD_CHARACTER);

        token = next_token(tokenizer);
        assert(token->type == TOKEN_KEYWORD_CHOICE);

        token = next_token(tokenizer);
        assert(token->type == TOKEN_KEYWORD_CLASS);

        token = next_token(tokenizer);
        assert(token->type == TOKEN_KEYWORD_COMPONENT);

        token = next_token(tokenizer);
        assert(token->type == TOKEN_KEYWORD_COMPONENTS);

        token = next_token(tokenizer);
        assert(token->type == TOKEN_KEYWORD_CONSTRAINED);

        token = next_token(tokenizer);
        assert(token->type == TOKEN_KEYWORD_CONTAINING);

        token = next_token(tokenizer);
        assert(token->type == TOKEN_KEYWORD_DATE);

        token = next_token(tokenizer);
        assert(token->type == TOKEN_KEYWORD_DATE_TIME);

        token = next_token(tokenizer);
        assert(token->type == TOKEN_KEYWORD_DEFAULT);

        token = next_token(tokenizer);
        assert(token->type == TOKEN_KEYWORD_DEFINITIONS);

        token = next_token(tokenizer);
        assert(token->type == TOKEN_KEYWORD_DURATION);

        token = next_token(tokenizer);
        assert(token->type == TOKEN_KEYWORD_EMBEDDED);

        token = next_token(tokenizer);
        assert(token->type == TOKEN_KEYWORD_ENCODED);

        token = next_token(tokenizer);
        assert(token->type == TOKEN_KEYWORD_ENCODING_CONTROL);

        token = next_token(tokenizer);
        assert(token->type == TOKEN_KEYWORD_END);

        token = next_token(tokenizer);
        assert(token->type == TOKEN_KEYWORD_ENUMERATED);

        token = next_token(tokenizer);
        assert(token->type == TOKEN_KEYWORD_EXCEPT);

        token = next_token(tokenizer);
        assert(token->type == TOKEN_KEYWORD_EXPLICIT);

        token = next_token(tokenizer);
        assert(token->type == TOKEN_KEYWORD_EXPORTS);

        token = next_token(tokenizer);
        assert(token->type == TOKEN_KEYWORD_EXTENSIBILITY);

        token = next_token(tokenizer);
        assert(token->type == TOKEN_KEYWORD_EXTERNAL);

        token = next_token(tokenizer);
        assert(token->type == TOKEN_KEYWORD_FALSE);

        token = next_token(tokenizer);
        assert(token->type == TOKEN_KEYWORD_FROM);

        token = next_token(tokenizer);
        assert(token->type == TOKEN_KEYWORD_GeneralizedTime);

        token = next_token(tokenizer);
        assert(token->type == TOKEN_KEYWORD_GeneralString);

        token = next_token(tokenizer);
        assert(token->type == TOKEN_KEYWORD_GraphicString);

        token = next_token(tokenizer);
        assert(token->type == TOKEN_KEYWORD_IA5String);

        token = next_token(tokenizer);
        assert(token->type == TOKEN_KEYWORD_IDENTIFIER);

        token = next_token(tokenizer);
        assert(token->type == TOKEN_KEYWORD_IMPLICIT);

        token = next_token(tokenizer);
        assert(token->type == TOKEN_KEYWORD_IMPLIED);

        token = next_token(tokenizer);
        assert(token->type == TOKEN_KEYWORD_IMPORTS);

        token = next_token(tokenizer);
        assert(token->type == TOKEN_KEYWORD_INCLUDES);

        token = next_token(tokenizer);
        assert(token->type == TOKEN_KEYWORD_INSTANCE);

        token = next_token(tokenizer);
        assert(token->type == TOKEN_KEYWORD_INSTRUCTIONS);

        token = next_token(tokenizer);
        assert(token->type == TOKEN_KEYWORD_INTEGER);

        token = next_token(tokenizer);
        assert(token->type == TOKEN_KEYWORD_INTERSECTION);

        token = next_token(tokenizer);
        assert(token->type == TOKEN_KEYWORD_ISO646String);

        token = next_token(tokenizer);
        assert(token->type == TOKEN_KEYWORD_MAX);

        token = next_token(tokenizer);
        assert(token->type == TOKEN_KEYWORD_MIN);

        token = next_token(tokenizer);
        assert(token->type == TOKEN_KEYWORD_MINUS_INFINITY);

        token = next_token(tokenizer);
        assert(token->type == TOKEN_KEYWORD_NOT_A_NUMBER);

        token = next_token(tokenizer);
        assert(token->type == TOKEN_KEYWORD_NULL);

        token = next_token(tokenizer);
        assert(token->type == TOKEN_KEYWORD_NumericString);

        token = next_token(tokenizer);
        assert(token->type == TOKEN_KEYWORD_OBJECT);

        token = next_token(tokenizer);
        assert(token->type == TOKEN_KEYWORD_ObjectDescriptor);

        token = next_token(tokenizer);
        assert(token->type == TOKEN_KEYWORD_OCTET);

        token = next_token(tokenizer);
        assert(token->type == TOKEN_KEYWORD_OF);

        token = next_token(tokenizer);
        assert(token->type == TOKEN_KEYWORD_OID_IRI);

        token = next_token(tokenizer);
        assert(token->type == TOKEN_KEYWORD_OPTIONAL);

        token = next_token(tokenizer);
        assert(token->type == TOKEN_KEYWORD_PATTERN);

        token = next_token(tokenizer);
        assert(token->type == TOKEN_KEYWORD_PDV);

        token = next_token(tokenizer);
        assert(token->type == TOKEN_KEYWORD_PLUS_INFINITY);

        token = next_token(tokenizer);
        assert(token->type == TOKEN_KEYWORD_PRESENT);

        token = next_token(tokenizer);
        assert(token->type == TOKEN_KEYWORD_PrintableString);

        token = next_token(tokenizer);
        assert(token->type == TOKEN_KEYWORD_PRIVATE);

        token = next_token(tokenizer);
        assert(token->type == TOKEN_KEYWORD_REAL);

        token = next_token(tokenizer);
        assert(token->type == TOKEN_KEYWORD_RELATIVE_OID);

        token = next_token(tokenizer);
        assert(token->type == TOKEN_KEYWORD_RELATIVE_OID_IRI);

        token = next_token(tokenizer);
        assert(token->type == TOKEN_KEYWORD_SEQUENCE);

        token = next_token(tokenizer);
        assert(token->type == TOKEN_KEYWORD_SET);

        token = next_token(tokenizer);
        assert(token->type == TOKEN_KEYWORD_SETTINGS);

        token = next_token(tokenizer);
        assert(token->type == TOKEN_KEYWORD_SIZE);

        token = next_token(tokenizer);
        assert(token->type == TOKEN_KEYWORD_STRING);

        token = next_token(tokenizer);
        assert(token->type == TOKEN_KEYWORD_SYNTAX);

        token = next_token(tokenizer);
        assert(token->type == TOKEN_KEYWORD_T61String);

        token = next_token(tokenizer);
        assert(token->type == TOKEN_KEYWORD_TAGS);

        token = next_token(tokenizer);
        assert(token->type == TOKEN_KEYWORD_TeletexString);

        token = next_token(tokenizer);
        assert(token->type == TOKEN_KEYWORD_TIME);

        token = next_token(tokenizer);
        assert(token->type == TOKEN_KEYWORD_TIME_OF_DAY);

        token = next_token(tokenizer);
        assert(token->type == TOKEN_KEYWORD_TRUE);

        token = next_token(tokenizer);
        assert(token->type == TOKEN_KEYWORD_TYPE_IDENTIFIER);

        token = next_token(tokenizer);
        assert(token->type == TOKEN_KEYWORD_UNION);

        token = next_token(tokenizer);
        assert(token->type == TOKEN_KEYWORD_UNIQUE);

        token = next_token(tokenizer);
        assert(token->type == TOKEN_KEYWORD_UNIVERSAL);

        token = next_token(tokenizer);
        assert(token->type == TOKEN_KEYWORD_UniversalString);

        token = next_token(tokenizer);
        assert(token->type == TOKEN_KEYWORD_UTCTime);

        token = next_token(tokenizer);
        assert(token->type == TOKEN_KEYWORD_UTF8String);

        token = next_token(tokenizer);
        assert(token->type == TOKEN_KEYWORD_VideotexString);

        token = next_token(tokenizer);
        assert(token->type == TOKEN_KEYWORD_VisibleString);

        token = next_token(tokenizer);
        assert(token->type == TOKEN_KEYWORD_WITH);

        token = next_token(tokenizer);
        assert(token->type == TOKEN_END_OF_FILE);

        token = next_token(tokenizer);
        assert(token->type == TOKEN_END_OF_FILE);
}

void 
test_is_white_space() {
        assert(is_white_space(' ') == true);
        assert(is_white_space('\t') == true);
        assert(is_white_space('\r') == true);
        assert(is_white_space('\n') == true);
        assert(is_white_space('a') != true);
}

void 
test_next_char() {
        tokenizer_t *tokenizer = tokenizer_create("CHOICE \r\r\n\r\n\rINTEGER");

        assert(next_char(tokenizer) == 'C');
        assert(next_char(tokenizer) == 'H');
        assert(next_char(tokenizer) == 'O');
        assert(next_char(tokenizer) == 'I');
        assert(next_char(tokenizer) == 'C');
        assert(next_char(tokenizer) == 'E');

        assert(next_char(tokenizer) == ' ');
        assert(tokenizer->line_num == 1);
        assert(tokenizer->column == 7);

        assert(next_char(tokenizer) == '\r');
        assert(tokenizer->line_num == 2);

        assert(next_char(tokenizer) == '\r');
        assert(tokenizer->line_num == 2);
        assert(next_char(tokenizer) == '\n');
        assert(tokenizer->line_num == 3);
        assert(tokenizer->column == 0);

        assert(next_char(tokenizer) == '\r');
        assert(tokenizer->line_num == 3);
        assert(next_char(tokenizer) == '\n');
        assert(tokenizer->line_num == 4);
        assert(tokenizer->column == 0);

        assert(next_char(tokenizer) == '\r');
        assert(tokenizer->line_num == 5);

        assert(next_char(tokenizer) == 'I');
        assert(next_char(tokenizer) == 'N');
        assert(next_char(tokenizer) == 'T');
        assert(next_char(tokenizer) == 'E');
        assert(next_char(tokenizer) == 'G');
        assert(next_char(tokenizer) == 'E');
        assert(next_char(tokenizer) == 'R');

        assert(next_char(tokenizer) == '\0');
        assert(next_char(tokenizer) == '\0');
        assert(next_char(tokenizer) == '\0');
}

void
test_peer_char() {
        tokenizer_t *tokenizer = tokenizer_create("CHOICE INTEGER");

        assert(next_char(tokenizer) == 'C');

        /* peer char */
        assert(peek_char(tokenizer) == 'H');
                
        assert(next_char(tokenizer) == 'H');
        assert(next_char(tokenizer) == 'O');
        assert(next_char(tokenizer) == 'I');
        assert(next_char(tokenizer) == 'C');
        assert(next_char(tokenizer) == 'E');

        assert(next_char(tokenizer) == ' ');

        assert(next_char(tokenizer) == 'I');
        assert(next_char(tokenizer) == 'N');
        assert(next_char(tokenizer) == 'T');
        assert(next_char(tokenizer) == 'E');
        assert(next_char(tokenizer) == 'G');
        assert(next_char(tokenizer) == 'E');

        /* peer char */
        assert(peek_char(tokenizer) == 'R');

        assert(next_char(tokenizer) == 'R');

        /* peer char */

        assert(peek_char(tokenizer) == '\0');
        assert(peek_char(tokenizer) == '\0');

        assert(next_char(tokenizer) == '\0');
        assert(next_char(tokenizer) == '\0');
        assert(next_char(tokenizer) == '\0');
}

int
main() {
        test_is_white_space();
        test_next_char();
        test_peer_char();
        test_is_upper_case();
        test_is_letter();
        test_is_digit();
        test_reserved_words_token();
        test_type_reference_token();
        test_identifer_token();
        test_one_line_comment_token();
        test_multi_line_comment_token();
}
