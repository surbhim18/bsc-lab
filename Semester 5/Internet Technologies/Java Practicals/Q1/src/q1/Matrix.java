package q1;

import java.util.Scanner;

/**
 *
 * @author surbhi
 */
public class Matrix {

    private int[][] mat;
    private int rows;
    private int cols;

    public Matrix(int m, int n) {
        rows = m;
        cols = n;

        mat = new int[rows][cols];
    }

    public void enter() {

        Scanner ob = new Scanner(System.in);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                System.out.print("Enter [" + i + "][" + j + "]: ");
                mat[i][j] = ob.nextInt();
            }
        }
    }

    private boolean checkCompatibility(Matrix m, char operation) {

        if (operation == '+' || operation == '-') {
            if (rows == m.rows && cols == m.cols) {
                return true;
            }
        } else if (operation == '*') {
            if (cols == m.rows) {
                return true;
            }
        }
        return false;
    }

    @Override
    public String toString() {

        String matrix = new String();

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                matrix = matrix + mat[i][j] + " ";
            }
            matrix = matrix + "\n";
        }
        return matrix;
    }

    public void display() {

        System.out.print(toString());
    }

    public Matrix add(Matrix m) throws MyException {

        if (checkCompatibility(m, '+') == true) {

            Matrix res = new Matrix(rows, cols);
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    res.mat[i][j] = mat[i][j] + m.mat[i][j];
                }
            }
            return res;

        } else {
            throw new MyException("The matricies are not compatible for addition.");
        }
    }

    public Matrix subtract(Matrix m) throws MyException {

        if (checkCompatibility(m, '-') == true) {

            Matrix res = new Matrix(rows, cols);
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    res.mat[i][j] = mat[i][j] - m.mat[i][j];
                }
            }
            return res;

        } else {
            throw new MyException("The matricies are not compatible for subtraction.");
        }
    }

    public Matrix multiply(Matrix m) throws MyException {

        if (checkCompatibility(m, '*') == true) {

            Matrix res = new Matrix(rows, m.cols);
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < m.cols; j++) {
                    res.mat[i][j] = 0;
                    for (int k = 0; k < cols; k++) {
                        res.mat[i][j] += mat[i][k] * m.mat[k][j];
                    }
                }
            }
            return res;

        } else {
            throw new MyException("The matricies are not compatible for multiplication.");
        }
    }

    public Matrix transpose() {

        Matrix res = new Matrix(cols, rows);

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                res.mat[i][j] = mat[j][i];
            }
        }
        return res;
    }
}
