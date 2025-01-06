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

Node *sortedArrayToBST(int arr[], int start, int end)
{
    if (start > end)
        return nullptr;
    int mid = (start + end) / 2;
    Node *root = new Node(arr[mid]);
    root->left = sortedArrayToBST(arr, start, mid - 1);
    root->right = sortedArrayToBST(arr, mid + 1, end);
    return root;
}

void inorder(Node *root)
{
    if (root)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    Node *root = sortedArrayToBST(arr, 0, n - 1);
    cout << "Inorder Traversal of BST: ";
    inorder(root);
    return 0;
}
