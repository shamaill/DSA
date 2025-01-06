#include <iostream>
#include <vector>
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

void storeInorder(Node *root, vector<int> &arr)
{
    if (!root)
        return;
    storeInorder(root->left, arr);
    arr.push_back(root->key);
    storeInorder(root->right, arr);
}

Node *sortedArrayToAVL(vector<int> &arr, int start, int end)
{
    if (start > end)
        return nullptr;

    int mid = (start + end) / 2;
    Node *root = new Node(arr[mid]);

    root->left = sortedArrayToAVL(arr, start, mid - 1);
    root->right = sortedArrayToAVL(arr, mid + 1, end);

    return root;
}

Node *mergeAVL(Node *root1, Node *root2)
{
    vector<int> arr1, arr2, mergedArr;
    storeInorder(root1, arr1);
    storeInorder(root2, arr2);

    mergedArr.resize(arr1.size() + arr2.size());
    merge(arr1.begin(), arr1.end(), arr2.begin(), arr2.end(), mergedArr.begin());

    return sortedArrayToAVL(mergedArr, 0, mergedArr.size() - 1);
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
    Node *root1 = new Node(30);
    root1->left = new Node(20);
    root1->right = new Node(40);

    Node *root2 = new Node(60);
    root2->left = new Node(50);
    root2->right = new Node(70);

    Node *mergedRoot = mergeAVL(root1, root2);

    cout << "Inorder traversal of merged AVL tree: ";
    inorder(mergedRoot);
}
