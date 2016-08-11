CC=gcc
CFLAGS=-I../../include -c


all: ../../build/lib/key_value/key_value.o ../../build/lib/key_value/hashing.o

../../build/lib/key_value/key_value.o: key_value.c ../../include/key_value/key_value.h ../../include/key_value/hashing.h create_dir
	$(CC) $(CFLAGS) key_value.c -o ../../build/lib/key_value/key_value.o

../../build/lib/key_value/hashing.o: hashing.c ../../include/key_value/hashing.h create_dir
	$(CC) $(CFLAGS) hashing.c -o ../../build/lib/key_value/hashing.o

.PHONY: create_dir

create_dir: 
	@mkdir -p ../../build/lib/key_value
