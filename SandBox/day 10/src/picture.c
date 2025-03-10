#include <stdio.h>  // Добавляем библиотеку IO
//#include <stdlib.h>

#define N 15
#define M 13

void transform(int *buf, int **matr, int n, int m);
void make_picture(int **picture, int n, int m);
void reset_picture(int **picture, int n, int m);
void output_picture(int **picture, int n, int m);

int main() {
    int picture_data[N][M];
    int *picture[N];
    transform(picture_data[N], picture, N, M);  // передаем массив указателей заданного размерного типа

    make_picture(picture, N, M);  // Добавляем размерность
    output_picture(picture, N, M);
    return 0;
}

void make_picture(int **picture, int n, int m) {
    /*int frame_w[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    int frame_h[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    int tree_trunk[] = {7, 7, 7, 7};
    int tree_foliage[] = {3, 3, 3, 3};
    int sun_data[6][5] = {{0, 6, 6, 6, 6}, {0, 0, 6, 6, 6}, {0, 0, 6, 6, 6},
                          {0, 6, 0, 0, 6}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}};*/

    reset_picture(picture, n, m);

    // int length_frame_w = sizeof(frame_w) / sizeof(frame_w[0]);
    // int length_frame_h = sizeof(frame_h) / sizeof(frame_h[0]);

    /*for (int i = 0; i < length_frame_w; i++) {
        picture[0][i] = frame_w[i];
    }*/
}

void reset_picture(int **picture, int n, int m) {  // Исправляем проходки по строками и столбцам
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            picture[i][j] = 0;
        }
    }
}

void transform(int *buf, int **matr, int n, int m) {
    for (int i = 0; i < n; i++) {
        matr[i] = buf + i * m;
    }
}

void output_picture(int **picture, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", picture[i][j]);
        }
        printf("\n");
    }
}
