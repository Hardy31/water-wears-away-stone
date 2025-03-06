char** calloc_matrix(int width, int height) {
    char** matrix = (char**) calloc(height + width * height, sizeof(char*));
    char* arrays = (char*) (matrix + height);
    for (int row = 0; row < height; row++) {
        matrix[row] = &arrays[row * width];
    }
    return matrix;
}