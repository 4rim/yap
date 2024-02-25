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
    // TOKEN_SYMBOL, // variable name?
    TOKEN_LPAREN,
    TOKEN_RPAREN,
    TOKEN_LBRACKET,
    TOKEN_RBRACKET,
    TOKEN_COLON,
    TOKEN_SEMICOLON,
    TOKEN_KEYWORD, // types, e.g., int
    TOKEN_COMMENT
} Tok_type;

typedef struct {
    Tok_type type;
    char *val;
} Tok;

void die(void);
void *lex_malloc(size_t);
void destroy_tok(Tok *, size_t);
void lex_advance(Tok *);

Tok *lex(char *, size_t);
Tok *create_tok(size_t);
Tok *lex_peek(Tok *);
