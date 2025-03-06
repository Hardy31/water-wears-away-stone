#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* read_file_to_string(char* filename);
int append_to_file(char* charArray, char* filename);
int string_output(char* charArray);
void input_string(char* input);
void menu();
void encoding_caesar(char* encode, int offset);

int main() {
    int var;
    char file_open[256];
    char* charString = NULL;
    menu();
    do {
        while (scanf("%d", &var) != 1) {
            fflush(stdin);
            menu();
        }
        if (var == 1) {
            printf("Input filename: ");
            if (scanf("%s", file_open) == 1) {
                if ((charString = read_file_to_string(file_open)) != NULL)
                    if (string_output(charString)) {
                    } else
                        printf("n/a\n");
                else
                    printf("n/a\n");
            }
            free(charString);
        } else if (var == 2) {
            char input[256] = {};
            printf("Input append string to [%s]: ", file_open);
            input_string(input);
            append_to_file(input, file_open);
            if ((charString = read_file_to_string(file_open)) != NULL)
                if (string_output(charString)) {
                } else
                    printf("n/a\n");
            else
                printf("n/a\n");
            free(charString);
        } else if (var == 3) {
            system("ls -1 ../src/encoding/*.c > ls.txt");
            FILE* file = fopen("ls.txt", "r");
            char filename[256] = {};

            while (fgets(filename, 256, file) != NULL) {
                for (long unsigned int i = 0; i < strlen(filename); i++)
                    if (filename[i] == '\n') filename[i] = 0;
                char* encstring = read_file_to_string(filename);
                encoding_caesar(encstring, 3);
                printf("%s", encstring);
                free(encstring);
            }
        }
        fflush(stdin);
    } while (var != -1);

    free(charString);
    return 0;
}

/* FUNCTIONS */
void encoding_caesar(char* encode, int offset) {
    const int alphabet = 26;
    for (; *encode != '\0' || *encode != EOF; encode++) {
        if (*encode >= 'a' && *encode <= 'z') {
            *encode = *encode - 'a';
            *encode = (*encode + offset + alphabet) % alphabet;
            *encode = *encode + 'a';
        }
        if (*encode >= 'A' && *encode <= 'Z') {
            *encode = *encode - 'A';
            *encode = (*encode + offset + alphabet) % alphabet;
            *encode = *encode + 'A';
        }
        printf("%c", *encode);
    }
}

int append_to_file(char* charArray, char* filename) {
    FILE* file = fopen(filename, "a");
    if (file == NULL) {
        return 0;
    } else {
        fprintf(file, "%s", charArray);
    }
    fclose(file);
    return 1;
}

char* read_file_to_string(char* filename) {
    char* charArray;
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        return NULL;
    } else {
        fseek(file, 0, SEEK_END);
        long fileSize = ftell(file);
        fseek(file, 0, SEEK_SET);
        charArray = (char*)malloc((fileSize + 1) * sizeof(char));
        if (charArray == NULL) {
            printf("Memory allocation is failed\n");
        } else {
            fread(charArray, sizeof(char), fileSize, file);
            charArray[fileSize] = '\0';
        }
    }
    fclose(file);
    return charArray;
}

int string_output(char* charArray) {
    if (strlen(charArray) != 0 && charArray != NULL) {
        printf("%s", charArray);
        printf("\n");
    } else {
        return 0;
    }
    return 1;
}

void input_string(char* input) {
    fflush(stdin);
    while ((*input = getchar()) != '\n') input++;
}

void menu() {
    system("clear");
    printf("Read File: 1\nAppend to file: 2\nEncoding: 3\nExit: -1\n");
}