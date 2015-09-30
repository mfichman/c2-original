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


typedef struct gen_InstrList gen_InstrList;

typedef enum gen_InstrCode {
	gen_InstrCode_beq,
	gen_InstrCode_bge,
	gen_InstrCode_bgt,
	gen_InstrCode_ble,
	gen_InstrCode_blt,
	gen_InstrCode_bne,
	gen_InstrCode_bnz,
	gen_InstrCode_bz,
	gen_InstrCode_call, // call mem[a]...mem[b]
	gen_InstrCode_cmp, // reg[c] = reg[a] cmp reg[b]
	gen_InstrCode_add, // reg[c] = reg[a] + reg[b]
	gen_InstrCode_div, // reg[c] = reg[a] / reg[b]
	gen_InstrCode_mul, // reg[c] = reg[a] * reg[b]
	gen_InstrCode_sub, // reg[c] = reg[a] - reg[b]
	gen_InstrCode_jmp, // jmp reg[a]
	gen_InstrCode_load, // reg[c] = mem[reg[a]]
	gen_InstrCode_loadi, // reg[c] = mem[a]
	gen_InstrCode_mov, // reg[c] = reg[a]
	gen_InstrCode_ret, // ret mem[a]...mem[b]
	gen_InstrCode_store, // mem[reg[c]] = reg[a]
} gen_InstrCode;

typedef enum gen_Type {
	gen_Type_i64;
	gen_Type_i32;
	gen_Type_i16;
	gen_Type_i8;
	gen_Type_f64;
	gen_Type_f32;
	gen_Type_ptr;
} gen_OperandType;

typedef struct gen_Operand {
	uint64_t val;
	gen_Type type;
} gen_Operand;

typedef struct gen_Instr {
	gen_InstrCode code;
	gen_Operand a;
	gen_Operand b;
	gen_Operand c;
} gen_Instr;

typedef struct gen_Func {
	gen_InstrList* instr;
} gen_Func;

typedef struct gen_Generator {
	int foo;
} gen_Generator;

vector_define(gen_InstrList,gen_Instr);

gen_Generator* gen_init(semant_Program* prog);
gen_Func const* gen_func(gen_Generator* gen);


