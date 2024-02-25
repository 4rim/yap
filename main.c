#include "lexer.c"
#include <stdlib.h>

void
usage(void)
{
    printf("./main \"<string to be lexed>\"");
    exit(EXIT_FAILURE);
}

int
main(int argc, char **argv)
{
    if (argc <= 1)
        usage();
    size_t len = strlen(argv[1]);
    Tok* ret = lex_malloc(len);
    int i = 0;
    ret = lex(argv[1], len);

    Tok* t = ret;

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
