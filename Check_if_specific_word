#include <iostream>
#include <list>
#include <string>

const int TABLE_SIZE = 10; // Define hash table size

class HashTable
{
private:
    std::list<std::string> table[TABLE_SIZE]; // Array of linked lists

    // Hash function to compute index
    int hashFunction(const std::string &word)
    {
        int hashValue = 0;
        for (char ch : word)
        {
            hashValue += ch; // Sum ASCII values of characters
        }
        return hashValue % TABLE_SIZE; // Keep index within bounds
    }

public:
    // Insert a word into the hash table
    void insert(const std::string &word)
    {
        int index = hashFunction(word);
        table[index].push_back(word);
    }

    // Check if a word exists in the hash table
    bool contains(const std::string &word)
    {
        int index = hashFunction(word);
        for (const std::string &entry : table[index])
        {
            if (entry == word)
            {
                return true; // Word found
            }
        }
        return false; // Word not found
    }
};

int main()
{
    HashTable hashTable;

    // Words to insert
    std::string words[] = {"apple", "banana", "cherry", "dog", "elephant",
                           "frog", "grape", "hat", "ice", "jacket"};

    // Insert words into the hash table
    for (const std::string &word : words)
    {
        hashTable.insert(word);
    }

    // Words to check
    std::string checkWords[] = {"apple", "cat", "frog"};

    // Check if words exist in the table
    for (const std::string &word : checkWords)
    {
        if (hashTable.contains(word))
        {
            std::cout << word << " is in the dictionary.\n";
        }
        else
        {
            std::cout << word << " is not in the dictionary.\n";
        }
    }

    return 0;
}
