#ifndef STATE_SORT_H_
#define STATE_SORT_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct my_struct {
    int year, month, day, hour, minute, second, status, code;
} MyStruct;

/* STATE_SORT */
long date_to_int(int yy, int mm, int dd, int hh, int min, int ss);
void puts_to_binary_file(FILE *file, MyStruct *line);
void sort_binary_file(char *filename);
int output_binary_file(char *filename);
void menu();
int search_in_binary_file(FILE *filename, int yy, int mm, int dd);

/*FUNCTIONS */
struct my_struct read_record_from_file(FILE *pfile, int index);
void write_record_in_file(FILE *pfile, struct my_struct *record_to_write, int index);
void swap_records_in_file(FILE *pfile, int record_index1, int record_index2);
int get_file_size_in_bytes(FILE *pfile);
int get_records_count_in_file(FILE *pfile);

#endif