#include <iostream>
#include <vector>
using namespace std;

#define MAX_ELEMENTS 100  // Maximum number of non-zero elements + 1 for metadata

// Function to input a sparse matrix in triplet form
void inputSparseMatrix(vector<vector<int>> &matrix, int numElements, int rows, int cols)
{
    // Store metadata in the first row of the array
    matrix[0][0] = rows;        // Number of rows in matrix
    matrix[0][1] = cols;        // Number of columns in matrix
    matrix[0][2] = numElements; // Number of non-zero elements

    // Read non-zero elements from the user
    for (int i = 1; i <= numElements; i++)
    {
        cin >> matrix[i][0] >> matrix[i][1] >> matrix[i][2]; // row, column, value
    }
}

// Function to display a sparse matrix in triplet form
void displaySparseMatrix(vector<vector<int>> &matrix, int numElements)
{
    // Display matrix metadata
    cout << "Sparse Matrix (rows, cols, numElements): ("
         << matrix[0][0] << ", " << matrix[0][1] << ", " << matrix[0][2] << ")\n";

    // Display each non-zero element
    cout << "Sparse Matrix (row, col, value):\n";
    for (int i = 1; i <= numElements; i++)
    {
        if (matrix[i][2] != 0) // Only print non-zero elements
        {
            cout << "(" << matrix[i][0] << ", " << matrix[i][1] << ", " << matrix[i][2] << ")\n";
        }
    }
}

// Function to add two sparse matrices and print the result
void addSparseMatrix(vector<vector<int>> &A, int numElementsA, vector<vector<int>> &B, int numElementsB,
                     int rowsA, int colsA, int rowsB, int colsB)
{
    // Check if dimensions match; if not, addition is impossible
    if (rowsA != rowsB || colsA != colsB)
    {
        cout << "Matrix dimensions do not match for addition.\n";
        return;
    }

    // Result matrix initialization
    vector<vector<int>> result(MAX_ELEMENTS, vector<int>(3, 0));
    result[0][0] = rowsA; // Store rows
    result[0][1] = colsA; // Store columns
    result[0][2] = 0;     // Initialize number of non-zero elements

    int k = 1, i = 1, j = 1; // Indices for result, A, B respectively

    // Merge non-zero elements from A and B
    while (i <= numElementsA && j <= numElementsB && k < MAX_ELEMENTS)
    {
        // Case 1: Same row in both matrices
        if (A[i][0] == B[j][0])
        {
            // Subcase 1.1: Same column, add values
            if (A[i][1] == B[j][1])
            {
                result[k][0] = A[i][0];
                result[k][1] = A[i][1];
                result[k][2] = A[i][2] + B[j][2]; // Sum the values

                if (result[k][2] != 0)
                {
                    result[0][2]++; // Increment non-zero count
                    k++;
                }

                i++;
                j++;
            }
            // Subcase 1.2: Column in A comes first
            else if (A[i][1] < B[j][1])
            {
                result[k] = A[i];
                result[0][2]++;
                i++;
                k++;
            }
            // Subcase 1.3: Column in B comes first
            else
            {
                result[k] = B[j];
                result[0][2]++;
                j++;
                k++;
            }
        }
        // Case 2: Different rows, A's row comes first
        else if (A[i][0] < B[j][0])
        {
            result[k] = A[i];
            result[0][2]++;
            i++;
            k++;
        }
        // Case 3: Different rows, B's row comes first
        else
        {
            result[k] = B[j];
            result[0][2]++;
            j++;
            k++;
        }
    }

    // Copy any remaining elements from A
    while (i <= numElementsA && k < MAX_ELEMENTS)
    {
        result[k] = A[i];
        result[0][2]++;
        i++;
        k++;
    }

    // Copy any remaining elements from B
    while (j <= numElementsB && k < MAX_ELEMENTS)
    {
        result[k] = B[j];
        result[0][2]++;
        j++;
        k++;
    }

    // Display the result
    if (result[0][2] > 0)
    {
        cout << "\nSum of Matrix A and B:\n";
        displaySparseMatrix(result, result[0][2]);
    }
    else
    {
        cout << "\nSum of Matrix A and B: Empty matrix (all zeros).\n";
    }
}

int main()
{
    vector<vector<int>> A(MAX_ELEMENTS, vector<int>(3, 0)); // Matrix A storage
    vector<vector<int>> B(MAX_ELEMENTS, vector<int>(3, 0)); // Matrix B storage
    int rowsA, colsA, numElementsA, rowsB, colsB, numElementsB;

    // Input matrix A
    cout << "Enter rows, cols, and number of non-zero elements for Matrix A: " << endl;
    cin >> rowsA >> colsA >> numElementsA;
    inputSparseMatrix(A, numElementsA, rowsA, colsA);

    // Display matrix A
    cout << "Matrix A:" << endl;
    displaySparseMatrix(A, numElementsA);

    // Input matrix B
    cout << "\nEnter rows, cols, and number of non-zero elements for Matrix B: " << endl;
    cin >> rowsB >> colsB >> numElementsB;
    inputSparseMatrix(B, numElementsB, rowsB, colsB);

    // Display matrix B
    cout << "Matrix B:" << endl;
    displaySparseMatrix(B, numElementsB);

    // Add matrices
    addSparseMatrix(A, numElementsA, B, numElementsB, rowsA, colsA, rowsB, colsB);

    return 0;
}
