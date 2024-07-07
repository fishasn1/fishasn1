#include <assert.h>
#include <stdio.h>
#include "tokenizer.h"

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
}
