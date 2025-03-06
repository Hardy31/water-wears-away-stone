all: yadm

yadm: yet_another_decision_module_entry.o decision.o data_stat.o data_io.o
	gcc yet_another_decision_module_entry.o decision.o data_stat.o data_io.o -o yadm.out

yet_another_decision_module_entry.o: yet_another_decision_module_entry.c
	gcc -Wall -Werror -Wextra -std=c11 -c yet_another_decision_module_entry.c

decision.o: decision.c
	gcc -Wall -Werror -Wextra -std=c11 -c decision.c

data_stat.o: ../data_libs/data_stat.c
	gcc -Wall -Werror -Wextra -std=c11 -c ../data_libs/data_stat.c

data_io.o: ../data_libs/data_io.c
	gcc -Wall -Werror -Wextra -std=c11 -c ../data_libs/data_io.c

clean:
	rm -rf *.o yadm