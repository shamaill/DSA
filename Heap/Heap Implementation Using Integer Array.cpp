#include <iostream>
using namespace std;

class MaxHeap
{
private:
    int *heapArray;
    int capacity;
    int size;

    void heapifyDown(int index)
    {
        int largest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < size && heapArray[left] > heapArray[largest])
            largest = left;

        if (right < size && heapArray[right] > heapArray[largest])
            largest = right;

        if (largest != index)
        {
            swap(heapArray[index], heapArray[largest]);
            heapifyDown(largest);
        }
    }

    void heapifyUp(int index)
    {
        int parent = (index - 1) / 2;
        if (index > 0 && heapArray[index] > heapArray[parent])
        {
            swap(heapArray[index], heapArray[parent]);
            heapifyUp(parent);
        }
    }

public:
    MaxHeap(int cap)
    {
        capacity = cap;
        size = 0;
        heapArray = new int[cap];
    }

    void insert(int value)
    {
        if (size == capacity)
        {
            cout << "Heap is full!" << endl;
            return;
        }
        heapArray[size] = value;
        heapifyUp(size);
        size++;
    }

    int extractMax()
    {
        if (size == 0)
        {
            cout << "Heap is empty!" << endl;
            return -1;
        }
        int maxVal = heapArray[0];
        heapArray[0] = heapArray[size - 1];
        size--;
        heapifyDown(0);
        return maxVal;
    }

    void printHeap()
    {
        cout << "Heap: ";
        for (int i = 0; i < size; i++)
            cout << heapArray[i] << " ";
        cout << endl;
    }

    ~MaxHeap()
    {
        delete[] heapArray;
    }
};

int main()
{
    MaxHeap heap(10);

    int arr[] = {15, 10, 30, 40, 50, 20};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++)
    {
        heap.insert(arr[i]);
    }

    heap.printHeap();

    cout << "Extracted Max: " << heap.extractMax() << endl;
    heap.printHeap();

    return 0;
}
