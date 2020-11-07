#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include "parser.h"
#include "translate.h"
#include "hashmap.h"

#ifdef _WIN32
#define SEP_CHAR '\\'
#else
#define SEP_CHAR '/'
#endif

void get_name(char* dest, char* src)
{
	char* beg = src;
	for(; *src != '\0'; src++);              // get to end of string
	for(; *src != SEP_CHAR && src != beg; src--); // get to first / or begining
	src++;
	while(*src != '\0' && *src != '.')              // get to end of string
		*dest++ = *src++;
	*dest = '\0';
}

void get_dir(char* dest, char* src)
{
	char* mark = src;
	char* prev = src;

	while (*src != '\0')              // get to end of string
	{
		if (*prev == SEP_CHAR)
			mark = src;
		prev = src;
		src++;
	}

	if (mark != NULL)
	{
		while (*mark != SEP_CHAR && *mark != '\0') // get to first / or begining
			*dest++ = *mark++;
	}
	*dest = '\0';
}

void get_file_ext(char *dest, char* src)
{
	char* mark = NULL;
	while(*src != '\0')              // get to end of string
	{
		if (*src == '.')
			mark = src;
		*src++;
	}
	while(mark != NULL && *mark != '\0')              // get to end of string
		*dest++ = *mark++;
	*dest = '\0';
}


void append_sep(char* src)
{
	for (; *src != '\0'; src++);
	if (*(src - 1) != SEP_CHAR)
	{
		*src = SEP_CHAR;
		*(src + 1) = '\0';
	}

}

int main(int argc, char* argv[])
{
	// get array of strings
	char* files[16];
	for (int i = 0; i < 16; i++)
	{
		files[i] = malloc(sizeof(char) * 128);
		*files[i] = '\0';
	}

	// current file
	char vm_dir[128] = "";

	// grab command line arguments
	strcpy(vm_dir, argv[1]);
	append_sep(vm_dir);
	printf("opening directory: %s\n", vm_dir);

	// no input file was supplied
	if (strcmp(vm_dir, "") == 0)
	{
		printf("ERROR: no VM file given >:(\n");
		return 1;
	}

	// get files in given directory
	char file_ext[6];
	bool boot = false;
	struct dirent *de;
	DIR *dr = opendir(vm_dir);


	char file_path[128];
	for (int i = 0; de = readdir(dr);)
	{
		get_file_ext(file_ext, de->d_name);
		if (strcmp(file_ext, ".vm") == 0)
		{
			strcpy(file_path, vm_dir);
			strcat(file_path, de->d_name);
			strcpy(files[i++], file_path);
		}
		if (strcmp(de->d_name, "Sys.vm") == 0)
			boot = true;
	}


	// preparse files
	FILE* f;
	char file_name[128];
	int errors = 0;
	HashTable* labels; 
	labels = init_ht(INT);

	for (int i = 0; *files[i] != '\0'; i++)
	{
		printf("file: %s\n", files[i]);
		f = fopen(files[i], "r");
		get_name(file_name, files[i]);

		errors += pre_scan(f, file_name, labels);
	}

	if (errors > 0)
	{
		printf("No file created, %d errors found!\n", errors);
		return 1;
	}

	// parse and compile
	char out_file[128];
	char out_name[128];
	get_dir(out_name, vm_dir);
	strcat(out_name, ".asm");

	strcpy(out_file, vm_dir);
	strcat(out_file, out_name);

	FILE* out = fopen(out_file, "w");

	if (boot)
		write_boot_code(out);
	write_generic_return(out);

	// print generic return;
	for (int i = 0; *files[i] != '\0'; i++)
	{
		f = fopen(files[i], "r");
		get_name(file_name, files[i]);
		parse(f, out, file_name, boot, labels);
		boot = false;
		fclose(f);
	}

	fclose(out);
	print_totals();
	return 0;
}
