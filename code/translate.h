#include <stdio.h>
#include "hashmap.h"

void write_binary_op(FILE* f, char op);
void write_unary_op(FILE* f, char op);
void write_logic_op(FILE* f, char* op, int i);
void write_push(FILE* f, char* segment, char* num, char* fname);
void write_pop(FILE* f, char* segment, char* num, char* fname);
void write_function(FILE* f, char* label, char* nVars);
void write_call(FILE* f, char* label, char* nArgs);
void write_boot_code(FILE* f);
void write_generic_return(FILE* f);
void translate_cmd(FILE* f, char* fname, char* args[], HashTable* labels);
void print_totals();
