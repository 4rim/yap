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

char *
trim_whitespace(char *c)
{
    /* Can use isspace() */
    char *ret = lex_malloc(strlen(c) + 1);

    char *iter = c;
    char *curr = ret;

    while (*iter != '\0') {
        if (*iter == ' ' || *iter == 10  || *iter == 13  || *iter == '\t' ) 
            iter++;
        else { // not whitespace
            *curr = *iter;
            iter++;
            curr++;
        }
    }
    curr++;
    *curr = '\0';
    return ret;
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

Lex_T *
tok_init(size_t len, char *val)
{
    Lex_T *ret = (Lex_T *) lex_malloc(len);
    return ret;
}

void
destroy_tok(Lex_T *t, size_t len)
{
    for (int i = len; i < 0; --i, --t) {
        free(t);
    }
}

void
lex_advance(Lex_T *in)
{
    
}

Lex_T *
lex_peek(Lex_T *in)
{
    Lex_T *ret = in;
    return ret;
}

/* TODO: Add strip_whitespace function
 * Add peek function, refactor lex
 */
Lex_T*
lex(char *s, size_t len)
{
    // printf("Are we even getting here?!\n");
    Lex_T *res = tok_init(len * sizeof(Lex_T), 0);
    Lex_T *tokptr = res;
    int i = 0;

    char *in = trim_whitespace(s);

    while (*in != '\0' || i < len){
        char *curr = in;
        Lex_T *currtok = lex_malloc(sizeof(Lex_T));
        currtok->val = lex_malloc(sizeof(char));
        if (*curr == 10 || *curr == 13 || *curr == 32){
            in++;
            i++;
        } else {
            switch (*curr)
            {
            case '{':
                currtok->type = TOKEN_LBRACKET;
                strncpy(currtok->val, curr, 1);
                memcpy(tokptr, currtok, sizeof(Lex_T));
                break;
            case '}':
                currtok->type = TOKEN_RBRACKET;
                strncpy(currtok->val, curr, 1);
                memcpy(tokptr, currtok, sizeof(Lex_T));
                break;
            case '(':
                currtok->type = TOKEN_LPAREN;
                strncpy(currtok->val, curr, 1);
                memcpy(tokptr, currtok, sizeof(Lex_T));
                break;
            case ')':
                currtok->type = TOKEN_RPAREN;
                strncpy(currtok->val, curr, 1);
                memcpy(tokptr, currtok, sizeof(Lex_T));
                break;
            case ';':
                currtok->type = TOKEN_SEMICOLON;
                strncpy(currtok->val, curr, 1);
                memcpy(tokptr, currtok, sizeof(Lex_T));
                break;
            case ':':
                currtok->type = TOKEN_COLON;
                strncpy(currtok->val, curr, 1);
                memcpy(tokptr, currtok, sizeof(Lex_T));
                break;
            case '.':
                currtok->type = TOKEN_PERIOD;
                strncpy(currtok->val, curr, 1);
                memcpy(tokptr, currtok, sizeof(Lex_T));
                break;
            default:
                break;
        }
        tokptr++;
        in++;
        i++;
        }
    }
    return res;
}
