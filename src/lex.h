/*
 * Copyright (c) 2014 Matt Fichman
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, APEXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 */

typedef enum lex_TokenType {
    /* Symbols and operators */
    lex_TokenType_lparen = '(',
    lex_TokenType_rparen = ')',
    lex_TokenType_lbracket = '[',
    lex_TokenType_rbracket = ']',
    lex_TokenType_lbrace = '{',
    lex_TokenType_rbrace = '}',
    lex_TokenType_plus = '+',
    lex_TokenType_minus = '-',
    lex_TokenType_star = '*',
    lex_TokenType_slash = '/',
    lex_TokenType_mod = '%',
    lex_TokenType_backslash = '\\',
    lex_TokenType_eq = '=',
    lex_TokenType_backtick = '`',
    lex_TokenType_caret = '^',
    lex_TokenType_less = '<',
    lex_TokenType_greater = '>',
    lex_TokenType_not = '!',
    lex_TokenType_ampersand = '&',
    lex_TokenType_tilde = '~',
    lex_TokenType_dollar = '$',
    lex_TokenType_hash = '#',

    /* Compound operators */
    lex_TokenType_leq = 0x256, // <=
    lex_TokenType_geq, // >=
    lex_TokenType_neq, // !=
    lex_TokenType_lshift, // <<
    lex_TokenType_rshfit, // >>

    /* Identifier */
    lex_TokenType_name,

    /* Keywords */
    lex_TokenType_import,
    lex_TokenType_export,
    lex_TokenType_struct,
    lex_TokenType_func,
    lex_TokenType_const,
    lex_TokenType_for,
    lex_TokenType_return,
    lex_TokenType_macro,
    lex_TokenType_enum,
    lex_TokenType_var,
    lex_TokenType_const,
    lex_TokenType_if,
    lex_TokenType_else,

    /* Sentinels */
    lex_TokenType_error,
    lex_TokenType_eof,
} lex_TokenType;

typedef struct lex_Token {
    lex_TokenType type;
    char* text;   
    uint32_t line;
    uint32_t column;
} lex_Token;

typedef struct lex_Lexer {
    FILE* file;
    uint32_t line;
    uint32_t column;
} lex_Lexer;

lex_Lexer* lex_init(FILE* file);
lex_Token* lex_token(lex_Lexer* self);
