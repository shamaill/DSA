#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    int key;
    string value;
    Node *left, *right;
    int height;

    Node(int k, string v)
    {
        key = k;
        value = v;
        left = right = nullptr;
        height = 1;
    }
};

int getHeight(Node *node)
{
    return node ? node->height : 0;
}

Node *insert(Node *node, int key, string value)
{
    if (!node)
        return new Node(key, value);

    if (key < node->key)
        node->left = insert(node->left, key, value);
    else if (key > node->key)
        node->right = insert(node->right, key, value);
    else
        node->value = value;

    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
    return node;
}

string search(Node *root, int key)
{
    if (!root)
        return "Not found";
    if (root->key == key)
        return root->value;
    return key < root->key ? search(root->left, key) : search(root->right, key);
}

int main()
{
    Node *root = nullptr;
    root = insert(root, 1, "Apple");
    root = insert(root, 2, "Banana");
    root = insert(root, 3, "Cherry");

    cout << "Search for key 2: " << search(root, 2) << endl;
    cout << "Search for key 4: " << search(root, 4) << endl;
}
