#include <iostream>
#include <stack>
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

Node *insert(Node *root, int key)
{
    if (!root)
        return new Node(key);
    if (key < root->data)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);
    return root;
}

void zigZagTraversal(Node *root)
{
    if (!root)
        return;

    stack<Node *> s1, s2;
    s1.push(root);

    while (!s1.empty() || !s2.empty())
    {
        while (!s1.empty())
        {
            Node *temp = s1.top();
            s1.pop();
            cout << temp->data << " ";
            if (temp->left)
                s2.push(temp->left);
            if (temp->right)
                s2.push(temp->right);
        }

        while (!s2.empty())
        {
            Node *temp = s2.top();
            s2.pop();
            cout << temp->data << " ";
            if (temp->right)
                s1.push(temp->right);
            if (temp->left)
                s1.push(temp->left);
        }
    }
}

int main()
{
    Node *root = nullptr;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    cout << "Zig-Zag Traversal: ";
    zigZagTraversal(root);
    return 0;
}
