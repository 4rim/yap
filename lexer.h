#ifndef LEX_H_
#define LEX_H_
#endif

#include <stdlib.h>

#define LEX_YAP_TYPE_INT 0
#define LEX_YAP_TYPE_SHORT 1
#define LEX_YAP_TYPE_FLOAT 2

#define LEX_YAP_FUNC_PRINT 11

typedef struct {
    unsigned int type;
    const char *symb;
} Entry;

typedef enum {
    TOKEN_END = 0,
    TOKEN_LPAREN,
    TOKEN_RPAREN,
    TOKEN_LBRACKET,
    TOKEN_RBRACKET,
    TOKEN_COLON,
    TOKEN_SEMICOLON,
    TOKEN_PERIOD,
    TOKEN_KEYWORD, // types, e.g., int
    TOKEN_STRING,
    TOKEN_COMMENT,
    TOKEN_NUMBER
} Tok_type;

typedef struct {
    Tok_type type;
    char *val;
    int idx;
} Lex_T;

void die(void);

char *trim_whitespace(char *);

void *lex_malloc(size_t);
void destroy_tok(Lex_T *, size_t);
void lex_advance(Lex_T *);

Lex_T *lex(char *, size_t);
Lex_T *tok_init(size_t, char *);
Lex_T *lex_peek(Lex_T *);
