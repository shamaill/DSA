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

int isBalanced(Node *root)
{
    if (!root)
        return 0;
    int leftHeight = isBalanced(root->left);
    if (leftHeight == -1)
        return -1;
    int rightHeight = isBalanced(root->right);
    if (rightHeight == -1)
        return -1;
    if (abs(leftHeight - rightHeight) > 1)
        return -1;
    return max(leftHeight, rightHeight) + 1;
}

bool checkBalanced(Node *root)
{
    return isBalanced(root) != -1;
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(2);
    root->left->right = new Node(7);

    cout << (checkBalanced(root) ? "Balanced BST" : "Not Balanced") << endl;
    return 0;
}
