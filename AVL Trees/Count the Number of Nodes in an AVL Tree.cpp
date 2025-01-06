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

int countNodes(Node *root)
{
    return root ? 1 + countNodes(root->left) + countNodes(root->right) : 0;
}

int main()
{
    Node *root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(70);
    root->left->left = new Node(20);
    root->right->right = new Node(80);

    cout << "Total number of nodes: " << countNodes(root) << endl;
}
