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

int checkAVL(Node *root)
{
    if (!root)
        return 0;

    int leftHeight = checkAVL(root->left);
    if (leftHeight == -1)
        return -1;

    int rightHeight = checkAVL(root->right);
    if (rightHeight == -1)
        return -1;

    if (abs(leftHeight - rightHeight) > 1)
        return -1;

    return max(leftHeight, rightHeight) + 1;
}

bool isAVL(Node *root)
{
    return checkAVL(root) != -1;
}

int main()
{
    Node *root = new Node(30);
    root->left = new Node(20);
    root->right = new Node(40);
    root->left->left = new Node(10);
    root->right->right = new Node(50);

    cout << "Is the tree an AVL tree? " << (isAVL(root) ? "Yes" : "No") << endl;
}
