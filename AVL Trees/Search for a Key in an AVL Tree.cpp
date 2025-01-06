#include <iostream>
using namespace std;

class Node
{
public:
    int key;
    Node *left, *right;

    Node(int val)
    {
        key = val;
        left = right = nullptr;
    }
};

bool search(Node *root, int key)
{
    if (!root)
        return false;
    if (root->key == key)
        return true;
    return key < root->key ? search(root->left, key) : search(root->right, key);
}

int main()
{
    Node *root = new Node(15);
    root->left = new Node(10);
    root->right = new Node(20);
    root->left->left = new Node(5);
    root->right->right = new Node(25);

    int key = 10;
    cout << "Key " << key << " is " << (search(root, key) ? "found" : "not found") << endl;
}
