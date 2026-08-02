// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

vector<vector<int>> readMatrix(int rows, int cols)
{
    vector<vector<int>> matrix(rows, vector<int>(cols));

    for (int i = 0; i < rows; i++)
    {
        cout << "Enter row " << i + 1 << ": ";
        for (int j = 0; j < cols; j++)
        {
            cin >> matrix[i][j];
        }
    }

    return matrix;
}

// Function to display a matrix
void displayMatrix(const vector<vector<int>>& matrix)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to transpose a matrix
vector<vector<int>> transpose(const vector<vector<int>>& matrix)
{
    int rows = matrix.size();
    int cols = matrix[0].size();

    vector<vector<int>> result(cols, vector<int>(rows));

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result[j][i] = matrix[i][j];
        }
    }

    return result;
}

// Function to add two matrices
vector<vector<int>> add(const vector<vector<int>>& matrix1,
                        const vector<vector<int>>& matrix2)
{
    int rows = matrix1.size();
    int cols = matrix1[0].size();

    vector<vector<int>> result(rows, vector<int>(cols));

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    return result;
}

// Function to multiply two matrices
vector<vector<int>> multiply(const vector<vector<int>>& matrix1,
                             const vector<vector<int>>& matrix2)
{
    int rows = matrix1.size();
    int cols = matrix2[0].size();
    int common = matrix2.size();

    vector<vector<int>> result(rows, vector<int>(cols, 0));

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            for (int k = 0; k < common; k++)
            {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    return result;
}

int main()
{
    // PART A
    cout << "PART A , Transpose" << endl;

    int rows, cols;

    cout << "Enter number of rows: ";
    cin >> rows;

    cout << "Enter number of columns: ";
    cin >> cols;

    vector<vector<int>> matrix = readMatrix(rows, cols);

    cout << "\nOriginal Matrix:" << endl;
    displayMatrix(matrix);

    cout << "\nTransposed Matrix:" << endl;
    displayMatrix(transpose(matrix));

    // PART B
    cout << "\nPART B , Add Two Matrices" << endl;

    cout << "Enter number of rows: ";
    cin >> rows;

    cout << "Enter number of columns: ";
    cin >> cols;

    cout << "Enter Matrix 1" << endl;
    vector<vector<int>> matrix1 = readMatrix(rows, cols);

    cout << "Enter Matrix 2" << endl;
    vector<vector<int>> matrix2 = readMatrix(rows, cols);

    cout << "\nResult:" << endl;
    displayMatrix(add(matrix1, matrix2));

    // PART C
    cout << "\nPART C , Multiply Two Matrices" << endl;

    int rows1, cols1, rows2, cols2;

    cout << "Rows of Matrix A: ";
    cin >> rows1;

    cout << "Columns of Matrix A: ";
    cin >> cols1;

    cout << "Enter Matrix A" << endl;
    vector<vector<int>> matrixA = readMatrix(rows1, cols1);

    cout << "Rows of Matrix B: ";
    cin >> rows2;

    cout << "Columns of Matrix B: ";
    cin >> cols2;

    if (cols1 != rows2)
    {
        cout << "Matrix multiplication not possible." << endl;
    }
    else
    {
        cout << "Enter Matrix B" << endl;
        vector<vector<int>> matrixB = readMatrix(rows2, cols2);

        cout << "\nProduct Matrix:" << endl;
        displayMatrix(multiply(matrixA, matrixB));
    }

    return 0;
}