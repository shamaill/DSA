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

void print2D(Node *root, int space)
{
    if (!root)
        return;

    space += 10;
    print2D(root->right, space);
    cout << endl;

    for (int i = 10; i < space; i++)
        cout << " ";
    cout << root->key << "\n";

    print2D(root->left, space);
}

int main()
{
    Node *root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(70);
    root->left->left = new Node(20);
    root->left->right = new Node(40);
    root->right->right = new Node(80);

    cout << "AVL Tree printed sideways:\n";
    print2D(root, 0);
}
