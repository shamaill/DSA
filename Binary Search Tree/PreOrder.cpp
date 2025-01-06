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

void preorder(Node *root)
{
    if (root)
    {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

int main()
{
    Node *root = nullptr;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);

    cout << "Preorder Traversal: ";
    preorder(root);
    return 0;
}
