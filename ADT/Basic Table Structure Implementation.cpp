#include <iostream>
#include <string>

using namespace std;

// Class to represent key-value pairs
class TableEntry
{
public:
    string key;
    string value;

    TableEntry() {}                                      // Default constructor
    TableEntry(string k, string v) : key(k), value(v) {} // Parameterized constructor
};

// Class to represent a simple key-value table
class Table
{
private:
    TableEntry entries[10]; // Fixed-size array for simplicity
    int size;

public:
    Table() : size(0) {} // Initialize table with zero entries

    // Insert a new key-value pair
    void insert(string key, string value)
    {
        if (size < 10)
        {
            entries[size++] = TableEntry(key, value);
        }
        else
        {
            cout << "Table is full. Cannot insert more entries." << endl;
        }
    }

    // Display all entries in the table
    void display()
    {
        cout << "Table Entries:\n";
        for (int i = 0; i < size; i++)
        {
            cout << entries[i].key << " : " << entries[i].value << endl;
        }
    }
};

int main()
{
    Table table;

    // Hardcoded test data
    table.insert("name", "Alice");
    table.insert("age", "25");
    table.insert("city", "New York");

    // Display all entries
    table.display();

    return 0;
}
