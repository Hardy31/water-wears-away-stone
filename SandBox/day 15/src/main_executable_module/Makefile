CC=gcc
FLAGS=-Wall -Werror -Wextra -std=c11
YET=../yet_another_decision_module/
DATA=../data_module/
LIBS=../data_libs/
BUILD=../../build/

all: main

build: main

main: main_executable_module.o data_process.o decision.o data_stat.o data_io.o
	$(CC) $(FLAGS) main_executable_module.o data_process.o decision.o data_stat.o data_io.o -o $(BUILD)Quest_3

build_with_macro: main_executable_module_macros.o data_process.o decision.o data_stat.o
	$(CC) $(FLAGS) main_executable_module_macros.o data_process.o decision.o data_stat.o -o $(BUILD)Quest_4

build_with_static: main_executable_module.o data_process.o decision.o data_stat.o data_io.o libdata_stat.a
	$(CC) $(FLAGS) main_executable_module.o data_process.o decision.o data_stat.o data_io.o -L$(LIBS) -ldata_stat -o $(BUILD)Quest_5

build_with_dynamic: main_executable_module.o decision.o data_io.o libdata_process_dynamic.so
	$(CC) $(FLAGS) main_executable_module.o decision.o data_io.o -L. -ldata_process_dynamic -Wl,-rpath,. -o $(BUILD)Quest_6

decision.o: $(YET)decision.c
	$(CC) $(FLAGS) -c $(YET)decision.c

data_process.o: $(DATA)data_process.c
	$(CC) $(FLAGS)  -c $(DATA)data_process.c

data_stat.o: $(LIBS)data_stat.c
	$(CC) $(FLAGS)  -c $(LIBS)data_stat.c -o data_stat.o

data_io.o: $(LIBS)data_io.c
	$(CC) $(FLAGS)  -c $(LIBS)data_io.c

main_executable_module.o: main_executable_module.c
	$(CC) $(FLAGS) -c main_executable_module.c

main_executable_module_macros.o: main_executable_module.c
	$(CC) $(FLAGS) -c -DMACROS main_executable_module.c -o main_executable_module_macros.o

libdata_stat.a: data_stat.o
	ar rc $(LIBS)libdata_stat.a data_stat.o

data_process_dynamic.o: $(DATA)data_process.c data_stat.o
	$(CC) $(FLAGS) -fPIC -c $(DATA)data_process.c -o data_process_dynamic.o
	$(CC) $(FLAGS) -fPIC -c $(LIBS)data_stat.c -o data_stat.o

libdata_process_dynamic.so: data_process_dynamic.o data_stat.o
	$(CC) $(FLAGS) -shared data_process_dynamic.o data_stat.o -o libdata_process_dynamic.so
	$(CC) $(FLAGS) -shared data_process_dynamic.o data_stat.o -o $(BUILD)libdata_process_dynamic.so	

clean:
	rm -rf *.o *.so $(BUILD)Quest* $(BUILD)*.so $(LIBS)*.a

rebuild: clean build
