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

#include "vector.h"
#include "lex.h"

typedef struct ExprList ExprList;
typedef struct FuncList FuncList;
typedef struct ImportList ImportList;
typedef struct StructList StructList;
typedef struct AttrList AttrList;
typedef struct ArgList ArgList;
typedef struct RetList RetList;
typedef struct IdList IdList;

typedef char* Id;

typedef enum ExprType {
    ExprType_binary,
    ExprType_call,
    ExprType_postfix,
    ExprType_ident,
    ExprType_literal,
    ExprType_block,
    ExprType_if,
    ExprType_while,
    ExprType_for,
} ExprType;

typedef struct Expr {
    ExprType type;
    char* value;
    ExprList* child;
} Expr;

typedef enum FuncFlags {
    FuncFlags_macro = 0x1,
    FuncFlags_export = 0x2,
} FuncFlags;

typedef struct Func {
    FuncFlags flags; 
    Expr* body;
    ArgList* arg;
    RetList* ret;
} Func;

typedef struct Arg {
    Id name;
    Id type;
} Arg;

typedef struct Ret {
    Id type;
} Ret;

typedef struct Import {
    Id name;
} Import;

typedef struct Attr {
    Id name;
    Id type;
} Attr;

typedef struct Struct {
    Id name;
    FuncList* func;
    AttrList* attr;
    // attributes
} Struct;

typedef struct File {
    ImportList* import;
    StructList* strct;
    FuncList* func;
} File;


typedef struct Parser {
    Lexer* lexer;
} Parser;

vector_define(ExprList,Expr*);
vector_define(FuncList,Func*);
vector_define(ImportList,Import*);
vector_define(StructList,Import*);
vector_define(AttrList,Attr*);
vector_define(ArgList,Arg*);
vector_define(RetList,Ret*);
vector_define(IdList,Id);

Parser* parse_init(Lexer* lexer);
File* parse_file(Parser* self);
Struct* parse_struct(Parser* self);
Attr* parse_attr(Parser* self);
Import* parse_import(Parser* self);
Ret* parse_ret(Ret* self);
Arg* parse_arg(Ret* self);
Func* parse_func(Ret* self);
Expr* parse_expr(Ret* self);
Id parse_id(Ret* self);


