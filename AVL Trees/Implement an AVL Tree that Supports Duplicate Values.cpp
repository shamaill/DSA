#include <iostream>
using namespace std;

class Node
{
public:
    int key, count;
    Node *left, *right;
    int height;

    Node(int val)
    {
        key = val;
        count = 1;
        left = right = nullptr;
        height = 1;
    }
};

int getHeight(Node *node)
{
    return node ? node->height : 0;
}

Node *insert(Node *node, int key)
{
    if (!node)
        return new Node(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        node->count++;

    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
    return node;
}

void inorder(Node *root)
{
    if (root)
    {
        inorder(root->left);
        for (int i = 0; i < root->count; i++)
            cout << root->key << " ";
        inorder(root->right);
    }
}

int main()
{
    Node *root = nullptr;
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 40);

    cout << "Inorder traversal of AVL tree with duplicates: ";
    inorder(root);
}
