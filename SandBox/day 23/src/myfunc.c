#include "state_sort.h"

/* MY FUNCTIONS */
void sort_binary_file(char* filename) {
    MyStruct line1, line2;
    long ts1, ts2;
    FILE* file = fopen(filename, "r+b");
    if (file != NULL) {
        int len = get_records_count_in_file(file);
        for (int i = len - 1; i >= 0; i--) {
            for (int j = i; j < len; j++) {
                line1 = read_record_from_file(file, j);
                line2 = read_record_from_file(file, j + 1);
                ts1 = date_to_int(line1.year, line1.month, line1.day, line1.hour, line1.minute, line1.second);
                ts2 = date_to_int(line2.year, line2.month, line2.day, line2.hour, line2.minute, line2.second);
                if (ts1 > ts2) {
                    swap_records_in_file(file, j, j + 1);
                }
            }
        }
    }
    fclose(file);
}

int output_binary_file(char* filename) {
    MyStruct line;
    int flag = 0;
    FILE* file = fopen(filename, "rb");
    if (file != NULL) {
        for (int i = 0; i < get_records_count_in_file(file); i++) {
            line = read_record_from_file(file, i);
            printf("[%i] %d %d %d %d %d %d %d %d\n", i, line.year, line.month, line.day, line.hour,
                   line.minute, line.second, line.status, line.code);
        }
        flag = 1;
    }
    fclose(file);
    return flag;
}

void menu() {
    printf("\033[2J");   /* Clear */
    printf("\033[0;0f"); /* Move cursor to the top left hand corner */
    printf("File output: 1\nFile sort & output: 2\nFile append + sort & output: 3\n---------------\n");
}

long date_to_int(int yy, int mm, int dd, int hh, int min, int ss) {
    long datestamp = 0;
    datestamp = ss + min * 100 + hh * 10000 + dd * 1000000 + mm * 100000000 + yy * 10000000000;
    return datestamp;
}

void puts_to_binary_file(FILE* file, MyStruct* line) {
    char* c = (char*)line;
    for (long unsigned i = 0; i < sizeof(struct my_struct); i++) {
        putc(*c++, file);
    }
}

int search_in_binary_file(FILE* filename, int yy, int mm, int dd) {
    int rtn = -1;
    for (int i = 0; i < get_records_count_in_file(filename); i++) {
        MyStruct line = read_record_from_file(filename, i);
        if (line.year == yy && line.month == mm && line.day == dd) {
            rtn = line.code;
            break;
        }
    }
    return rtn;
}