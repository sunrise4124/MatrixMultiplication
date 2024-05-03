#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generate_random_matrix(int rows, int cols, int **matrix) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 10; 
        }
    }
}

void multiply_matrices(int rows, int cols, int **matrix1, int **matrix2, int **result) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            for (int k = 0; k < cols; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

int main() {
    srand(time(NULL)); 

    int rows, cols;
    printf("Enter the number of rows and columns in the matrices: ");
    scanf("%d %d", &rows, &cols);

    int **matrix1 = (int **)malloc(rows * sizeof(int *));
    int **matrix2 = (int **)malloc(rows * sizeof(int *));
    int **result = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix1[i] = (int *)malloc(cols * sizeof(int));
        matrix2[i] = (int *)malloc(cols * sizeof(int));
        result[i] = (int *)calloc(cols, sizeof(int)); 
    }

    generate_random_matrix(rows, cols, matrix1);
    generate_random_matrix(rows, cols, matrix2);

    clock_t start_time = clock();
    multiply_matrices(rows, cols, matrix1, matrix2, result);
    clock_t end_time = clock();
    double duration = ((double)(end_time - start_time) / CLOCKS_PER_SEC) * 1000; 

    printf("Time taken for matrix multiplication: %.2f milliseconds\n", duration);

    for (int i = 0; i < rows; i++) {
        free(matrix1[i]);
        free(matrix2[i]);
        free(result[i]);
    }
    free(matrix1);
    free(matrix2);
    free(result);

    return 0;
}
