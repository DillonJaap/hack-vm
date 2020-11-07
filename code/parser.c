#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#include "parser.h"
#include "translate.h"
#include "error.h"

// like fgetc, but skip comments
char fgetcskip(FILE *f)
{
	char cur  = '\0';

	while((cur = fgetc(f)) == '\r');

	if (cur == '/')
	{
		if (fgetc(f) == '/')
			while((cur = fgetc(f)) != '\n' && cur != EOF);
		else
			fseek(f, -1, SEEK_CUR);
	}

	return cur;
}

// copy src into dest until you see a character that is in til or *src == '\0'
char* strcpytil(char* dest, char* src, const char* til)
{
	while (!strchr(til, *src) && *src != '\0')
		*(dest++) = *(src++);

	*dest = '\0';

	return src;
}

// test if there are more instructions in the file
int is_more_cmds(FILE *f)
{
	char c = '\0';

	int pos = ftell(f);
	while ((c = fgetcskip(f)) == '\n'); // loop until non blank line
	fseek(f, pos, SEEK_SET);

	if (c == EOF)
		return 0;
	return 1;
}

int get_cmd(FILE* f, char* cmd)
{
	// keep count of number of lines traversed
	int num_lines = 0;
	int i = 0;

	// skip white space
	while (isspace(*cmd = fgetcskip(f)))
	{
		if (*cmd == '\n')
			num_lines++;
	}

	while (cmd[i] != '\n' && i < MAX_INST)
		cmd[++i] = fgetcskip(f);

	cmd[i] = '\0';

	return num_lines + 1;
}

// get n arguments, returns the position where it ends
int get_nargs(char** args, char* cmd, int num)
{
	int i = 0;

	// get arguments
	for (i = 0; i < num && *cmd != '\0'; i++)
	{
		// skip leading white space
		for (; isspace(*cmd); cmd++); 
		if (*cmd == '\0')
			break;
		cmd = strcpytil(args[i], cmd, " \t");
	}

	int count = i;

	// no more arguments, set the rest to empty
	while (i < MAX_ARGS)
		*args[i++] = '\0';

	// return the position where it stopped copying args
	return count;
}


// pre_scan vm code for errors and build hash table of labels names
int pre_scan(FILE* f, char* fname, HashTable* labels)
{
	HashTable* cmds;
	HashTable* segments;
	//HashTable* labels;
	init_tables(&cmds, &segments);

	char cmd[MAX_INST];
	char* args[MAX_ARGS+1];

	int nArgs = 0;
	int line_num = 0;

	// init args, array of pointers to strings
	for (int i = 0; i < MAX_ARGS; i++)
		args[i] = malloc(sizeof(char) * (MAX_INST/MAX_ARGS));
	args[MAX_ARGS] = NULL; // list of args is NULL terminated

	// KEEP TRACK OF WHAT FUNCTION WE ARE IN TO KEEP TRACK OF SCOPE, "" IS
	// GLOBAL 
	char function_name[2048] = "";
	char label_name[4096]    = "";
	// build labels table
	while (is_more_cmds(f))
	{
		get_cmd(f, cmd);
		nArgs = get_nargs(args, cmd, MAX_ARGS);

		if (strcmp(args[0], "function") == 0)
			strcpy(function_name, args[1]); // entered scope of a function
		if (strcmp(args[0], "label") == 0)
		{
			if (strcmp(function_name, "") != 0)
			{
				sprintf(label_name, "%s.%s", function_name, args[1]);
			//	printf("%s\n", label_name);
			}
			ht_insert(labels, label_name, (void*)&args[2], INT);
		}
		if (strcmp(args[0], "return") == 0)
			strcpy(function_name, ""); // left function in global scope
	}

	fseek(f, 0, SEEK_SET);

	int errors = 0;
	while (is_more_cmds(f))
	{
		line_num += get_cmd(f, cmd);
		nArgs = get_nargs(args, cmd, MAX_ARGS);
		errors += check_error(cmds, segments, labels, args, nArgs, fname, cmd, line_num);
	}
	return errors;
}

void parse(FILE* in, FILE* out, char* fname, bool boot, HashTable* labels)
{
	char cmd[MAX_INST];
	char* args[MAX_ARGS+1];
	fseek(in, 0, SEEK_SET);

	// init args, array of pointers to strings
	for (int i = 0; i < MAX_ARGS; i++)
		args[i] = malloc(sizeof(char) * (MAX_INST/MAX_ARGS));
	args[MAX_ARGS] = NULL; // list of args is NULL terminated
	while (is_more_cmds(in))
	{
		get_cmd(in, cmd);
		get_nargs(args, cmd, MAX_ARGS);
		translate_cmd(out, fname, args, labels);
	}
}
