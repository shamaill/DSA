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

Node *deleteLeaves(Node *root)
{
    if (!root)
        return nullptr;
    if (!root->left && !root->right)
    {
        delete root;
        return nullptr;
    }
    root->left = deleteLeaves(root->left);
    root->right = deleteLeaves(root->right);
    return root;
}

void inorder(Node *root)
{
    if (root)
    {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

int main()
{
    Node *root = new Node(30);
    root->left = new Node(20);
    root->right = new Node(40);
    root->left->left = new Node(10);
    root->right->right = new Node(50);

    cout << "Before deleting leaves: ";
    inorder(root);
    cout << endl;

    root = deleteLeaves(root);

    cout << "After deleting leaves: ";
    inorder(root);
}
