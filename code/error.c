#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "error.h"
#include "hashmap.h"

void print_error(char* msg, char* fname, char* cmd, int line_num)
{
	printf("%s:%d: error: ", fname, line_num);
	printf("%s\n", msg);
	printf("  %d | %s\n\n", line_num, cmd);
}

int check_error(HashTable* cmds, HashTable* segments, HashTable* labels,
	       	char* args[], int nArgs, char* fname, char* cmd, int line_num)
{
	int errors = 0;
	if (!is_cmd(cmds, args[0]))
	{
		print_error("unkown command", fname, cmd, line_num);
		errors += 1;
	}
	else if (!properly_formated(cmds, args[0], nArgs))
	{
		char msg[32];
		sprintf(msg, "incorret num of args: %d", nArgs);
		print_error(msg, fname, cmd, line_num);
		errors += 1;
	}
	else if (strcmp(args[0], "pop") == 0 || strcmp(args[0], "push") == 0)
	{
		if (!known_mem_seg(segments, args[1]))
		{
			print_error("unkown segment", fname, cmd, line_num);
			errors += 1;
		}
		if (!(legal_index(args[2])))
		{
			print_error("illegal index", fname, cmd, line_num);
			errors += 1;
		}
		else if (!index_in_range(segments, args[1], args[2]))
		{
			print_error("index out of range", fname, cmd, line_num);
			errors += 1;
		}
	}
	else if (strcmp(args[0], "label") == 0 || strcmp(args[0], "goto") == 0
		|| strcmp(args[0], "if-goto") == 0)
	{
		if (!legal_label(args[1]))
		{
			print_error("illegal label", fname, cmd, line_num);
			errors += 1;
		}
		else if (!resolved_label(labels, args[1]))
		{
			print_error("unresolved label", fname, cmd, line_num);
			errors += 1;
		}
	}
	else if (strcmp(args[0], "function") == 0 
		|| strcmp(args[0], "call") == 0)
	{
		if (!legal_label(args[1]))
		{
			print_error("illegal function name", fname, cmd, line_num);
			errors += 1;
		}
		if (!(legal_index(args[2])))
		{
			print_error("illegal count", fname, cmd, line_num);
			errors += 1;
		}
	}

	return errors;
}

bool is_cmd(HashTable* cmds, char* cmd_name)
{
	return ht_exists(cmds, cmd_name);
}

bool known_mem_seg(HashTable* segments, char* seg)
{
	return ht_exists(segments, seg);
}

bool resolved_label(HashTable* labels, char* label)
{
	//return ht_exists(labels, label); // REMOVED for SCOPE compatiblity
	return true;
}

bool properly_formated(HashTable* cmds, char* cmd_name, int nArgs)
{
	int data = 0;
	ht_find(cmds, cmd_name, (void*)&data, INT);
	return (nArgs == data) ? true : false;
}

bool legal_index(const char* num)
{
	if (num[0] == '\0')
		return false;

	char valid[24];

	if (!strncmp("0x", num, 2) || !strncmp("0X", num, 2))
	{
		strcpy(valid, "1234567890abcdefABCDEF");
		num += 2;
	}
	else if (!strncmp("0b", num, 2) || !strncmp("0B", num, 2))
	{
		strcpy(valid, "01");
		num += 2;
	}
       	else
		strcpy(valid, "1234567890");

	size_t valid_len = strspn(num, valid);
	if (valid_len != strlen(num))
		return false;
	return true;
}

bool index_in_range(HashTable* segments, char* seg, char* addr)
{
	int addr_int = atoi(addr);
	int num = addr_int;
	ht_find(segments, seg, (void*)&num, INT);
	return (addr_int <= num) ? true : false;
}

bool legal_label(char* name)
{
		// names cannot start with numbers
	if (!isalpha(name[0]) && name[0] != '.' && name[0] != '_'
		       	&& name[0] != '$' && name[0] != ':')
		return false;

	char* valid =
		"1234567890"
		"abcdefghijklmnopqrstuvwxyz"
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ_.$:";
	size_t valid_len = strspn(name, valid);

	if (valid_len != strlen(name))
		return false;
	return true;
}
