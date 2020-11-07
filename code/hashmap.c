#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include "hashmap.h"

uint32_t hash_string(char* s)
{
	int hash = 7;
	for (; *s != '\0'; s++)
		hash = hash * 31 + *s;
	return hash;
}

void ht_copy_data(Data* dest, void* src, DataType type)
{
	// copy data
	switch (type)
	{
		case INT: 
			dest->i = *(int*)src;
			break;
		case FLOAT:
			dest->f = *(double*)src;
			break;
		case STRING:
			strcpy(dest->str, (char*)src);
		       	break;
		default:
			printf("error: specifiy data type to be copied!\n");
			break;
	}
}

struct Cell* init_cell(char key[], void* data, DataType type)
{
	// init cell
	struct Cell* cell;
	cell = malloc(sizeof(struct Cell));
	cell->next = NULL;

	//copy key
	strcpy(cell->key, key);

	// copy data
	ht_copy_data(&cell->data, data, type);
	
	return cell;
}

HashTable* init_ht(DataType type)
{
	HashTable* ht = malloc(sizeof(ht) * sizeof(struct Cell*) * LENGTH);

	ht->type = type;
	for (int i = 0; i < LENGTH; i++)
		ht->table[i] = NULL;

	return ht;
}

// init various tables for parsing the text in the program
void init_tables(HashTable** cmds, HashTable** segments)
{
	*cmds      = init_ht(INT);
	*segments  = init_ht(INT);
	int32_t num = 0;

	// insert all commands
	num = 3; // number of required parameters
       	ht_insert(*cmds, "pop",      (void*)&num, INT);
	ht_insert(*cmds, "push",     (void*)&num, INT);
	ht_insert(*cmds, "function", (void*)&num, INT);
	ht_insert(*cmds, "call",     (void*)&num, INT);
	num = 2;
       	ht_insert(*cmds, "label",    (void*)&num, INT);
	ht_insert(*cmds, "goto",     (void*)&num, INT);
	ht_insert(*cmds, "if-goto",  (void*)&num, INT);
	num = 1;
       	ht_insert(*cmds, "return",   (void*)&num, INT);
	ht_insert(*cmds, "add",      (void*)&num, INT);
	ht_insert(*cmds, "sub",      (void*)&num, INT);
	ht_insert(*cmds, "and",      (void*)&num, INT);
	ht_insert(*cmds, "or",       (void*)&num, INT);
	ht_insert(*cmds, "or",       (void*)&num, INT);
	ht_insert(*cmds, "neg",      (void*)&num, INT);
	ht_insert(*cmds, "not",      (void*)&num, INT);
	ht_insert(*cmds, "eq",       (void*)&num, INT);
	ht_insert(*cmds, "gt",       (void*)&num, INT);
	ht_insert(*cmds, "lt",       (void*)&num, INT);
	// extended commands
	ht_insert(*cmds, "bool",     (void*)&num, INT);
	ht_insert(*cmds, "ne",       (void*)&num, INT);
	ht_insert(*cmds, "ge",       (void*)&num, INT);
	ht_insert(*cmds, "le",       (void*)&num, INT);
	ht_insert(*cmds, "l-and",    (void*)&num, INT);
	ht_insert(*cmds, "l-not",    (void*)&num, INT);
	ht_insert(*cmds, "l-or",     (void*)&num, INT);
	ht_insert(*cmds, "l-xor",    (void*)&num, INT);

	num = 32767; // max address
	ht_insert(*segments, "local",    (void*)&num, INT);
	ht_insert(*segments, "argument", (void*)&num, INT);
	ht_insert(*segments, "this",     (void*)&num, INT);
	ht_insert(*segments, "that",     (void*)&num, INT);
	ht_insert(*segments, "constant", (void*)&num, INT);
	ht_insert(*segments, "ram",      (void*)&num, INT);
	num = 2; // max address
	ht_insert(*segments, "pointer",  (void*)&num, INT);
	num = 7; // max address
	ht_insert(*segments, "temp",     (void*)&num, INT);
	num = 239; // max address
	ht_insert(*segments, "static",   (void*)&num, INT);
}

void ht_insert(HashTable* ht, char* key, void* data, DataType type)
{
	uint32_t index = hash_string(key) % LENGTH;
	struct Cell* cell;

	// if no type specified, use the one provided by the hash table
	if (type == NONE)
		type = ht->type;

	// cell is first in current row
	if (ht->table[index] == NULL)
	{
		ht->table[index] = init_cell(key, data, type);
		return;
	}
		
	// find where to insert cell
	cell = ht->table[index]; 
	for (;;)
	{
		// cell already exists update data
		if (strcmp(cell->key, key) == 0)
		{
			ht_copy_data(&cell->data, data, type);
			return;
		}
		// end of list, create new cell
		else if (cell->next == NULL)
		{
			cell->next = init_cell(key, data, type);
			return;
		}

		cell = cell->next;
	}
}

int ht_delete(HashTable* ht, char* key)
{
	uint32_t index = hash_string(key) % LENGTH;
	struct Cell temp_cell; 
	struct Cell* cell = &temp_cell; 

	cell->next = ht->table[index];

	for (;;)
	{
		if (cell->next == NULL)
			return 0;
		else if (strcmp(cell->next->key, key) == 0)
		{
			struct Cell* tmp = cell->next;
			cell->next = cell->next->next;
			free(tmp);
		return 1;
		}
		cell = cell->next;
	}
}

bool ht_exists(HashTable* ht, char* key)
{
	uint32_t index = hash_string(key) % LENGTH;
	struct Cell* cell = ht->table[index];

	// first cell in current row
	if (cell == NULL)
		return false;

	while (strcmp(cell->key, key) != 0)
	{
		if (cell->next == NULL)
			return false;
		cell = cell->next;
	}
	return true;
}

bool ht_find(HashTable* ht, char* key, void* data, DataType type)
{
	uint32_t index = hash_string(key) % LENGTH;
	struct Cell* cell = ht->table[index];

	// if no type specified, use the one provided by the hash table
	if (type == NONE)
		type = ht->type;

	// first cell in current row
	if (cell == NULL)
		return false;

	while (strcmp(cell->key, key) != 0)
	{
		if (cell->next == NULL)
			return false;
		 cell = cell->next;
	}

	switch (type)
	{
		case INT: 
			*(int*)data = cell->data.i;
			break;
		case FLOAT:
			*(double*)data = cell->data.f;
			break;
		case STRING:
			strcpy((char*)data, cell->data.str);
		       	break;
		default:
			printf("error: specifiy data type to be copied!\n");
			break;
	}
	return true;
}
