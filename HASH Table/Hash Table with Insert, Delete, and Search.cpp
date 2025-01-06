#include <iostream>
#include <list>
#include <string>

const int TABLE_SIZE = 10;

class HashTable
{
private:
    std::list<std::string> table[TABLE_SIZE];

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
    void insert(const std::string &word)
    {
        int index = hashFunction(word);
        table[index].push_back(word);
    }

    void remove(const std::string &word)
    {
        int index = hashFunction(word);
        table[index].remove(word);
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
    hashTable.insert("apple");
    hashTable.insert("banana");
    hashTable.insert("cherry");

    std::cout << "Before deletion:\n";
    std::cout << "apple: " << (hashTable.contains("apple") ? "Found\n" : "Not Found\n");

    hashTable.remove("apple");

    std::cout << "After deletion:\n";
    std::cout << "apple: " << (hashTable.contains("apple") ? "Found\n" : "Not Found\n");

    return 0;
}
