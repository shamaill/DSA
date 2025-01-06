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

void kthSmallestUtil(Node *root, int &k, int &result)
{
    if (!root)
        return;

    kthSmallestUtil(root->left, k, result);

    k--;
    if (k == 0)
    {
        result = root->key;
        return;
    }

    kthSmallestUtil(root->right, k, result);
}

int findKthSmallest(Node *root, int k)
{
    int result = -1;
    kthSmallestUtil(root, k, result);
    return result;
}

int main()
{
    Node *root = new Node(30);
    root->left = new Node(20);
    root->right = new Node(40);
    root->left->left = new Node(10);
    root->right->right = new Node(50);

    int k = 3;
    cout << "Kth smallest element (k = " << k << ") is: " << findKthSmallest(root, k) << endl;
}
