#include "key_value/hashing.h"

// implements djb2 hashing of strings. Refer: http://cse.yorku.ca/~oz/hash.html
unsigned long hash(char* string) {
	unsigned long hash = 5381;
	int c;
	while(c = *string++) {
		hash = ((hash << 5) + hash) + c;
	}
	return hash;
}
