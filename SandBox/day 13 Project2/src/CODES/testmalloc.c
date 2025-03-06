#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows, columns;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    printf("Enter the number of columns: ");
    scanf("%d", &columns);

    // Dynamically allocate memory for the matrix
    char** matrix = (char**)malloc(rows * sizeof(char*));

    if (matrix == NULL) {
        printf("Memory allocation failed.");
        return 1;
    }

    // Dynamically allocate memory for each row of the matrix
    for (int i = 0; i < rows; i++) {
        matrix[i] = (char*)malloc(columns * sizeof(char));
        if (matrix[i] == NULL) {
            printf("Memory allocation failed.");
            return 1;
        }
    }

    // Fill the matrix with characters
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            matrix[i][j] = 'A' + (i * columns + j) % 26; // Filling with alphabets
        }
    }

    // Print the matrix
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("%c ", matrix[i][j]);
        }
        printf("\n");
    }

    // Free the memory allocated for the matrix
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}