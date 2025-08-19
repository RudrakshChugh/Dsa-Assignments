#include <iostream>
#include <vector>

using namespace std;

#define N 5

int main()
{
    int i, j, k;

    int diagonal_size = N;
    vector<int> diagonal_array(diagonal_size);

    cout << "Enter " << diagonal_size << " elements for a diagonal matrix:" << endl;
    for (i = 0; i < diagonal_size; i++)
    {
        cin >> diagonal_array[i];
    }
    cout << "The diagonal matrix is:" << endl;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (i == j)
            {
                cout << diagonal_array[i] << " ";
            }
            else
            {
                cout << "0 ";
            }
        }
        cout << endl;
    }
    cout << endl;

    int tridiagonal_size = 3 * N - 2;
    vector<int> tridiagonal_array(tridiagonal_size);

    cout << "Enter " << tridiagonal_size << " elements for a tri-diagonal matrix:" << endl;
    for (i = 0; i < tridiagonal_size; i++)
    {
        cin >> tridiagonal_array[i];
    }
    cout << "The tri-diagonal matrix is:" << endl;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (i - j == 1)
            { // Upper diagonal
                cout << tridiagonal_array[i - 1] << " ";
            }
            else if (i - j == 0)
            { // Main diagonal
                cout << tridiagonal_array[N - 1 + i] << " ";
            }
            else if (i - j == -1)
            { // Lower diagonal
                cout << tridiagonal_array[2 * N - 2 + i] << " ";
            }
            else
            {
                cout << "0 ";
            }
        }
        cout << endl;
    }
    cout << endl;

    int lower_size = N * (N + 1) / 2;
    vector<int> lower_array(lower_size);

    cout << "Enter " << lower_size << " elements for a lower triangular matrix:" << endl;
    for (i = 0; i < lower_size; i++)
    {
        cin >> lower_array[i];
    }
    cout << "The lower triangular matrix is:" << endl;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (i >= j)
            {
                k = i * (i + 1) / 2 + j;
                cout << lower_array[k] << " ";
            }
            else
            {
                cout << "0 ";
            }
        }
        cout << endl;
    }
    cout << endl;

    int upper_size = N * (N + 1) / 2;
    vector<int> upper_array(upper_size);

    cout << "Enter " << upper_size << " elements for an upper triangular matrix:" << endl;
    for (i = 0; i < upper_size; i++)
    {
        cin >> upper_array[i];
    }
    cout << "The upper triangular matrix is:" << endl;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (i <= j)
            {
                k = (i * N) - (i * (i + 1) / 2) + (j - i);
                cout << upper_array[k] << " ";
            }
            else
            {
                cout << "0 ";
            }
        }
        cout << endl;
    }
    cout << endl;

    int symmetric_size = N * (N + 1) / 2;
    vector<int> symmetric_array(symmetric_size);

    cout << "Enter " << symmetric_size << " elements for a symmetric matrix (upper part):" << endl;
    for (i = 0; i < symmetric_size; i++)
    {
        cin >> symmetric_array[i];
    }
    cout << "The symmetric matrix is:" << endl;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (i <= j)
            {
                k = (i * N) - (i * (i + 1) / 2) + (j - i);
                cout << symmetric_array[k] << " ";
            }
            else
            {
                k = (j * N) - (j * (j + 1) / 2) + (i - j);
                cout << symmetric_array[k] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}

/*
Enter 5 elements for a diagonal matrix:
1 6 5 4 3
The diagonal matrix is:
1 0 0 0 0
0 6 0 0 0
0 0 5 0 0
0 0 0 4 0
0 0 0 0 3

Enter 13 elements for a tri-diagonal matrix:
1 2 3 4 5 6 7 8 9 1 2 3 4
The tri-diagonal matrix is:
5 9 0 0 0
1 6 1 0 0
0 2 7 2 0
0 0 3 8 3
0 0 0 4 9

Enter 15 elements for a lower triangular matrix:
 1 2 3 4 5 6 7 8 9 1 2 3 4 5 6
The lower triangular matrix is:
1 0 0 0 0
2 3 0 0 0
4 5 6 0 0
7 8 9 1 0
2 3 4 5 6

Enter 15 elements for an upper triangular matrix:
1 2 3 4 5 6 7 8 9 1 2 3 4 5 6
The upper triangular matrix is:
1 2 3 4 5
0 5 6 7 8
0 0 8 9 1
0 0 0 1 2
0 0 0 0 2

Enter 15 elements for a symmetric matrix (upper part):
1 2 3 4 5 6 7 8 9 1 2 3 4 5 6
The symmetric matrix is:
1 2 3 4 5
2 5 6 7 8
3 6 8 9 1
4 7 9 1 2
5 8 1 2 2
*/