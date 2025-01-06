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

bool isBSTUtil(Node *root, Node *minNode, Node *maxNode)
{
    if (!root)
        return true;
    if ((minNode && root->data <= minNode->data) || (maxNode && root->data >= maxNode->data))
        return false;
    return isBSTUtil(root->left, minNode, root) && isBSTUtil(root->right, root, maxNode);
}

bool isBST(Node *root)
{
    return isBSTUtil(root, nullptr, nullptr);
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(20);
    root->left->left = new Node(3);
    root->left->right = new Node(7);

    cout << (isBST(root) ? "Valid BST" : "Not a BST") << endl;
    return 0;
}
