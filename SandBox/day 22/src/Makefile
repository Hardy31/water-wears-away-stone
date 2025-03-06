CC=gcc
CFLAGS=-Wall -Werror -Wextra -std=c11
BUILD=../build/

all: cipher

cipher: cipher.c
	$(CC) $(CFLAGS) cipher.c -o $(BUILD)cipher

rebuild: crean all

clean:
	rm -rf $(BUILD)*

