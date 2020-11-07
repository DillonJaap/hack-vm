#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "translate.h"
#include "vmcmds.c"
#include "xvmcmds.c"

//*****************************************************************************
// NOT IN SUBMISSION USED TO PROFILE THE NUMBER OF EACH INSTRUCTION RAN
//*****************************************************************************
int label = 0;
int if_goto = 0;
int _goto = 0;
int call = 0;
int _return = 0;
int function = 0;

int push_total = 0;
int push_constant = 0;
int push_static = 0;
int push_local = 0;
int push_argument = 0;
int push_this = 0;
int push_that = 0;
int push_temp = 0;
int push_pointer_this = 0;
int push_pointer_that = 0;

int pop_total = 0;
int pop_constant = 0;
int pop_static = 0;
int pop_local = 0;
int pop_argument;
int pop_this = 0;
int pop_that = 0;
int pop_temp = 0;
int pop_pointer_this = 0;
int pop_pointer_that = 0;

int _lt = 0;
int _gt = 0;
int _eq = 0;
int sub = 0;
int add = 0;
int neg = 0;
int and = 0;
int or  = 0;
int _not = 0;
//*****************************************************************************

const int TEMP_BASE_ADDR = 5;
	

void write_logic_op(FILE* f, char* op, int i)
{
	static int count[6] = {0};
	fprintf(f, logic_op_asm, op, count[i], op, op, count[i]);
	count[i]++;
}

void write_push(FILE* f, char* segment, char* num, char* fname)
{
	if      (strcmp(segment, "local") == 0)
	{
		if (strcmp(num, "0") != 0)
			fprintf(f, push_mem_asm, num, "LCL");
		else
			fprintf(f, push_mem_zero_asm, "LCL");
		push_local++;
	}
	else if (strcmp(segment, "argument") == 0)
	{
		if (strcmp(num, "0") != 0)
			fprintf(f, push_mem_asm, num, "ARG");
		else
			fprintf(f, push_mem_zero_asm, "ARG");
		push_argument++;
	}
	else if (strcmp(segment, "this") == 0)
	{
		if (strcmp(num, "0") != 0)
			fprintf(f, push_mem_asm, num, "THIS");
		else
			fprintf(f, push_mem_zero_asm, "THIS");
		push_this++;
	}
	else if (strcmp(segment, "that") == 0)
	{
		if (strcmp(num, "0") != 0)
			fprintf(f, push_mem_asm, num, "THAT");
		else
			fprintf(f, push_mem_zero_asm, "THAT");
		push_that++;
	}
	else if (strcmp(segment, "constant") == 0)
	{
		fprintf(f, push_const_asm, num);
		push_constant++;
	}
	else if (strcmp(segment, "ram") == 0)
	{
		fprintf(f, push_ram_asm, num);
	}
	else if (strcmp(segment, "temp") == 0)
	{
		// get address to reference temp_base + num
		int addr = atoi(num) + TEMP_BASE_ADDR;
		fprintf(f, push_temp_asm, addr);
		push_temp++;
	}
	else if (strcmp(segment, "pointer") == 0)
	{
		if      (strcmp(num, "0") == 0)
		{
			fprintf(f, push_value_asm, "THIS");
			push_pointer_this++;
		}
		else if (strcmp(num, "1") == 0)
		{
			fprintf(f, push_value_asm, "THAT");
			push_pointer_that++;
		}
	}
	else if (strcmp(segment, "static") == 0)
	{
		// "filename.num"
		char static_name[64];
		strcpy(static_name, fname);
		strcat(static_name, ".");
		strcat(static_name, num);
		fprintf(f, push_value_asm, static_name);
		push_static++;
	}
}

void write_pop(FILE* f, char* segment, char* num, char* fname)
{
	if      (strcmp(segment, "local") == 0)
	{
		fprintf(f, pop_mem_asm, num, "LCL");
		pop_local++;
	}
	else if (strcmp(segment, "argument") == 0)
	{
		fprintf(f, pop_mem_asm, num, "ARG");
		pop_argument++;
	}
	else if (strcmp(segment, "this") == 0)
	{
		fprintf(f, pop_mem_asm, num, "THIS");
		pop_this++;
	}
	else if (strcmp(segment, "that") == 0)
	{
		fprintf(f, pop_mem_asm, num, "THAT");
		pop_that++;
	}
	else if (strcmp(segment, "constant") == 0)
	{
		fprintf(f, pop_const_asm, num);
		pop_constant++;
	}
	else if (strcmp(segment, "ram") == 0)
	{
		fprintf(f, pop_ram_asm, num);
	}
	else if (strcmp(segment, "temp") == 0)
	{
		// get address to reference temp_base + num
		int addr = atoi(num) + TEMP_BASE_ADDR;
		fprintf(f, pop_temp_asm, addr);
		pop_temp++;
	}
	else if (strcmp(segment, "pointer") == 0)
	{
		if      (strcmp(num, "0") == 0)
		{
			fprintf(f, pop_value_asm, "THIS");
			pop_pointer_this++;
		}
		else if (strcmp(num, "1") == 0)
		{
			fprintf(f, pop_value_asm, "THAT");
			pop_pointer_that++;
		}
	}
	else if (strcmp(segment, "static") == 0)
	{
		// "filename.num"
		char static_name[64];
		strcpy(static_name, fname);
		strcat(static_name, ".");
		strcat(static_name, num);
		fprintf(f, pop_value_asm, static_name);
		pop_static++;
	}
}

void write_function(FILE* f, char* label, char* nVars)
{
	int count = atoi(nVars);


	//fprintf(f, function_header_asm);
	fprintf(f, label_asm, label);
	for (int i = 0; i < count; i++) 
		fprintf(f, push_zero_asm);
}

void write_call(FILE* f, char* label, char* nArgs)
{
	static int count = 0;
	char ret_address[128] = "";
	strcat(ret_address, label);
	strcat(ret_address, ".return");
	sprintf(ret_address, "%s.%d", ret_address, count++);
	fprintf(f, call_asm, ret_address, nArgs, label, ret_address);
}

// XVM instructions
void write_bool(FILE* f)
{
	static int count = 0;
	fprintf(f, bool_asm, count, count);
	count++;
}

void write_lnot(FILE* f)
{
	static int count = 0;
	fprintf(f, l_not_asm, count, count);
	count++;
}

void write_land(FILE* f)
{
	static int count = 0;
	fprintf(f, l_and_asm, count, count, count);
	count++;
}

void write_lor(FILE* f)
{
	static int count = 0;
	fprintf(f, l_or_asm, count, count, count);
	count++;
}

void write_lxor(FILE* f)
{
	static int count = 0;
	fprintf(f, l_xor_asm, count, count, count, count, count, count, count, count, count, count);
	count++;
}

void write_boot_code(FILE* f)
{
	fprintf(f, "// BOOT CODE\n");
	fprintf(f, boot_asm);
}

void write_generic_return(FILE* f)
{
	fprintf(f, "// Generic Return\n");
	fprintf(f, generic_return_asm);
}

void translate_cmd(FILE* f, char* fname, char* args[], HashTable* labels)
{
	fprintf(f, "// ");
	for (int i = 0; args[i] != NULL; i++)
		fprintf(f, "%s ", args[i]);
	fprintf(f, "\n");

	char fname_label[4000];
	static char func_name[4000];
	static char func_label[4000];
	sprintf(fname_label, "%s.%s", fname, args[1]);

	if (strcmp(args[0], "pop") == 0) // memory access commands
	{
		write_pop(f, args[1], args[2], fname);
		pop_total++;
	}
	else if (strcmp(args[0], "push") == 0)
	{
		write_push(f, args[1], args[2], fname);
		push_total++;
	}
	else if (strcmp(args[0], "label") == 0) // branching command
	{
		sprintf(func_label, "%s.%s", func_name, args[1]);
		if (ht_exists(labels, func_label))
		{
			sprintf(fname_label, "%s.%s", fname, func_label);
		}
		fprintf(f, label_asm, fname_label);
		label++;
	}
	else if (strcmp(args[0], "goto") == 0)
	{
		sprintf(func_label, "%s.%s", func_name, args[1]);
		if (ht_exists(labels, func_label))
		{
			//printf("%s\n", func_label);
			sprintf(fname_label, "%s.%s", fname, func_label);
		}
		fprintf(f, goto_asm, fname_label); 
		_goto++;
	}
	else if (strcmp(args[0], "if-goto") == 0)
	{
		sprintf(func_label, "%s.%s", func_name, args[1]);
		if (ht_exists(labels, func_label))
		{
			//printf("%s\n", func_label);
			sprintf(fname_label, "%s.%s", fname, func_label);
		}
		fprintf(f, if_goto_asm , fname_label);
		if_goto++;
	}
	else if (strcmp(args[0], "function") == 0)
	{
		sprintf(func_name, "%s", args[1]);
		write_function(f, args[1], args[2]);
		function++;
	}
	else if (strcmp(args[0], "call") == 0)
	{
		write_call(f, args[1], args[2]);
		call++;
	}
	else if (strcmp(args[0], "return") == 0)
	{
		sprintf(func_name, "");
		//fprintf(f, return_asm);
		fprintf(f, "@...GENERIC_RETURN...\n"); // jump to return statement
		fprintf(f, "0;JMP\n");
		_return++;
	}
	else if (strcmp(args[0], "add") == 0)
	{
		fprintf(f, bin_op_asm, '+');
		add++;
	}
	else if (strcmp(args[0], "sub") == 0)
	{
		fprintf(f, sub_asm);
		sub++;
	}
	else if (strcmp(args[0], "and") == 0)
	{
		fprintf(f, bin_op_asm, '&');
		and++;
	}
	else if (strcmp(args[0], "or") == 0)
	{
		fprintf(f, bin_op_asm, '|');
		or++;
	}
	else if (strcmp(args[0], "neg") == 0)
	{
		fprintf(f, unary_op_asm, '-');
		neg++;
	}
	else if (strcmp(args[0], "not") == 0)
	{
		fprintf(f, unary_op_asm, '!');
		_not++;
	}
	else if (strcmp(args[0], "eq") == 0)
	{
		write_logic_op(f, "EQ", 0);
		_eq++;
	}
	else if (strcmp(args[0], "gt") == 0)
	{
		write_logic_op(f, "GT", 1);
		_gt++;
	}
	else if (strcmp(args[0], "lt") == 0)
	{
		write_logic_op(f, "LT", 2);
		_lt++;
	}
	// XVM commands
	else if (strcmp(args[0], "bool") == 0)
		write_bool(f);
	else if (strcmp(args[0], "ne") == 0)
		write_logic_op(f, "NE", 3);
	else if (strcmp(args[0], "ge") == 0)
		write_logic_op(f, "GE", 4);
	else if (strcmp(args[0], "le") == 0)
		write_logic_op(f, "LE", 5);
	else if (strcmp(args[0], "l-and") == 0)
		write_land(f);
	else if (strcmp(args[0], "l-not") == 0)
		write_lnot(f);
	else if (strcmp(args[0], "l-or") == 0)
		write_lor(f);
	else if (strcmp(args[0], "l-xor") == 0)
		write_lxor(f);
}

void print_totals()
{
	printf("%17s: %d\n", "label", label);
	printf("%17s: %d\n", "if_goto", if_goto);
	printf("%17s: %d\n", "_goto", _goto);
	printf("%17s: %d\n", "call", call);
	printf("%17s: %d\n", "_return", _return);
	printf("%17s: %d\n", "function", function);

	printf("%17s: %d\n", "push_total", push_total);
	printf("%17s: %d\n", "push_constant", push_constant);
	printf("%17s: %d\n", "push_static", push_static);
	printf("%17s: %d\n", "push_local", push_local);
	printf("%17s: %d\n", "push_argument", push_argument);
	printf("%17s: %d\n", "push_this", push_this);
	printf("%17s: %d\n", "push_that", push_that);
	printf("%17s: %d\n", "push_temp", push_temp);
	printf("%17s: %d\n", "push_pointer_this", push_pointer_this);
	printf("%17s: %d\n", "push_pointer_that", push_pointer_that);

	printf("%17s: %d\n", "pop_total", pop_total);
	printf("%17s: %d\n", "pop_constant", pop_constant);
	printf("%17s: %d\n", "pop_static", pop_static);
	printf("%17s: %d\n", "pop_local", pop_local);
	printf("%17s: %d\n", "pop_argument", pop_argument);
	printf("%17s: %d\n", "pop_this", pop_this);
	printf("%17s: %d\n", "pop_that", pop_that);
	printf("%17s: %d\n", "pop_temp", pop_temp);
	printf("%17s: %d\n", "pop_pointer_this", pop_pointer_this);
	printf("%17s: %d\n", "pop_pointer_that", pop_pointer_that);

	printf("%17s: %d\n", "sub", sub);
	printf("%17s: %d\n", "add", add);
	printf("%17s: %d\n", "neg", neg);
	printf("%17s: %d\n", "and", and);
	printf("%17s: %d\n", "or ", or );
	printf("%17s: %d\n", "_not", _not);
	printf("%17s: %d\n", "_lt", _lt);
	printf("%17s: %d\n", "_gt", _gt);
	printf("%17s: %d\n", "_eq", _eq);
}
