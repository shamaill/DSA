#include <iostream>
#include <vector>

const int TABLE_SIZE = 10;
const int EMPTY = -1;

class HashTable
{
private:
    std::vector<int> table;

    int hashFunction(int key)
    {
        return key % TABLE_SIZE; // Simple modulo-based hash function
    }

public:
    HashTable() : table(TABLE_SIZE, EMPTY) {}

    void insert(int key)
    {
        int index = hashFunction(key);
        while (table[index] != EMPTY)
        {
            index = (index + 1) % TABLE_SIZE; // Linear probing
        }
        table[index] = key;
    }

    bool contains(int key)
    {
        int index = hashFunction(key);
        while (table[index] != EMPTY)
        {
            if (table[index] == key)
            {
                return true;
            }
            index = (index + 1) % TABLE_SIZE;
        }
        return false;
    }
};

int main()
{
    HashTable hashTable;
    hashTable.insert(12);
    hashTable.insert(22);
    hashTable.insert(42);

    std::cout << "22: " << (hashTable.contains(22) ? "Found\n" : "Not Found\n");
    std::cout << "15: " << (hashTable.contains(15) ? "Found\n" : "Not Found\n");

    return 0;
}
