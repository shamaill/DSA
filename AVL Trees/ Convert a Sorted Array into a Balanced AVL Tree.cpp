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

Node *sortedArrayToAVL(int arr[], int start, int end)
{
    if (start > end)
        return nullptr;

    int mid = (start + end) / 2;
    Node *root = new Node(arr[mid]);

    root->left = sortedArrayToAVL(arr, start, mid - 1);
    root->right = sortedArrayToAVL(arr, mid + 1, end);

    return root;
}

void inorder(Node *root)
{
    if (root)
    {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50, 60, 70};
    int n = sizeof(arr) / sizeof(arr[0]);

    Node *root = sortedArrayToAVL(arr, 0, n - 1);

    cout << "Inorder traversal of AVL tree: ";
    inorder(root);
}
