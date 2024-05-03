#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

void generate_random_matrix(int rows, int cols, vector<vector<int>>& matrix) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 10;
        }
    }
}

vector<vector<int>> multiply_matrices(const vector<vector<int>>& matrix1, const vector<vector<int>>& matrix2) {
    int rows = matrix1.size();
    int cols = matrix2[0].size();
    int sharedDim = matrix2.size();

    vector<vector<int>> result(rows, vector<int>(cols, 0));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            for (int k = 0; k < sharedDim; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    return result;
}

int main() {
    srand(time(NULL));

    int rows, cols;
    cout << "Enter the number of rows and columns in the matrices: ";
    cin >> rows >> cols;

    vector<vector<int>> matrix1(rows, vector<int>(cols));
    vector<vector<int>> matrix2(rows, vector<int>(cols));
    generate_random_matrix(rows, cols, matrix1);
    generate_random_matrix(rows, cols, matrix2);

    clock_t start_time = clock();
    vector<vector<int>> result = multiply_matrices(matrix1, matrix2);
    clock_t end_time = clock();
    double duration = ((double)(end_time - start_time) / CLOCKS_PER_SEC) * 1000; 

    cout << "Time taken for matrix multiplication: " << duration << " milliseconds" << endl;

    return 0;
}