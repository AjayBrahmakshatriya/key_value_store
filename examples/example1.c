#include "key_value/key_value.h"
#include <stdio.h>

int main(){
	key_value *kv = key_value_create();
	key_value_insert(kv, "key", (void*)"value");
	void *res = key_value_search_key(kv,"key");
	if (res == NULL){
		printf("NOT FOUND\n");
	}else{
		printf("VALUE FOUND = %s\n", (char*) res);	
	}
	key_value_destroy(kv);
	return 0;
}
