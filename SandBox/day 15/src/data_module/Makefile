all: data_module

clean:
	rm -rf *.o data_module

data_module_entry.o: data_module_entry.c
	gcc -Wall -Werror -Wextra -c data_module_entry.c

data_process.o: data_process.c
	gcc -Wall -Werror -Wextra -c data_process.c

data_io.o: ../data_libs/data_io.c
	gcc -Wall -Werror -Wextra -c ../data_libs/data_io.c

data_stat.o: ../data_libs/data_stat.c
	gcc -Wall -Werror -Wextra -c ../data_libs/data_stat.c

data_module: data_module_entry.o data_process.o data_io.o data_stat.o
	gcc data_module_entry.o data_process.o data_io.o data_stat.o -o data_module.out