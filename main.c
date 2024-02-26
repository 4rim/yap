#include "lexer.c"
#include <stdlib.h>

/* TODO: 
 * main should take in a file name as input. For now, we are pretending that
 * the first argument is the code line we are trying to lex, but this is
 * obviously incorrect lexing in general. */

void
usage(void)
{
    printf("Usage: ./main <file name>\n");
    exit(EXIT_FAILURE);
}

int
main(int argc, char **argv)
{
    if (argc <= 1)
        usage();

    size_t len = strlen(argv[1]);
    Lex_T* ret = lex_malloc(len);
    int i = 0;
    ret = lex(argv[1], len);

    Lex_T* t = ret;

    printf("[");
    for (i = 0; i < len-1; ++i, ++t) {
        printf("(%d, \"%s\")", t->type, t->val);
        printf(" ");
    }
    printf("(%d, \"%s\")", t->type, t->val);
    printf("]\n");
    free(ret);

    return EXIT_SUCCESS;
}
