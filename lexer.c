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

Tok *
tok_init(size_t len, char *val)
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

void
lex_advance(Tok *in)
{
    
}

Tok *
lex_peek(Tok *in)
{
    Tok *ret = in;
    return ret;
}

/* TODO: Add strip_whitespace function
 * Add peek function, refactor lex
 */
Tok*
lex(char *s, size_t len)
{
    // printf("Are we even getting here?!\n");
    Tok *res = tok_init(len * sizeof(Tok), 0);
    Tok *tokptr = res;
    int i = 0;

    char *in = trim_whitespace(s);

    while (*in != '\0' || i < len){
        char *curr = in;
        Tok *currtok = lex_malloc(sizeof(Tok));
        currtok->val = lex_malloc(sizeof(char));
        switch (*curr)
        {
        case 10: // carriage return
            in++;
            i++;
            break; // ignore whitespace
        case 13: // newline
            in++;
            i++;
            break; // ignore whitespace
        case 32: // space
            in++;
            i++;
            break; // ignore whitespace
        case '{':
            currtok->type = TOKEN_LBRACKET;
            strncpy(currtok->val, curr, 1);
            memcpy(tokptr, currtok, sizeof(Tok));
            in++;
            i++;
            tokptr++;
            break;
        case '}':
            currtok->type = TOKEN_RBRACKET;
            strncpy(currtok->val, curr, 1);
            memcpy(tokptr, currtok, sizeof(Tok));
            in++;
            i++;
            tokptr++;
            break;
        case '(':
            currtok->type = TOKEN_LPAREN;
            strncpy(currtok->val, curr, 1);
            memcpy(tokptr, currtok, sizeof(Tok));
            in++;
            i++;
            tokptr++;
            break;
        case ')':
            currtok->type = TOKEN_RPAREN;
            strncpy(currtok->val, curr, 1);
            memcpy(tokptr, currtok, sizeof(Tok));
            in++;
            i++;
            tokptr++;
            break;
        case ';':
            currtok->type = TOKEN_SEMICOLON;
            strncpy(currtok->val, curr, 1);
            memcpy(tokptr, currtok, sizeof(Tok));
            in++;
            i++;
            tokptr++;
            break;
        case ':':
            currtok->type = TOKEN_COLON;
            strncpy(currtok->val, curr, 1);
            memcpy(tokptr, currtok, sizeof(Tok));
            in++;
            i++;
            tokptr++;
            break;
        case '.':
            currtok->type = TOKEN_PERIOD;
            strncpy(currtok->val, curr, 1);
            memcpy(tokptr, currtok, sizeof(Tok));
            in++;
            i++;
            tokptr++;
            break;
        default:
            in++;
            i++;
            tokptr++;
            break;
        }
        // tokptr++;
        // in++;
        // i++;
    }
    return res;
}
