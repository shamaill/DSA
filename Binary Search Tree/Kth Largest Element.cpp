void kthLargestUtil(Node *root, int &k, int &result)
{
    if (!root)
        return;
    kthLargestUtil(root->right, k, result);
    if (--k == 0)
    {
        result = root->data;
        return;
    }
    kthLargestUtil(root->left, k, result);
}

int kthLargest(Node *root, int k)
{
    int result = -1;
    kthLargestUtil(root, k, result);
    return result;
}
