#include <iostream>
#include <vector>

const int TABLE_SIZE = 10;
const std::string EMPTY = "";

class HashTable
{
private:
    std::vector<std::string> table;

    int hashFunction(const std::string &word)
    {
        int hashValue = 0;
        for (char ch : word)
        {
            hashValue += ch;
        }
        return hashValue % TABLE_SIZE;
    }

public:
    HashTable() : table(TABLE_SIZE, EMPTY) {}

    void insert(const std::string &word)
    {
        int index = hashFunction(word);
        while (table[index] != EMPTY)
        {
            index = (index + 1) % TABLE_SIZE; // Linear probing
        }
        table[index] = word;
    }

    bool contains(const std::string &word)
    {
        int index = hashFunction(word);
        while (table[index] != EMPTY)
        {
            if (table[index] == word)
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
    hashTable.insert("apple");
    hashTable.insert("banana");
    hashTable.insert("cherry");

    std::cout << "apple: " << (hashTable.contains("apple") ? "Found\n" : "Not Found\n");
    std::cout << "cat: " << (hashTable.contains("cat") ? "Found\n" : "Not Found\n");

    return 0;
}
