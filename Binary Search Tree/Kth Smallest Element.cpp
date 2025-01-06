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

void kthSmallestUtil(Node *root, int &k, int &result)
{
    if (!root)
        return;
    kthSmallestUtil(root->left, k, result);
    if (--k == 0)
    {
        result = root->data;
        return;
    }
    kthSmallestUtil(root->right, k, result);
}

int kthSmallest(Node *root, int k)
{
    int result = -1;
    kthSmallestUtil(root, k, result);
    return result;
}

int main()
{
    Node *root = new Node(20);
    root->left = new Node(10);
    root->right = new Node(30);
    root->left->left = new Node(5);
    root->left->right = new Node(15);

    cout << "3rd Smallest Element: " << kthSmallest(root, 3) << endl;
    return 0;
}
