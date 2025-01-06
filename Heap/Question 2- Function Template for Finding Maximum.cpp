#include <iostream>
using namespace std;

template <class T>
void findMax(T &heap)
{
    if (heap.isEmpty())
    {
        cout << "Heap is empty!" << endl;
    }
    else
    {
        cout << "Maximum element: " << heap.getMax() << endl;
    }
}

class Heap
{
private:
    int heapArray[10];
    int size;

public:
    Heap()
    {
        size = 0;
    }

    void insert(int value)
    {
        if (size < 10)
        {
            heapArray[size++] = value;
        }
    }

    int getMax()
    {
        if (size > 0)
            return heapArray[0]; // Max Heap root is the max element
        return -1;
    }

    bool isEmpty()
    {
        return size == 0;
    }
};

int main()
{
    Heap myHeap;
    myHeap.insert(30);
    myHeap.insert(50);
    myHeap.insert(10);

    findMax(myHeap);

    return 0;
}
