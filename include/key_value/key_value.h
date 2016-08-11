#ifndef KEY_VALUE
#define KEY_VALUE

#include "sgxc/sgxc.h"
#include "hashing.h"

#define TABLE_SIZE 1024

struct node {
	char *key;
	void *value;
	struct node *next;
};

typedef struct {
	struct node** table;	
}key_value;

key_value* key_value_create(void);
void key_value_insert(key_value*, char*, void*);
void* key_value_search_key(key_value*, char*);
void key_value_delete_key(key_value*, char*);
void key_value_destroy(key_value*);

void key_value_change_case_reverse_key(key_value*, char*);
 
#endif
