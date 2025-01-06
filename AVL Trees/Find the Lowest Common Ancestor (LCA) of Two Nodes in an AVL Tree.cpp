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

Node *findLCA(Node *root, int n1, int n2)
{
    if (!root)
        return nullptr;

    if (root->key > n1 && root->key > n2)
        return findLCA(root->left, n1, n2);

    if (root->key < n1 && root->key < n2)
        return findLCA(root->right, n1, n2);

    return root;
}

int main()
{
    Node *root = new Node(30);
    root->left = new Node(20);
    root->right = new Node(40);
    root->left->left = new Node(10);
    root->right->right = new Node(50);

    int n1 = 10, n2 = 20;
    Node *lca = findLCA(root, n1, n2);

    if (lca)
        cout << "LCA of " << n1 << " and " << n2 << " is " << lca->key << endl;
    else
        cout << "LCA not found.\n";
}
