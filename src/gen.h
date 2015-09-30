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


typedef struct ir_InstrList ir_InstrList;

typedef enum ir_InstrCode {
	ir_InstrCode_jeq, // jmp reg[c]
	ir_InstrCode_jge,
	ir_InstrCode_jgt,
	ir_InstrCode_jle,
	ir_InstrCode_jlt,
	ir_InstrCode_jne,
	ir_InstrCode_jnz, 
	ir_InstrCode_jz, 
	ir_InstrCode_call, // call mem[a]...mem[b]
	ir_InstrCode_cmp, // reg[c] = reg[a] cmp reg[b]
	ir_InstrCode_add, // reg[c] = reg[a] + reg[b]
	ir_InstrCode_div, // reg[c] = reg[a] / reg[b]
	ir_InstrCode_mul, // reg[c] = reg[a] * reg[b]
	ir_InstrCode_sub, // reg[c] = reg[a] - reg[b]
	ir_InstrCode_jmp, // jmp reg[a]
	ir_InstrCode_load, // reg[c] = mem[reg[a]]
	ir_InstrCode_loadi, // reg[c] = mem[a]
	ir_InstrCode_mov, // reg[c] = reg[a]
	ir_InstrCode_ret, // ret mem[a]...mem[b]
	ir_InstrCode_store, // mem[reg[c]] = reg[a]
} ir_InstrCode;

typedef enum ir_Type {
	ir_Type_i64;
	ir_Type_i32;
	ir_Type_i16;
	ir_Type_i8;
	ir_Type_f64;
	ir_Type_f32;
	ir_Type_ptr;
} ir_OperandType;

typedef struct ir_Operand {
	uint32_t val;
	ir_Type type;
} ir_Operand;

typedef struct ir_Instr {
	ir_InstrCode code;
	ir_Operand a;
	ir_Operand b;
} ir_Instr;

typedef struct ir_Block {

} ir_Block;

typedef struct ir_Func {
	ir_InstrList* instr;
} ir_Func;

typedef struct ir_Generator {
	int foo;
} ir_Generator;

vector_define(ir_InstrList,ir_Instr);

ir_Generator* ir_init(semant_Program* prog);
ir_Func const* ir_func(ir_Generator* gen);


