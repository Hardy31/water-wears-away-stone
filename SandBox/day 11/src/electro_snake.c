#include <stdio.h>
#include <stdlib.h>

void sort_vertical(int **matrix, int n, int m, int **result);
void sort_horizontal(int **matrix, int n, int m, int **result_matrix);
int input(int **matrix, int n, int m);
void output(int **matrix, int n, int m);
void output2(int **matrix, int n, int m);

int main()
{
    int **matrix, **result;
    int n,m;
    float fn, fm;

    if (scanf("%f", &fn) && fn == (int)fn && fn > 0) {
        if (scanf("%f", &fm) && fm == (int)fm && fm > 0) {

            n = (int)fn; m= (int)fm;
            // Выделяем память под исходный массив
            matrix = (int**) malloc(n*sizeof(int*) + n*m*sizeof(int));
            for (int i=0; i<m; i++) matrix[i] = (int*) (matrix + n + i*m);
            // Выделяем память под массив результатов
            if (matrix != NULL) {
                result = (int**) malloc(n*sizeof(int*) + m*n*sizeof(int));
                for (int i=0; i<m; i++) result[i] = (int*) (result + n + i*m);
            }

            if (input(matrix, n, m)) {
                //output(matrix, n, m);
                sort_vertical(matrix, n, m, result);
                output(result,n,m);
                /*sort_horizontal(matrix, n, m, result);
                output(result);*/
            free(matrix);
            free(result);
            } else printf("n/a");
        } else printf ("n/a");
    } else printf ("n/a");
    return 0;
}

/* ---------------------------------- */
/*
1 3 2 4 5
6 7 8 9 10
11 12 13 14 15
16 17 18 19 20 

    1 8 9 16 17
    3 7 10 15 18
    2 6 11 14 19
    4 5 12 13 20
*/
void sort_vertical(int **matrix, int n, int m, int **result) {
    int arr[n*m];
    int arri=0;
    for (int i=0; i<n; i++)
        for (int k=0; k<m; k++) {
            arr[arri] = matrix[i][k];
            arri++;
        }
        arri=0;
    for (int i=0; i<n; i++)
        for (int k=0; k<m; k++) {
            result[i][k]=arr[arri];
            arri++;
        }
}
/*
    1 2 3
    6 5 4
    7 8 9
*/
void sort_horizontal(int **matrix, int n, int m, int **result_matrix) {

}

/* ---------------------------------- */

int input(int **matrix, int n, int m) {
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            float element;
            if (!scanf("%f", &element) || element != (int)element) return 0; else matrix[i][j] = (int)element;
        }
    }
    return 1;
}

void output(int **matrix, int n, int m) {
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            printf("%d", matrix[i][j]);
            if (j<m-1) printf(" ");
        }
        if (i<n-1) printf("\n");
    }
}

void output2(int **result, int n, int m) {
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            printf("%d", result[i][j]);
            if (j<m-1) printf(" ");
        }
        if (i<n-1) printf("\n");
    }
}
