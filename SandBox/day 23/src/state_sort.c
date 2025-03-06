#include "state_sort.h"

int input_validation(char* input_string, MyStruct* line);

int main() {
    menu();
    char filename[256] = {};
    int scanstatus, select, outflag = 0;
    printf("Input filename (ex: ../datasets/door_state_1): ");
    scanf("%s", filename);
    printf("Input menu choise (1-3): ");
    scanstatus = scanf("%d", &select);
    if (scanstatus == 1 && select == 1) {
        if (output_binary_file(filename)) outflag = 1;
    }
    if (scanstatus == 1 && select == 2) {
        sort_binary_file(filename);
        if (output_binary_file(filename)) outflag = 1;
    }
    if (scanstatus == 1 && select == 3) {
        printf("Input new string in format YYYY MM DD hh mm ss i CCC: ");
        FILE* file = fopen(filename, "r+b");
        if (file != NULL) {
            char input_string[26];
            int ifcorrect = 0;
            MyStruct appline;
            while (ifcorrect != 18) {
                rewind(stdin);
                fgets(input_string, 26, stdin);
                if ((ifcorrect = input_validation(input_string, &appline)) != 18)
                    printf("Incorrect input. Please try again\n");
                else
                    write_record_in_file(file, &appline, get_records_count_in_file(file));
            }
            sort_binary_file(filename);
            if (output_binary_file(filename)) outflag = 1;
            outflag = 1;
        }
        fclose(file);
    }
    if (outflag == 0) printf("n/a\n");
    return 0;
}

int input_validation(char* input_string, MyStruct* line) {
    int correctcount = 0;
    int newdata[8] = {};
    int i = 0;
    for (int i = 0; i < 26; i++) {
        if (input_string[i] != ' ') {
            if (input_string[i] >= '0' && input_string[i] <= '9') correctcount++;
        }
    }
    char tok[10] = " ";
    char* istr;
    istr = strtok(input_string, tok);
    while (istr != NULL) {
        newdata[i] = atoi(istr);
        // printf("%d ", newdata[i]);
        i++;
        istr = strtok(NULL, tok);
    }
    if (newdata[0] < 0) {
        correctcount = 0;
    } else {
        line->year = newdata[0];
    }
    if (newdata[1] < 0 || newdata[1] > 12) {
        correctcount = 0;
    } else {
        line->month = newdata[1];
    }
    if (newdata[2] < 0 || newdata[2] > 31) {
        correctcount = 0;
    } else {
        line->day = newdata[2];
    }
    if (newdata[3] < 0 || newdata[3] > 23) {
        correctcount = 0;
    } else {
        line->hour = newdata[3];
    }
    if (newdata[4] < 0 || newdata[4] > 59) {
        correctcount = 0;
    } else {
        line->minute = newdata[4];
    }
    if (newdata[5] < 0 || newdata[5] > 59) {
        correctcount = 0;
    } else {
        line->second = newdata[5];
    }
    if (newdata[6] != 0 && newdata[6] != 1) {
        correctcount = 0;
    } else {
        line->status = newdata[6];
    }
    if (newdata[7] < 0 || newdata[7] > 999) {
        correctcount = 0;
    } else {
        line->code = newdata[7];
    }

    return correctcount;
}
