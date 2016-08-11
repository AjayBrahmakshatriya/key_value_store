#include "key_value/key_value.h"
#include <stdlib.h>
#include <string.h>

key_value* key_value_create(void) {
	key_value* kv;
	kv = (key_value*) malloc(sizeof(key_value));
	kv->table = malloc(sizeof(struct node*)*TABLE_SIZE);
	return kv;
}

struct node* search_node(key_value *kv, char *key) {
	int index = hash(key) % TABLE_SIZE;
	struct node* s = kv->table[index];
	while(s != NULL) {
		if(strcmp(key, s->key)==0)
			return s;
	}
	return NULL;
}

void* key_value_search_key(key_value* kv, char *key) {
	struct node* s = search_node(kv, key);
	if ( s == NULL )
		return NULL;
	return s->value;
}

void key_value_insert(key_value *kv, char *key, void* value) {
	struct node* s = search_node(kv, key);
	if ( s != NULL ) {
		s->value = value;
		return;
	}
	int index = hash(key) % TABLE_SIZE;
	s = kv->table[index];
	struct node *n = malloc(sizeof(struct node));
	kv->table[index] = n;
	n->next = s;
	n->value = value;
	n->key = key;
	return;
}
void key_value_delete_key(key_value *kv, char *key) {
	struct node* s;
	struct node* p = NULL;
	int index = hash(key) % TABLE_SIZE;
	s = kv->table[index];
	while( s!=NULL ) {
		if (strcmp(s->key, key)==0){
			if( p != NULL ){
				p->next = s->next;
			}else{
				kv->table[index] = s->next;
			}
			free(s);
			return;
		}
		p = s;
		s = s -> next;
	}
	return;
}

void key_value_destroy(key_value *kv) {
	struct node *s;
	struct node *n;
	int i;
	for(i = 0; i < TABLE_SIZE ; i++ ) {
		s = kv->table[i];
		while( s != NULL){
			n = s->next;
			free(s);
			s = n;
		}
	}
	free(kv->table);
	free(kv);
}
