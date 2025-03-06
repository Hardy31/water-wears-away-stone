#include <math.h>
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define WIDTH 80
#define HEIGHT 25
#define CELL '*'
#define DEAD_CELL ' '
#define SPEED_INCREMENT 50000
#define SPEED_BASE 300000
#define MAXSPEED 600000

/* ------- Определения функций -------- */
char** init_matrix();
char** clone_matrix(char** matrix);
void clear_matrix(char** matrix);
void output_matrix(char** matrix);
void free_matrix(char** matrix);

char* read_start_stage(int stage);
void push_stage(char** matrix, const char* stage, int x, int y);

int count_neighbours(char** matrix, int cell_x, int cell_y);
int kill_birth(int count, int status);

void update(char** matrix, int stage);

// ГЛАВНЫЙ БЛОК
int main() {
    char** field = init_matrix();
    clear_matrix(field);
    char* stage = read_start_stage(1);
    push_stage(field, stage, 0, 0);
    free(stage);

    initscr();
    halfdelay(1);
    int keypress, speed = SPEED_BASE;
    while ((keypress = getch()) != 27) {
        switch (keypress) {
            case 49:
                update(field, 1);
                break;
            case 50:
                update(field, 2);
                break;
            case 51:
                update(field, 3);
                break;
            case 52:
                update(field, 4);
                break;
            case 53:
                update(field, 5);
                break;
            case 61:
                speed = speed - SPEED_INCREMENT;
                if (speed <= 0) speed = SPEED_INCREMENT;
                break;
            case 45:
                speed = speed + SPEED_INCREMENT;
                if (speed >= MAXSPEED) speed = MAXSPEED;
                break;
        }

        clear();
        output_matrix(field);
        char** newfield = clone_matrix(field);
        for (int y = 0; y < HEIGHT; y++)
            for (int x = 0; x < WIDTH; x++) {
                int count = count_neighbours(field, x, y);
                int status = 0;
                if (field[y][x] == CELL)
                    status = 1;
                else
                    status = 0;
                if (kill_birth(count, status) == 0)
                    newfield[y][x] = DEAD_CELL;
                else
                    newfield[y][x] = CELL;
            }
        free_matrix(field);
        field = clone_matrix(newfield);
        free_matrix(newfield);
        refresh();
        usleep(speed);
    }

    free_matrix(field);
    endwin();
    return 0;
}

/* ------- ИНТЕРАКТИВ ------- */

void update(char** matrix, int stage) {
    clear_matrix(matrix);
    char* str = read_start_stage(stage);
    push_stage(matrix, str, 0, 0);
    free(str);
}

/* ------- ЛОГИКА ------- */

char** clone_matrix(char** matrix) {  // ВЫДЕЛЯЕТСЯ ПАМЯТЬ!!! ОЧИСТИТЬ!!!
    char** newmatrix = init_matrix();
    for (int i = 0; i < HEIGHT; i++)
        for (int j = 0; j < WIDTH; j++) newmatrix[i][j] = matrix[i][j];
    return newmatrix;
}

int count_neighbours(char** matrix, int cell_x, int cell_y) {
    int count = 0;
    for (int y = cell_y - 1; y <= cell_y + 1; y++)
        for (int x = cell_x - 1; x <= cell_x + 1; x++) {
            if (x >= 0 && y >= 0 && x < WIDTH && y < HEIGHT)
                if ((x != cell_x || y != cell_y) && matrix[y][x] == CELL) count++;
        }
    return count;
}

int kill_birth(int count, int status) {
    if (count < 2 || count > 3) status = 0;
    if (count == 2 && status == 1) status = 1;
    if (count == 3) status = 1;
    return status;
}

/* ------- ФУНКЦИИ -------- */

char** init_matrix() {
    char** matrix = (char**)calloc(HEIGHT, sizeof(char*));
    if (matrix != NULL) {
        for (int i = 0; i < HEIGHT; i++) {
            matrix[i] = (char*)calloc(WIDTH, sizeof(char));
            if (matrix[i] == NULL) printf("Выделение памяти не удалось: Строка[%d]", i);
        }
    } else
        printf("Выделение памяти не удалось: [Указатели]");
    return matrix;
}

void output_matrix(char** matrix) {
    printw("Game of Life Automation\n");
    for (int i = 0; i < WIDTH; i++) printw("-");
    printw("\n");
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) printw("%c", matrix[i][j]);
        printw("\n");
    }
    for (int i = 0; i < WIDTH; i++) printw("-");
    printw("\nEsc - exit | 1-5 Levels| +/- Speed up/down\n");
}

void clear_matrix(char** matrix) {
    for (int i = 0; i < HEIGHT; i++)
        for (int j = 0; j < WIDTH; j++) matrix[i][j] = DEAD_CELL;
}

void free_matrix(char** matrix) {
    for (int i = 0; i < HEIGHT; i++) free(matrix[i]);
    free(matrix);
}

// -------- УСТАНОВКА НАЧАЛЬНОЙ СТАДИИ --------- //

char* read_start_stage(int stage) {
    char* stagefile;
    char* charArray;
    switch (stage) {
        case 1:
            stagefile = "stage1.txt";
            break;
        case 2:
            stagefile = "stage2.txt";
            break;
        case 3:
            stagefile = "stage3.txt";
            break;
        case 4:
            stagefile = "stage4.txt";
            break;
        case 5:
            stagefile = "stage5.txt";
            break;
    }
    FILE* file = fopen(stagefile, "r");
    if (file == NULL) {
        printf("Невозможно открыть файл.");
    } else {
        fseek(file, 0, SEEK_END);
        long fileSize = ftell(file);
        fseek(file, 0, SEEK_SET);
        charArray = (char*)malloc((fileSize + 1) * sizeof(char));
        if (charArray == NULL) {
            printf("Выделение памяти не удалось.");
        } else {
            fread(charArray, sizeof(char), fileSize, file);
            charArray[fileSize] = '\0';
            // printf("Content of the file:\n%s", charArray);
        }
        fclose(file);
    }
    return charArray;
}

void push_stage(char** matrix, const char* stage, int x, int y) {
    int i = 0, startx = x;
    while (stage[i] != '\0') {
        if (stage[i] != '\n') {
            if (x < WIDTH && y < HEIGHT && x >= 0 && y >= 0) matrix[y][x] = stage[i];
            x++;
        } else {
            y++;
            x = startx;
        }
        i++;
    }
}