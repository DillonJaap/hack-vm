#include <stdbool.h>
#include "hashmap.h"

void print_error(char* msg, char* fname, char* cmd, int line_num);
int check_error(HashTable* cmds, HashTable* segments, HashTable* labels,
	       	char* args[], int nArgs, char* fname, char* cmd, int line_num);
bool is_cmd(HashTable* cmds, char* cmd_name);
bool known_mem_seg(HashTable* segments, char* seg);
bool resolved_label(HashTable* labels, char* label);
bool properly_formated(HashTable* cmds, char* cmd_name, int nArgs);
bool legal_index(const char* num);
bool index_in_range(HashTable* segments, char* seg, char* addr);
bool legal_label(char* name);
