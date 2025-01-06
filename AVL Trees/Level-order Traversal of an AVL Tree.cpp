#include <iostream>
#include <queue>
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

void levelOrder(Node *root)
{
    if (!root)
        return;
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        cout << temp->key << " ";
        q.pop();

        if (temp->left)
            q.push(temp->left);
        if (temp->right)
            q.push(temp->right);
    }
}

int main()
{
    Node *root = new Node(30);
    root->left = new Node(20);
    root->right = new Node(40);
    root->left->left = new Node(10);
    root->right->right = new Node(50);

    cout << "Level-order traversal: ";
    levelOrder(root);
}
