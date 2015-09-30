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

/* Definitions for the semantic analyzer. The semantic analyzer builds up a
 * semantic tree, which annotates the AST with additional semantic information.
 * The original AST is not modified in this process. Instead, each AST node has
 * a corresponding semantic tree node, which has the additional information
 * annotated by the semantic analyzer.
 *
 * A note on memory management: Like the AST, the semantic analyzer allocates
 * memory using an arena-based bump allocator.
 */

typedef char const* semant_Id;

typedef struct semant_ExprList semant_ExprList;
typedef struct semant_FuncList semant_FuncList;
typedef struct semant_FileList semant_FileList;

typedef struct semant_Expr {
	parse_Expr* parsed;
	semant_Id type;	
	semant_ExprList* child;
} semant_Expr;

typedef struct semant_Func {
	parse_Func* parsed;
	semant_Expr* body;
} semant_Func;

typedef struct semant_File {
	parse_File* parsed;
	semant_FuncList* func;
} semant_File;

typedef struct semant_Program {
	parse_Program* parsed;
	semant_FileList* file;	
} semant_Program;

typedef struct semant_Analyzer {
	int foo;
} semant_Analyzer;

vector_define(semant_ExprList,semant_Expr*);
vector_define(semant_FuncList,semant_Func*);
vector_define(semant_FileList,semant_File*);

semant_Analyzer* semant_init(parse_Program* prog);

semant_Program const* semant_program(semant_Analyzer* self);
semant_File const* semant_file(semant_Analyzer* self);
semant_Func const* semant_func(semant_Analyzer* self);
semant_Expr const* semant_expr(semant_Analyzer* self);
