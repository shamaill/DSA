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

Node *LCA(Node *root, int n1, int n2)
{
    if (!root)
        return nullptr;
    if (root->data > n1 && root->data > n2)
        return LCA(root->left, n1, n2);
    if (root->data < n1 && root->data < n2)
        return LCA(root->right, n1, n2);
    return root;
}

int main()
{
    Node *root = new Node(20);
    root->left = new Node(10);
    root->right = new Node(30);
    root->left->left = new Node(5);
    root->left->right = new Node(15);

    Node *lca = LCA(root, 5, 15);
    cout << "LCA: " << lca->data << endl;
    return 0;
}
