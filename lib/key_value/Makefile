CC=gcc
CFLAGS=-I../../include -c
TARGET_DIR=../../build/lib/key_value

all: create_dir ../../build/lib/key_value/key_value.o ../../build/lib/key_value/hashing.o

.PHONY: create_dir
create_dir: ${TARGET_DIR}

../../build/lib/key_value/key_value.o: key_value.c ../../include/key_value/key_value.h ../../include/key_value/hashing.h ../../include/sgxc/sgxc.h
	$(CC) $(CFLAGS) key_value.c -o ../../build/lib/key_value/key_value.o

../../build/lib/key_value/hashing.o: hashing.c ../../include/key_value/hashing.h ../../include/sgxc/sgxc.h
	$(CC) $(CFLAGS) hashing.c -o ../../build/lib/key_value/hashing.o


${TARGET_DIR}: 
	@mkdir -p ../../build/lib/key_value
