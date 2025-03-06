#include "state_sort.h"

int main() {
    int flag = 0;
    int dd1, mm1, yy1, dd2, mm2, yy2;
    printf("Input filename (ex: ../datasets/door_state_1): ");
    char filename[256] = {};
    scanf("%s", filename);
    // while (yy2 < yy1) {
    printf("Input start and end date in format DD.MM.YYYY DD.MM.YYYY: ");
    while (flag != 1) {
        scanf("%2d.%2d.%4d", &dd1, &mm1, &yy1);
        if (dd1 < 0 || dd1 > 31) {
            flag = 0;
            printf("Day is out of range. Please try again.\n");
        } else if (mm1 < 0 || mm1 > 12) {
            flag = 0;
            printf("Month is out of range. Please try again.\n");
        } else if (yy1 < 0) {
            flag = 0;
            printf("Year is out of range. Please try again.\n");
        } else
            flag = 1;
    }
    flag = 0;
    while (flag != 1) {
        scanf("%2d.%2d.%4d", &dd2, &mm2, &yy2);
        if (dd2 < 0 || dd2 > 31) {
            flag = 0;
            printf("Day is out of range. Please try again.\n");
        } else if (mm2 < 0 || mm2 > 12) {
            flag = 0;
            printf("Month is out of range. Please try again.\n");
        } else if (yy2 < 0) {
            flag = 0;
            printf("Year is out of range. Please try again.\n");
        } else
            flag = 1;
    }
    // if (yy2 < yy1) printf("Start date have to be less than End date");
    // }
    // printf("%d.%d.%d\n", dd,mm,yy);

    FILE* file = fopen(filename, "rb");
    char cpy[256];
    strcpy(cpy, filename);
    char* filecopy = strcat(cpy, "_cp");
    printf("%s\n", filecopy);
    FILE* tmp = fopen(filecopy, "wb");
    if (file != NULL && tmp != NULL) {
        // sort_binary_file(filename);
        int len = get_records_count_in_file(file);
        int first_rec = 0, last_rec = 0;
        MyStruct line;
        for (int i = 0; i < len; i++) {
            line = read_record_from_file(file, i);
            if (line.year >= yy1 && line.month >= mm1 && line.day >= dd1) {
                first_rec = i;
                printf("F[%d]: %d %d %d\n", first_rec, line.year, line.month, line.day);
                break;
            }
        }
        fseek(file, 0, SEEK_SET);
        for (int i = len - 1; i >= 0; i--) {
            line = read_record_from_file(file, i);
            if (line.year <= yy2 && line.month <= mm2 && line.day <= dd2) {
                last_rec = i;
                printf("L[%d]: %d %d %d\n", last_rec, line.year, line.month, line.day);
                break;
            }
        }
        fseek(file, 0, SEEK_SET);
        for (int i = 0; i < len; i++) {
            if (i < first_rec || i > last_rec) {
                line = read_record_from_file(file, i);
                fwrite(&line, sizeof(struct my_struct), 1, tmp);
            }
        }

    } else
        printf("n/a\n");
    fclose(file);
    fclose(tmp);
    rename(filecopy, filename);
    return 0;
}