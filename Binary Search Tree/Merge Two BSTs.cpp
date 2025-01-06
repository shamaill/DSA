#include <iostream>
#include <vector>
#include <algorithm>
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

void storeInorder(Node *root, vector<int> &inorder)
{
    if (!root)
        return;
    storeInorder(root->left, inorder);
    inorder.push_back(root->data);
    storeInorder(root->right, inorder);
}

Node *sortedArrayToBST(vector<int> &arr, int start, int end)
{
    if (start > end)
        return nullptr;
    int mid = (start + end) / 2;
    Node *root = new Node(arr[mid]);
    root->left = sortedArrayToBST(arr, start, mid - 1);
    root->right = sortedArrayToBST(arr, mid + 1, end);
    return root;
}

Node *mergeBSTs(Node *root1, Node *root2)
{
    vector<int> inorder1, inorder2, merged;
    storeInorder(root1, inorder1);
    storeInorder(root2, inorder2);
    merge(inorder1.begin(), inorder1.end(), inorder2.begin(), inorder2.end(), back_inserter(merged));
    return sortedArrayToBST(merged, 0, merged.size() - 1);
}

int main()
{
    Node *root1 = new Node(10);
    root1->left = new Node(5);
    root1->right = new Node(15);

    Node *root2 = new Node(20);
    root2->left = new Node(18);
    root2->right = new Node(25);

    Node *mergedRoot = mergeBSTs(root1, root2);
    return 0;
}
