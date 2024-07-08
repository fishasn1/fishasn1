#include <assert.h>
#include <stdio.h>
#include <stdbool.h>
#include "tokenizer.h"

void test_next_token() {
        tokenizer_t tokenizer;
        tokenizer.stream = "ABSENT ABSTRACT-SYNTAX ALL APPLICATION AUTOMATIC BEGIN BIT BMPString BOOLEAN BY CHARACTER CHOICE CLASS COMPONENT COMPONENTS CONSTRAINED CONTAINING DATE DATE-TIME DEFAULT DEFINITIONS DURATION EMBEDDED ENCODED ENCODING-CONTROL END ENUMERATED EXCEPT EXPLICIT EXPORTS EXTENSIBILITY EXTERNAL FALSE FROM GeneralizedTime GeneralString GraphicString IA5String IDENTIFIER IMPLICIT IMPLIED IMPORTS INCLUDES INSTANCE INSTRUCTIONS INTEGER INTERSECTION ISO646String MAX MIN MINUS-INFINITY NOT-A-NUMBER NULL NumericString OBJECT ObjectDescriptor OCTET OF OID-IRI OPTIONAL PATTERN PDV PLUS-INFINITY PRESENT PrintableString PRIVATE REAL RELATIVE-OID RELATIVE-OID-IRI SEQUENCE SET SETTINGS SIZE STRING SYNTAX";

        tokenizer.pos = 0;

        token_t *token;

        /* Test reversed words */
        token = next_token(&tokenizer);
        assert(token->type == TOKEN_ABSENT);

        token = next_token(&tokenizer);
        assert(token->type == TOKEN_ABSTRACT_SYNTAX);

        token = next_token(&tokenizer);
        assert(token->type == TOKEN_ALL);

        token = next_token(&tokenizer);
        assert(token->type == TOKEN_APPLICATION);

        token = next_token(&tokenizer);
        assert(token->type == TOKEN_AUTOMATIC);

        token = next_token(&tokenizer);
        assert(token->type == TOKEN_BEGIN);

        token = next_token(&tokenizer);
        assert(token->type == TOKEN_BIT);

        token = next_token(&tokenizer);
        assert(token->type == TOKEN_BMPString);

        token = next_token(&tokenizer);
        assert(token->type == TOKEN_BOOLEAN);

        token = next_token(&tokenizer);
        assert(token->type == TOKEN_BY);

        token = next_token(&tokenizer);
        assert(token->type == TOKEN_CHARACTER);

        token = next_token(&tokenizer);
        assert(token->type == TOKEN_CHOICE);

        token = next_token(&tokenizer);
        assert(token->type == TOKEN_CLASS);

        token = next_token(&tokenizer);
        assert(token->type == TOKEN_COMPONENT);

        token = next_token(&tokenizer);
        assert(token->type == TOKEN_COMPONENTS);

        token = next_token(&tokenizer);
        assert(token->type == TOKEN_CONSTRAINED);

        token = next_token(&tokenizer);
        assert(token->type == TOKEN_CONTAINING);

        token = next_token(&tokenizer);
        assert(token->type == TOKEN_DATE);

        token = next_token(&tokenizer);
        assert(token->type == TOKEN_DATE_TIME);

        token = next_token(&tokenizer);
        assert(token->type == TOKEN_DEFAULT);

        token = next_token(&tokenizer);
        assert(token->type == TOKEN_DEFINITIONS);

        token = next_token(&tokenizer);
        assert(token->type == TOKEN_DURATION);

        token = next_token(&tokenizer);
        assert(token->type == TOKEN_EMBEDDED);

        token = next_token(&tokenizer);
        assert(token->type == TOKEN_ENCODED);

        token = next_token(&tokenizer);
        assert(token->type == TOKEN_ENCODING_CONTROL);

        token = next_token(&tokenizer);
        assert(token->type == TOKEN_END);

        token = next_token(&tokenizer);
        assert(token->type == TOKEN_ENUMERATED);

        token = next_token(&tokenizer);
        assert(token->type == TOKEN_EXCEPT);

        token = next_token(&tokenizer);
        assert(token->type == TOKEN_EXPLICIT);

        token = next_token(&tokenizer);
        assert(token->type == TOKEN_EXPORTS);

        token = next_token(&tokenizer);
        assert(token->type == TOKEN_EXTENSIBILITY);

        token = next_token(&tokenizer);
        assert(token->type == TOKEN_EXTERNAL);

        token = next_token(&tokenizer);
        assert(token->type == TOKEN_FALSE);

        token = next_token(&tokenizer);
        assert(token->type == TOKEN_FROM);

        token = next_token(&tokenizer);
        assert(token->type == TOKEN_GeneralizedTime);

        token = next_token(&tokenizer);
        assert(token->type == TOKEN_GeneralString);

        token = next_token(&tokenizer);
        assert(token->type == TOKEN_GraphicString);

        token = next_token(&tokenizer);
        assert(token->type == TOKEN_IA5String);

        token = next_token(&tokenizer);
        assert(token->type == TOKEN_IDENTIFIER);

        token = next_token(&tokenizer);
        assert(token->type == TOKEN_IMPLICIT);

        token = next_token(&tokenizer);
        assert(token->type == TOKEN_IMPLIED);

        token = next_token(&tokenizer);
        assert(token->type == TOKEN_IMPORTS);

        token = next_token(&tokenizer);
        assert(token->type == TOKEN_INCLUDES);

        token = next_token(&tokenizer);
        assert(token->type == TOKEN_INSTANCE);

        token = next_token(&tokenizer);
        assert(token->type == TOKEN_INSTRUCTIONS);

        token = next_token(&tokenizer);
        assert(token->type == TOKEN_INTEGER);

        token = next_token(&tokenizer);
        assert(token->type == TOKEN_INTERSECTION);

        token = next_token(&tokenizer);
        assert(token->type == TOKEN_ISO646String);

        token = next_token(&tokenizer);
        assert(token->type == TOKEN_MAX);

        token = next_token(&tokenizer);
        assert(token->type == TOKEN_MIN);

        token = next_token(&tokenizer);
        assert(token->type == TOKEN_MINUS_INFINITY);

        token = next_token(&tokenizer);
        assert(token->type == TOKEN_NOT_A_NUMBER);

        token = next_token(&tokenizer);
        assert(token->type == TOKEN_NULL);

        token = next_token(&tokenizer);
        assert(token->type == TOKEN_NumericString);

        token = next_token(&tokenizer);
        assert(token->type == TOKEN_OBJECT);

        token = next_token(&tokenizer);
        assert(token->type == TOKEN_ObjectDescriptor);

        token = next_token(&tokenizer);
        assert(token->type == TOKEN_OCTET);

        token = next_token(&tokenizer);
        assert(token->type == TOKEN_OF);

        token = next_token(&tokenizer);
        assert(token->type == TOKEN_OID_IRI);

        token = next_token(&tokenizer);
        assert(token->type == TOKEN_OPTIONAL);

        token = next_token(&tokenizer);
        assert(token->type == TOKEN_PATTERN);

        token = next_token(&tokenizer);
        assert(token->type == TOKEN_PDV);

        token = next_token(&tokenizer);
        assert(token->type == TOKEN_PLUS_INFINITY);

        token = next_token(&tokenizer);
        assert(token->type == TOKEN_PRESENT);

        token = next_token(&tokenizer);
        assert(token->type == TOKEN_PrintableString);

        token = next_token(&tokenizer);
        assert(token->type == TOKEN_PRIVATE);

        token = next_token(&tokenizer);
        assert(token->type == TOKEN_REAL);

        token = next_token(&tokenizer);
        assert(token->type == TOKEN_RELATIVE_OID);

        token = next_token(&tokenizer);
        assert(token->type == TOKEN_RELATIVE_OID_IRI);

        token = next_token(&tokenizer);
        assert(token->type == TOKEN_SEQUENCE);

        token = next_token(&tokenizer);
        assert(token->type == TOKEN_SET);

        token = next_token(&tokenizer);
        assert(token->type == TOKEN_SETTINGS);

        token = next_token(&tokenizer);
        assert(token->type == TOKEN_SIZE);

        token = next_token(&tokenizer);
        assert(token->type == TOKEN_STRING);

        token = next_token(&tokenizer);
        assert(token->type == TOKEN_SYNTAX);

        token = next_token(&tokenizer);
        assert(token->type == TOKEN_UNKNOWN);
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
        tokenizer_t tokenizer;
        tokenizer.stream = "CHOICE INTEGER";
        tokenizer.pos = 0;

        assert(next_char(&tokenizer) == 'C');
        assert(next_char(&tokenizer) == 'H');
        assert(next_char(&tokenizer) == 'O');
        assert(next_char(&tokenizer) == 'I');
        assert(next_char(&tokenizer) == 'C');
        assert(next_char(&tokenizer) == 'E');

        assert(next_char(&tokenizer) == ' ');

        assert(next_char(&tokenizer) == 'I');
        assert(next_char(&tokenizer) == 'N');
        assert(next_char(&tokenizer) == 'T');
        assert(next_char(&tokenizer) == 'E');
        assert(next_char(&tokenizer) == 'G');
        assert(next_char(&tokenizer) == 'E');
        assert(next_char(&tokenizer) == 'R');

        assert(next_char(&tokenizer) == '\0');
        assert(next_char(&tokenizer) == '\0');
        assert(next_char(&tokenizer) == '\0');
}

void
test_peer_char() {
        tokenizer_t tokenizer;
        tokenizer.stream = "CHOICE INTEGER";
        tokenizer.pos = 0;

        assert(next_char(&tokenizer) == 'C');

        /* peer char */
        assert(peek_char(&tokenizer) == 'H');
                
        assert(next_char(&tokenizer) == 'H');
        assert(next_char(&tokenizer) == 'O');
        assert(next_char(&tokenizer) == 'I');
        assert(next_char(&tokenizer) == 'C');
        assert(next_char(&tokenizer) == 'E');

        assert(next_char(&tokenizer) == ' ');

        assert(next_char(&tokenizer) == 'I');
        assert(next_char(&tokenizer) == 'N');
        assert(next_char(&tokenizer) == 'T');
        assert(next_char(&tokenizer) == 'E');
        assert(next_char(&tokenizer) == 'G');
        assert(next_char(&tokenizer) == 'E');

        /* peer char */
        assert(peek_char(&tokenizer) == 'R');

        assert(next_char(&tokenizer) == 'R');

        /* peer char */

        assert(peek_char(&tokenizer) == '\0');
        assert(peek_char(&tokenizer) == '\0');

        assert(next_char(&tokenizer) == '\0');
        assert(next_char(&tokenizer) == '\0');
        assert(next_char(&tokenizer) == '\0');
}

int
main() {
        test_is_white_space();
        test_next_char();
        test_peer_char();

        test_next_token();
}
