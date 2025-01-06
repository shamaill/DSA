#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
    Node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};

Node *insert(Node *root, int key)
{
    if (!root)
        return new Node(key);
    if (key < root->data)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);
    return root;
}

int findMin(Node *root)
{
    while (root->left)
        root = root->left;
    return root->data;
}

int findMax(Node *root)
{
    while (root->right)
        root = root->right;
    return root->data;
}

int main()
{
    Node *root = nullptr;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);

    cout << "Minimum: " << findMin(root) << "\n";
    cout << "Maximum: " << findMax(root) << "\n";
    return 0;
}
