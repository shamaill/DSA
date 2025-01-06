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
    return node ? node->height : 0;
}

Node *rotateRight(Node *y)
{
    Node *x = y->left;
    y->left = x->right;
    x->right = y;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    return x;
}

Node *rotateLeft(Node *x)
{
    Node *y = x->right;
    x->right = y->left;
    y->left = x;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    return y;
}

void preorder(Node *root)
{
    if (root)
    {
        cout << root->key << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

int main()
{
    Node *root = new Node(30);
    root->left = new Node(20);
    root->right = new Node(40);
    root->left->left = new Node(10);

    cout << "Before Right Rotation (LL case): ";
    preorder(root);
    cout << endl;

    root = rotateRight(root);

    cout << "After Right Rotation: ";
    preorder(root);
}
