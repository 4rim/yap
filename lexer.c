#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lexer.h"

Entry keyword_dict[] = {
    { LEX_YAP_TYPE_INT, "int" },
    { LEX_YAP_TYPE_FLOAT, "float" },
    { LEX_YAP_TYPE_SHORT, "short" },
    { LEX_YAP_FUNC_PRINT, "print" }
};

void
die(void)
{
    fprintf(stderr, "OOPS!");
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

void lex_advance(Tok *in)
{
    
}

Tok *lex_peek(Tok *in)
{
    Tok *ret = in;
    return ret;
}

/* TODO: Add peek function, refactor lex
 * Note that as of now, "curr" refers to the entire string rather than one "token", leading to incorrect behaviour
 * */
Tok*
lex(char *s, size_t len)
{
    // printf("Are we even getting here?!\n");
    Tok *res = create_tok(len * sizeof(Tok));
    Tok *tokptr = res;
    int i = 0;

    while (*s != '\0' || i < len){
        char *curr = s;
        Tok *currtok = lex_malloc(sizeof(Tok));
        currtok->val = lex_malloc(sizeof(char));
        switch (*curr)
        {
        case '\n':
            s++;
            i++;
            tokptr++;
            break; // ignore whitespace
        case '{':
            currtok->type = TOKEN_LBRACKET;
            strncpy(currtok->val, curr, 1);
            memcpy(tokptr, currtok, sizeof(Tok));
            break;
        case '}':
            currtok->type = TOKEN_RBRACKET;
            strncpy(currtok->val, curr, 1);
            memcpy(tokptr, currtok, sizeof(Tok));
            break;
        case '(':
            currtok->type = TOKEN_LPAREN;
            strncpy(currtok->val, curr, 1);
            memcpy(tokptr, currtok, sizeof(Tok));
            break;
        case ')':
            currtok->type = TOKEN_RPAREN;
            strncpy(currtok->val, curr, 1);
            memcpy(tokptr, currtok, sizeof(Tok));
            break;
        case ';':
            currtok->type = TOKEN_SEMICOLON;
            strncpy(currtok->val, curr, 1);
            memcpy(tokptr, currtok, sizeof(Tok));
            break;
        case ':':
            currtok->type = TOKEN_COLON;
            strncpy(currtok->val, curr, 1);
            memcpy(tokptr, currtok, sizeof(Tok));
            break;
        }
        // if (*curr == ';' ||
        //     *curr == ':') {
        //     currtok->type = TOKEN_SEMICOLON;
        //     strncpy(currtok->val, curr, 1);
        //     memcpy(tokptr, currtok, sizeof(Tok));
        // } 
        // else {
        //    s++;
        //    i++;
        //    continue;
        // }
        tokptr++;
        s++;
        i++;
    }
    return res;
}
