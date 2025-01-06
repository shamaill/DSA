#include <iostream>
#include <list>
#include <string>

const int TABLE_SIZE = 10; // Define hash table size

class HashTable
{
private:
    std::list<std::string> table[TABLE_SIZE]; // Array of linked lists

    int hashFunction(const std::string &word)
    {
        int hashValue = 0;
        for (char ch : word)
        {
            hashValue += ch; // Sum ASCII values
        }
        return hashValue % TABLE_SIZE; // Keep index within bounds
    }

public:
    void insert(const std::string &word)
    {
        int index = hashFunction(word);
        table[index].push_back(word);
    }

    bool contains(const std::string &word)
    {
        int index = hashFunction(word);
        for (const std::string &entry : table[index])
        {
            if (entry == word)
            {
                return true;
            }
        }
        return false;
    }
};

int main()
{
    HashTable hashTable;
    std::string words[] = {"apple", "banana", "cherry", "dog", "elephant"};

    for (const std::string &word : words)
    {
        hashTable.insert(word);
    }

    std::string checkWords[] = {"apple", "cat", "dog"};
    for (const std::string &word : checkWords)
    {
        std::cout << word << (hashTable.contains(word) ? " is found.\n" : " is not found.\n");
    }

    return 0;
}
