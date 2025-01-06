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

int findMin(Node *root)
{
    while (root->left)
        root = root->left;
    return root->key;
}

int findMax(Node *root)
{
    while (root->right)
        root = root->right;
    return root->key;
}

int main()
{
    Node *root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(70);
    root->left->left = new Node(20);
    root->right->right = new Node(80);

    cout << "Minimum value: " << findMin(root) << endl;
    cout << "Maximum value: " << findMax(root) << endl;
}
