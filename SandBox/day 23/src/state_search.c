#include "state_sort.h"

int main() {
    int flag = 0;
    int dd, mm, yy;
    printf("Input filename (ex: ../datasets/door_state_1): ");
    char filename[256] = {};
    scanf("%s", filename);
    printf("Input date in format DD.MM.YYYY: ");
    while (flag != 1) {
        scanf("%2d.%2d.%4d", &dd, &mm, &yy);
        if (dd < 0 || dd > 31) {
            flag = 0;
            printf("Day is out of range. Please try again.\n");
        } else if (mm < 0 || mm > 12) {
            flag = 0;
            printf("Month is out of range. Please try again.\n");
        } else if (yy < 0) {
            flag = 0;
            printf("Year is out of range. Please try again.\n");
        } else
            flag = 1;
    }
    // printf("%d.%d.%d\n", dd,mm,yy);

    FILE* file = fopen(filename, "rb");
    if (file != NULL) {
        int code = search_in_binary_file(file, yy, mm, dd);
        if (code != -1)
            printf("%d", code);
        else
            printf("n/a\n");
    } else
        printf("n/a\n");
    fclose(file);
    return 0;
}
