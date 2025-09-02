#include <iostream>
#include <vector>
using namespace std;

#define MAX_ELEMENTS 100  // Maximum non-zero elements + 1 for metadata

// Function to input sparse matrix elements
void inputSparseMatrix(vector<vector<int>>& matrix, int numElements, int rows, int cols) {
    matrix[0][0] = rows;        // Store number of rows
    matrix[0][1] = cols;        // Store number of columns
    matrix[0][2] = numElements; // Store number of non-zero elements

    cout << "Enter row, column, and value for each non-zero element (sorted by row, then column):" << endl;
    for (int i = 1; i <= numElements; i++) {
        cout << "Element " << i << ": ";
        cin >> matrix[i][0] >> matrix[i][1] >> matrix[i][2];

        // Check for valid row and column indices
        if (matrix[i][0] >= rows || matrix[i][1] >= cols) {
            cout << "Invalid row or column index. Please re-enter this element." << endl;
            i--; // Retry the same element
        }
    }
}

// Function to display sparse matrix
void displaySparseMatrix(const vector<vector<int>>& matrix, int numElements) {
    cout << "Sparse Matrix (rows, cols, numElements): ("
         << matrix[0][0] << ", " << matrix[0][1] << ", " << matrix[0][2] << ")" << endl;
    cout << "Sparse Matrix (row, col, value):" << endl;
    for (int i = 1; i <= numElements; i++) {
        if (matrix[i][2] != 0) {
            cout << "(" << matrix[i][0] << ", " << matrix[i][1] << ", " << matrix[i][2] << ")" << endl;
        }
    }
}

// Function to transpose a sparse matrix
void transposeSparseMatrix(const vector<vector<int>>& A, vector<vector<int>>& result, int numElements) {
    int rows = A[0][1];  // Rows of transpose = columns of original
    int cols = A[0][0];  // Columns of transpose = rows of original
    result[0][0] = rows;
    result[0][1] = cols;
    result[0][2] = 0;    // Initialize number of non-zero elements in transpose

    int k = 1; // Index for result

    // Scan through all column indices of original matrix
    for (int col = 0; col < cols; col++) {
        for (int i = 1; i <= numElements; i++) {
            if (A[i][1] == col) {
                result[k][0] = A[i][1]; // Transpose row = original column
                result[k][1] = A[i][0]; // Transpose column = original row
                result[k][2] = A[i][2]; // Value remains the same
                result[0][2]++;         // Increment non-zero count
                k++;
            }
        }
    }
}

int main() {
    vector<vector<int>> A(MAX_ELEMENTS, vector<int>(3, 0));
    vector<vector<int>> transpose(MAX_ELEMENTS, vector<int>(3, 0));
    int rows, cols, numElements;

    // Input matrix dimensions and number of non-zero elements
    cout << "Enter number of rows, columns, and non-zero elements: ";
    cin >> rows >> cols >> numElements;

    if (rows <= 0 || cols <= 0 || numElements < 0 || numElements > MAX_ELEMENTS - 1) {
        cout << "Invalid dimensions or number of elements." << endl;
        return 1;
    }

    // Input sparse matrix
    inputSparseMatrix(A, numElements, rows, cols);

    // Display original matrix
    cout << "\nOriginal Matrix:" << endl;
    displaySparseMatrix(A, numElements);

    // Compute transpose
    transposeSparseMatrix(A, transpose, numElements);

    // Display transposed matrix
    cout << "\nTransposed Matrix:" << endl;
    displaySparseMatrix(transpose, transpose[0][2]);

    return 0;
}
