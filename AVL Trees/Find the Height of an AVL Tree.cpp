#include <iostream>
using namespace std;

class Node
{
public:
    int key;
    Node *left, *right;
    int height;

    Node(int val)
    {
        key = val;
        left = right = nullptr;
        height = 1;
    }
};

int getHeight(Node *node)
{
    return node ? max(getHeight(node->left), getHeight(node->right)) + 1 : 0;
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(2);
    root->left->right = new Node(8);

    cout << "Height of the AVL tree: " << getHeight(root) << endl;
}
