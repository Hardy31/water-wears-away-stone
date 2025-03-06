CC=gcc -Wall -Wextra -Werror -std=c11
BUILD=../build/

all: main list_test

main: dmanager_module.o door_functions.o
	$(CC) dmanager_module.o door_functions.o -o $(BUILD)Quest_1

list_test: list.c list_test.c
	$(CC) list.c list_test.c -o $(BUILD)Quest_2

dmanager_module.o: dmanager_module.c
	$(CC) -c dmanager_module.c -o dmanager_module.o

door_functions.o: door_functions.c
	$(CC) -c door_functions.c -o door_functions.o

clean:
	rm -rf *.o $(BUILD)Quest*