#include <iostream>
using namespace std;

int Linear(const int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] != i + 1)
            return i + 1;
    }
    return n;
}

int BinarySearch(const int arr[], int n)
{
    int low = 0, high = n - 2;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == mid + 1)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low + 1;
}

int main()
{
    int arr[] = {1, 2, 3, 5, 6};
    int n = 6;

    cout << "Linear: Missing number is " << Linear(arr, n) << endl;
    cout << "Binary Search: Missing number is " << BinarySearch(arr, n) << endl;

    return 0;
}
