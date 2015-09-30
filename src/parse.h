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

/* Definitions for the parser. The parser consumes a stream of tokens, and
 * builds an abstract syntax tree using the structures defined below. 
 *
 * A note on memory management: The parser allocates all memory using the arena
 * bump allocator. During normal compilation, this memory is never freed, since
 * the compiler exits soon after the AST is no longer needed. However, when
 * used as a library, it may make sense to free the AST to reclaim memory. In
 * this case, a call to parser_free will free the all ASTs created by the
 * parser.
 */

/* List typedefs */
typedef struct parse_ExprList parse_ExprList;
typedef struct parse_FuncList parse_FuncList;
typedef struct parse_ImportList parse_ImportList;
typedef struct parse_StructList parse_StructList;
typedef struct parse_AttrList parse_AttrList;
typedef struct parse_ArgList parse_ArgList;
typedef struct parse_RetList parse_RetList;
typedef struct parse_IdList parse_IdList;
typedef struct parse_FileList parse_FileList;
typedef char const* parse_Id;

/* Public structures */
typedef enum parse_ExprType {
    parse_ExprType_binary,
    parse_ExprType_call,
    parse_ExprType_postfix,
    parse_ExprType_ident,
    parse_ExprType_literal,
    parse_ExprType_block,
    parse_ExprType_if,
    parse_ExprType_while,
    parse_ExprType_for,
	parse_ExprType_assign,
	parse_ExprType_reassign,
} parse_ExprType;

typedef struct parse_Expr {
    parse_ExprType type;
    char* value;
    parse_ExprList* child;
} parse_Expr;

typedef enum parse_FuncFlags {
    parse_FuncFlags_macro = 0x1,
    parse_FuncFlags_export = 0x2,
} parse_FuncFlags;

typedef struct parse_Func {
    parse_FuncFlags flags; 
    parse_Expr* body;
    parse_ArgList* arg;
    parse_RetList* ret;
} parse_Func;

typedef struct parse_Arg {
    parse_Id name;
    parse_Id type;
} parse_Arg;

typedef struct parse_Ret {
    parse_Id type;
} parse_Ret;

typedef struct parse_Import {
    parse_Id name;
} parse_Import;

typedef struct parse_Attr {
    parse_Id name;
    parse_Id type;
} parse_Attr;

typedef struct parse_Struct {
    parse_Id name;
    parse_FuncList* func;
    parse_AttrList* attr;
    // attributes
} parse_Struct;

typedef struct parse_File {
    parse_ImportList* import;
    parse_StructList* strct;
    parse_FuncList* func;
} parse_File;

typedef struct parse_Program {
	parse_FileList* file;
} parse_Program;

typedef struct parse_Parser {
    lex_Lexer* lexer;
} parse_Parser;

/* List type definitions */
vector_define(parse_ExprList,parse_Expr*);
vector_define(parse_FuncList,parse_Func*);
vector_define(parse_ImportList,parse_Import*);
vector_define(parse_StructList,parse_Import*);
vector_define(parse_AttrList,parse_Attr*);
vector_define(parse_ArgList,parse_Arg*);
vector_define(parse_RetList,parse_Ret*);
vector_define(parse_FileList,parse_File*);
vector_define(parse_IdList,parse_Id);

/* Public function API */
parse_Parser* parse_init(lex_Lexer* lexer);
void parse_free(parse_Parser* self);

/* Top-level parsing routines */
parse_Program const* parse_program(parse_Parser* self);
parse_File const* parse_file(parse_Parser* self);
parse_Struct const* parse_struct(parse_Parser* self);
parse_Attr const* parse_attr(parse_Parser* self);
parse_Import const* parse_import(parse_Parser* self);
parse_Ret const* parse_ret(parse_Parser* self);
parse_Arg const* parse_arg(parse_Parser* self);
parse_Func const* parse_func(parse_Parser* self);
parse_Expr const* parse_expr(parse_Parser* self);
parse_Id parse_id(parse_Ret* self);

/* Expression parsing */
parse_Expr const* parse_binary(parse_Parser* self);
parse_Expr const* parse_call(parse_Parser* self);
parse_Expr const* parse_postfix(parse_Parser* self);
parse_Expr const* parse_ident(parse_Parser* self);
parse_Expr const* parse_literal(parse_Parser* self);
parse_Expr const* parse_block(parse_Parser* self);
parse_Expr const* parse_if(parse_Parser* self);
parse_Expr const* parse_while(parse_Parser* self);
parse_Expr const* parse_if(parse_Parser* self);
parse_Expr const* parse_for(parse_Parser* self);
parse_Expr const* parse_assign(parse_Parser* self);
parse_Expr const* parse_reassign(parse_Parser* self);


