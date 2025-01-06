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

int height(Node *root)
{
    if (!root)
        return -1;
    return 1 + max(height(root->left), height(root->right));
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(20);
    root->right->right = new Node(30);

    cout << "Height of BST: " << height(root) << "\n";
    return 0;
}
