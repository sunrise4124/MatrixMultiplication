import java.util.Random;
import java.util.Scanner;

public class MatrixMultiplication {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Random random = new Random();

        System.out.print("Enter the number of rows: ");
        int mRows = scanner.nextInt();
        System.out.print("Enter the number of columns: ");
        int mCols = scanner.nextInt();

        int[][] matrix1 = generateRandomMatrix(mRows, mCols, random);
        int[][] matrix2 = generateRandomMatrix(mRows, mCols, random);

        long startTime = System.currentTimeMillis();
        multiplyMatrices(matrix1, matrix2);
        long endTime = System.currentTimeMillis();
        long duration = endTime - startTime;
        System.out.println("Time taken for matrix multiplication: " + duration + " milliseconds");

        scanner.close();
    }

    public static int[][] generateRandomMatrix(int rows, int cols, Random random) {
        int[][] matrix = new int[rows][cols];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                matrix[i][j] = random.nextInt(10);
            }
        }
        return matrix;
    }

    public static int[][] multiplyMatrices(int[][] matrix1, int[][] matrix2) {
        int m1Rows = matrix1.length;
        int m1Cols = matrix1[0].length;
        int m2Cols = matrix2[0].length;

        int[][] result = new int[m1Rows][m2Cols];
        for (int i = 0; i < m1Rows; i++) {
            for (int j = 0; j < m2Cols; j++) {
                for (int k = 0; k < m1Cols; k++) {
                    result[i][j] += matrix1[i][k] * matrix2[k][j];
                }
            }
        }
        return result;
    }
}

