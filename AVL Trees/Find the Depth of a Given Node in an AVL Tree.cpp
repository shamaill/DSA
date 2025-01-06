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

int findDepth(Node *root, int key, int depth = 0)
{
    if (!root)
        return -1;
    if (root->key == key)
        return depth;

    int leftDepth = findDepth(root->left, key, depth + 1);
    if (leftDepth != -1)
        return leftDepth;

    return findDepth(root->right, key, depth + 1);
}

int main()
{
    Node *root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(70);
    root->left->left = new Node(20);
    root->right->right = new Node(80);

    int key = 80;
    int depth = findDepth(root, key);
    if (depth != -1)
        cout << "Depth of node " << key << " is " << depth << endl;
    else
        cout << "Node not found in AVL tree." << endl;
}
