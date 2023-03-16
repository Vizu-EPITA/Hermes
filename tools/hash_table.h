#ifndef CRAWLER_H
#define CRAWLER_H

typedef struct Ht_item
{
	char* key;
	char* value;
	Ht_item* next;
} Ht_item;

typedef struct HashTable
{
	Ht_item** items;
	size_t size;
	size_t count;
} HashTable;

Ht_item* create_item(char* key, char* value);

HashTable* create_table(size_t size);

void free_item(Ht_item* item);

void free_table(HashTable* table);

void ht_insert(HashTable* table, char* key, char* value);

char* ht_search(HashTable* table, char* key);

void print_table(HashTable* table);

#endif
