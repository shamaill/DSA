#include <iostream>
using namespace std;

void insertionSort(int arr[], int n)
{
    int swaps = 0;
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
            swaps++;
        }
        arr[j + 1] = key;
    }
    cout << "Total swaps: " << swaps << endl;
}

int main()
{
    int arr[] = {8, 4, 3, 7, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    insertionSort(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}
