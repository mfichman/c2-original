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

#include <stdio.h>

typedef enum TokenType {
    TokenType_lparen = '(',
    TokenType_rparen = ')',
    TokenType_lbracket = '[',
    TokenType_rbracket = ']',
    TokenType_lbrace = '{',
    TokenType_rbrace = '}',
    TokenType_plus = '+',
    TokenType_minus = '-',
    TokenType_star = '*',
    TokenType_slash = '/',
    TokenType_backslash = '\\',
    TokenType_eq = '=',
    TokenType_backtick = '`',
    TokenType_caret = '^',
    TokenType_name = 0x256,
    TokenType_error,
    TokenType_eof,
} TokenType;

typedef struct Token {
    TokenType type;
    char* text;   
    uint32_t line;
    uint32_t column;
} Token;

typedef struct Lexer {
    FILE* file;
    uint32_t line;
    uint32_t column;
} Lexer;

Lexer* lex_init(FILE* file);
Token* lex_token(Lexer* self);

