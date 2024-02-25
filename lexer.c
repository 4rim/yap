#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lexer.h"

void
die(void)
{
    fprintf(stderr, "Oopsie...");
    exit(EXIT_FAILURE);
}

void *
lex_malloc(size_t s)
{
    void *ret = malloc(s);
    if (ret == NULL) {
        free(ret);
        die();
    }
    return ret;
}

Tok*
create_tok(size_t len)
{
    Tok *ret = (Tok *) lex_malloc(len);
    return ret;
}

void
destroy_tok(Tok *t, size_t len)
{
    for (int i = len; i < 0; --i, --t) {
        free(t);
    }
}

/* TODO: Make this with switch? */
Tok*
lex(char *s, size_t len)
{
    Tok *res = create_tok(len * sizeof(Tok));
    Tok *tokptr = res;
    int i = 0;

    while (*s != '\0' || i < len){
        char *curr;
        curr = s;
        Tok *currtok = lex_malloc(sizeof(Tok));
        currtok->val = lex_malloc(sizeof(char)+1);
        if (*curr == '\n'){
            s++;
            i++;
            tokptr++;
            continue; // ignore whitespace
        }
        if (*curr == ';' ||
            *curr == ':') {
            currtok->type = TOKEN_PUNCT;
            strncpy(currtok->val, curr, 1);
            memcpy(tokptr, currtok, sizeof(Tok));
        } else if (*curr == '{') {
            currtok->type = TOKEN_LBRACKET;
            strncpy(currtok->val, curr, 1);
            memcpy(tokptr, currtok, sizeof(Tok));
        } else if (*curr == '}') {
            currtok->type = TOKEN_RBRACKET;
            strncpy(currtok->val, curr, 1);
            memcpy(tokptr, currtok, sizeof(Tok));
        } else if (*curr == '(') {
            currtok->type = TOKEN_LPAREN;
            strncpy(currtok->val, curr, 1);
            memcpy(tokptr, currtok, sizeof(Tok));
        } else if (*curr == ')') {
            currtok->type = TOKEN_RPAREN;
            strncpy(currtok->val, curr, 1);
            memcpy(tokptr, currtok, sizeof(Tok));
        }
        else {
            s++;
            i++;
            continue;
        }
        tokptr++;
        s++;
        i++;
    }
    return res;
}
