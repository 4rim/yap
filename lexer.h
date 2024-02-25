#include <stdlib.h>

#define LEX_YAP_TYPE_INT 0
#define LEX_YAP_TYPE_SHORT 1
#define LEX_YAP_TYPE_FLOAT 2

#define LEX_YAP_FUNC_PRINT 11

typedef struct {
    unsigned int type;
    const char *symb;
} Entry;

/* Valid yap symbols */
Entry keyword_dict[] = {
    { LEX_YAP_TYPE_INT, "int" },
    { LEX_YAP_TYPE_FLOAT, "float" },
    { LEX_YAP_TYPE_SHORT, "short" },
    { LEX_YAP_FUNC_PRINT, "print" }
};

typedef enum {
    // TOKEN_SYMBOL, // variable name?
    TOKEN_PAIR, // () {}
    TOKEN_LPAREN,
    TOKEN_RPAREN,
    TOKEN_LBRACKET,
    TOKEN_RBRACKET,
    TOKEN_PUNCT, // ; :
    TOKEN_OP, // + - * /
    TOKEN_KEYWORD, // types, e.g., int
    TOKEN_COMMENT
} Tok_type;

typedef struct {
    Tok_type type;
    char *val;
} Tok;

void die(void);
void *lex_malloc(size_t);
Tok *create_tok(size_t);
void destroy_tok(Tok *, size_t);
Tok *lex(char *, size_t);
