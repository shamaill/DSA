#include <iostream>
using namespace std;

int hoarePartition(int arr[], int low, int high)
{
    int pivot = arr[low], i = low - 1, j = high + 1;
    while (true)
    {
        do
        {
            i++;
        } while (arr[i] < pivot);
        do
        {
            j--;
        } while (arr[j] > pivot);
        if (i >= j)
            return j;
        swap(arr[i], arr[j]);
    }
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = hoarePartition(arr, low, high);
        quickSort(arr, low, pi);
        quickSort(arr, pi + 1, high);
    }
}

int main()
{
    int arr[] = {30, 20, 50, 40, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}
