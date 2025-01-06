#include <iostream>
#include <list>
#include <string>

const int TABLE_SIZE = 10;

class HashTable
{
private:
    std::list<std::pair<std::string, int>> table[TABLE_SIZE];

    int hashFunction(const std::string &key)
    {
        int hashValue = 0;
        for (char ch : key)
        {
            hashValue += ch;
        }
        return hashValue % TABLE_SIZE;
    }

public:
    void insert(const std::string &key, int value)
    {
        int index = hashFunction(key);
        for (auto &pair : table[index])
        {
            if (pair.first == key)
            {
                pair.second = value;
                return;
            }
        }
        table[index].emplace_back(key, value);
    }

    int get(const std::string &key)
    {
        int index = hashFunction(key);
        for (const auto &pair : table[index])
        {
            if (pair.first == key)
            {
                return pair.second;
            }
        }
        return -1;
    }
};

int main()
{
    HashTable hashTable;
    hashTable.insert("apple", 5);
    hashTable.insert("banana", 3);
    hashTable.insert("cherry", 7);

    std::cout << "apple: " << hashTable.get("apple") << "\n";
    std::cout << "grape: " << hashTable.get("grape") << "\n";

    return 0;
}
