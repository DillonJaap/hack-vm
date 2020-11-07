#include <stdbool.h>
#include "hashmap.h"

#define MAX_INST 1024
#define MAX_ARGS 8

/*
enum InstType
{
	NONE       = 0,
	PUSH       = 1,
	POP        = 2,
	LABEL      = 3,
	GOTO       = 4,
	IF         = 5,
	FUNCTION   = 6,
	RETURN     = 7,
	CALL       = 8,
	ARITHMETIC = 9,
};
*/


char fgetcskip(FILE *f);
char* strcpytil(char* dest, char* src, const char* til);
int is_more_cmds(FILE *f);
int get_cmd(FILE* f, char* cmd);
int get_cmd_type(const char* cmd);
int get_nargs(char** args, char* cmd, int num);
int pre_scan(FILE* f, char* fname, HashTable* labels);
void parse(FILE* in, FILE* out, char* fname, bool boot, HashTable* labels);
