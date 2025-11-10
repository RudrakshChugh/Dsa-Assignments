/*
A slightly improved selection sort – We know that selection sort algorithm takes the minimum on
every pass on the array, and place it at its correct position. The idea is to take also the maximum on
every pass and place it at its correct position. So in every pass, we keep track of both maximum and
minimum and array becomes sorted from both ends. Implement this logic.
*/

#include <bits/stdc++.h>
using namespace std;

void selectionSortImproved(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n / 2; i++)
    {
        int minIndex = i;
        int maxIndex = i;

        for (int j = i + 1; j < n - i; j++)
        {
            if (arr[j] < arr[minIndex])
                minIndex = j;
            if (arr[j] > arr[maxIndex])
                maxIndex = j;
        }

        swap(arr[i], arr[minIndex]);
        if (maxIndex == i)
            maxIndex = minIndex;
        swap(arr[n - i - 1], arr[maxIndex]);
    }
}

int main()
{
    vector<int> arr = {64, 25, 12, 22, 11, 90, 34, 78};
    int n = arr.size();

    cout << "Original array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    selectionSortImproved(arr);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}