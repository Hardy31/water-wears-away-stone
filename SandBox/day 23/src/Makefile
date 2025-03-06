CC=gcc
CFLAGS=-Wall -Werror -Wextra -std=c11
BUILD=../build/

all: state_sort state_search clear_state

state_sort: state_sort.c functions.c myfunc.c
	$(CC) $(CFLAGS) state_sort.c functions.c myfunc.c -o $(BUILD)Quest_1

state_search: state_search.c myfunc.c functions.c
	$(CC) $(CFLAGS) state_search.c myfunc.c functions.c -o $(BUILD)Quest_2

clear_state: clear_state.c myfunc.c functions.c
	$(CC) $(CFLAGS) clear_state.c myfunc.c functions.c -o $(BUILD)Quest_3

clean:
	rm -rf $(BUILD)Quest*

rebuild: clean all