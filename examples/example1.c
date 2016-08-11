#include "key_value/key_value.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sgxc/sgxc.h"
int main(){
	SECRET char *value = (SECRET char*) secret_malloc(100);
	strcpy(value, "value");
	key_value *kv = key_value_create();
	key_value_insert(kv, "key", (void*)value);
	key_value_change_case_reverse_key(kv, "key");
	void *res = key_value_search_key(kv,"key");
	if (res == NULL){
		printf("NOT FOUND\n");
	}else{
		printf("VALUE FOUND = %s\n", (SECRET char*) res); //THIS SHOULD BE flagged as warning
	}
	key_value_destroy(kv);
	free(value);
	return 0;
}
