CC=gcc
CFLAGS=-I../include/

all: create_dir ../build/examples/example1.out

.PHONY: create_dir
create_dir: ../build/examples 

../build/examples:
	@mkdir -p ../build/examples/

../build/examples/example1.out: example1.c ../include/key_value/key_value.h ../include/key_value/hashing.h ../include/sgxc/sgxc.h ../build/lib/key_value/key_value.o ../build/lib/key_value/hashing.o
	$(CC) $(CFLAGS) -o ../build/examples/example1.out example1.c ../build/lib/key_value/key_value.o ../build/lib/key_value/hashing.o

