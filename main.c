#include "lexer.c"
#include <stdlib.h>

/* TODO: 
 * main should take in a file name as input. For now, we are pretending that
 * the first argument is the code line we are trying to lex, but this is
 * obviously incorrect lexing in general. */
/* TODO: init-ing the tok is not being done correctly in main(), there are
 * garbage values */

void
usage(void)
{
    printf("Usage: ./main <file name>\n");
    exit(EXIT_FAILURE);
}

int
main(int argc, char **argv)
{
    // if (argc <= 1)
    //     usage();

    char *content = "x = (a + b) * cat";

    size_t len = strlen(content);
    tok_T* ret = lex_malloc(len);
    ret = lex(content, len);

    tok_T* t = ret;

    if (ret->len <= 0) {
        destroy_tok(ret, 1);
        return EXIT_SUCCESS;
    }
    
    while (t->type != TOKEN_EOF) {
        printf("(%d, \"%s\")\n", t->type, t->val);
        t++;
    }

    free(ret);

    return EXIT_SUCCESS;
}
