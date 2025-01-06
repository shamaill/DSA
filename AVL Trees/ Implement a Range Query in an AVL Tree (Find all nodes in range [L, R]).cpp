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

void rangeQuery(Node *root, int L, int R)
{
    if (!root)
        return;

    if (root->key > L)
        rangeQuery(root->left, L, R);

    if (root->key >= L && root->key <= R)
        cout << root->key << " ";

    if (root->key < R)
        rangeQuery(root->right, L, R);
}

int main()
{
    Node *root = new Node(30);
    root->left = new Node(20);
    root->right = new Node(40);
    root->left->left = new Node(10);
    root->right->right = new Node(50);

    int L = 15, R = 45;
    cout << "Nodes in range [" << L << ", " << R << "]: ";
    rangeQuery(root, L, R);
}
