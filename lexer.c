#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "lexer.h"

Entry keyword_dict[] = {
    /* { LEX_YAP_TYPE_INT, "int" },
    { LEX_YAP_TYPE_FLOAT, "float" },
    { LEX_YAP_TYPE_SHORT, "short" },
    { LEX_YAP_FUNC_PRINT, "print" } */
    0
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

tok_T *
tok_init(size_t len, char *val)
{
    tok_T *ret = (tok_T *) lex_malloc(len);
    ret->len = 0;
    ret->val = val;
    ret->type = TOKEN_EOF;
    return ret;
}

void
destroy_tok(tok_T *t, size_t len)
{
}

char *
scan_ident(char *c)
{
    char *iter = c;
    char *ret = calloc(strlen(c), sizeof(char));
    while (iter != NULL && isalpha(*iter)) {
        strncat(ret, iter, sizeof(char));
        iter++;
    }
    return ret;
}

void
lex_advance(tok_T *in)
{
    in->len++;
    in->val++;
    return;
}

tok_T *
lex_peek(tok_T *in)
{
    tok_T *ret = in;
    return ret;
}

tok_T
lex_match(char *in)
{
    tok_T ret = {0};
    return ret;
}

bool
is_symbol_start(char x)
{
    return isalpha(x) || x == '_';
}

/* TODO: 
 * Add peek function, refactor lex
 */
tok_T*
lex(char *s, size_t len)
{
    // printf("Are we even getting here?!\n");
    tok_T *res = calloc(len, sizeof(tok_T));
    tok_T *tokptr = res;
    int i = 0;

    char *in = trim_whitespace(s);

    size_t temp = strlen(in);

    while (*in != '\0' || i < len){
        char *curr = in;
        tok_T *currtok = lex_malloc(sizeof(tok_T));
        currtok->val = lex_malloc(sizeof(char));
        currtok->len = temp;
        if (*curr == 10 || *curr == 13 || *curr == 32) {
            in++;
            i++;
        } else if (isdigit(*curr)) {
            currtok->type = TOKEN_DIGIT;
            strncpy(currtok->val, curr, 1);
            memcpy(tokptr, currtok, sizeof(tok_T));
            tokptr++;
            in++;
            i++;
        } else if (isalpha(*curr)) {
            // Implement a "scan_string" function?
            currtok->type = TOKEN_SYMB;
            currtok->val = scan_ident(curr);
            strncpy(currtok->val, curr, sizeof(char));
            memcpy(tokptr, currtok, sizeof(tok_T));
            tokptr += strlen(currtok->val);
            in += strlen(currtok->val);
            i++;
        } else {
            switch (*curr)
            {
            case '{':
                currtok->type = TOKEN_LBRACKET;
                strncpy(currtok->val, curr, 1);
                memcpy(tokptr, currtok, sizeof(tok_T));
                break;
            case '}':
                currtok->type = TOKEN_RBRACKET;
                strncpy(currtok->val, curr, 1);
                memcpy(tokptr, currtok, sizeof(tok_T));
                break;
            case '(':
                currtok->type = TOKEN_LPAREN;
                strncpy(currtok->val, curr, 1);
                memcpy(tokptr, currtok, sizeof(tok_T));
                break;
            case ')':
                currtok->type = TOKEN_RPAREN;
                strncpy(currtok->val, curr, 1);
                memcpy(tokptr, currtok, sizeof(tok_T));
                break;
            case ';':
                currtok->type = TOKEN_SEMICOLON;
                strncpy(currtok->val, curr, 1);
                memcpy(tokptr, currtok, sizeof(tok_T));
                break;
            case ':':
                currtok->type = TOKEN_COLON;
                strncpy(currtok->val, curr, 1);
                memcpy(tokptr, currtok, sizeof(tok_T));
                break;
            case '.':
                currtok->type = TOKEN_PERIOD;
                strncpy(currtok->val, curr, 1);
                memcpy(tokptr, currtok, sizeof(tok_T));
                break;
            case '#':
                currtok->type = TOKEN_COMMENT;
                strncpy(currtok->val, curr, 1);
                memcpy(tokptr, currtok, sizeof(tok_T));
                break;
            case '-':
                currtok->type = TOKEN_MINUS;
                strncpy(currtok->val, curr, 1);
                memcpy(tokptr, currtok, sizeof(tok_T));
                break;
            case '+':
                currtok->type = TOKEN_PLUS;
                strncpy(currtok->val, curr, 1);
                memcpy(tokptr, currtok, sizeof(tok_T));
                break;
            case '*':
                currtok->type = TOKEN_TIMES;
                strncpy(currtok->val, curr, 1);
                memcpy(tokptr, currtok, sizeof(tok_T));
                break;
            case '/':
                currtok->type = TOKEN_DIV;
                strncpy(currtok->val, curr, 1);
                memcpy(tokptr, currtok, sizeof(tok_T));
                break;
            case '%':
                currtok->type = TOKEN_MOD;
                strncpy(currtok->val, curr, 1);
                memcpy(tokptr, currtok, sizeof(tok_T));
                break;
            case '=':
                currtok->type = TOKEN_EQ;
                strncpy(currtok->val, curr, 1);
                memcpy(tokptr, currtok, sizeof(tok_T));
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
