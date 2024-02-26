#ifndef LEX_H_
#define LEX_H_
#endif

#include <stdlib.h>
#include <stdbool.h>

#define LEX_YAP_FUNC_PRINT 11

typedef struct {
    unsigned int type;
    const char *symb;
} Entry;

typedef enum {
    TOKEN_EOF = 0,
    TOKEN_LPAREN,
    TOKEN_RPAREN,
    TOKEN_LBRACKET,
    TOKEN_RBRACKET,
    TOKEN_COLON,
    TOKEN_SEMICOLON,
    TOKEN_PERIOD,
    TOKEN_COMMENT,
    TOKEN_EQ,
    TOKEN_MINUS,
    TOKEN_PLUS,
    TOKEN_TIMES,
    TOKEN_DIV,
    TOKEN_MOD,
    TOKEN_KEYWORD, // types, e.g., int
    TOKEN_STRING,
    TOKEN_DIGIT,
    TOKEN_SYMB
} Tok_type;

typedef struct {
    Tok_type type;
    char *val;
    size_t len;
} tok_T;

void die(void);

char *trim_whitespace(char *);
char *scan_ident(char *);

void *lex_malloc(size_t);
void destroy_tok(tok_T *, size_t);
void lex_advance(tok_T *);

bool is_symbol_start(char);

// tok_T lex_match(char *);
tok_T *lex(char *, size_t);
tok_T *tok_init(size_t, char *);
tok_T *lex_peek(tok_T *);
