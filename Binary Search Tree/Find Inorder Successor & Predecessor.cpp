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

Node *inorderSuccessor(Node *root, Node *target)
{
    Node *succ = nullptr;
    while (root)
    {
        if (target->data < root->data)
        {
            succ = root;
            root = root->left;
        }
        else
            root = root->right;
    }
    return succ;
}

Node *inorderPredecessor(Node *root, Node *target)
{
    Node *pred = nullptr;
    while (root)
    {
        if (target->data > root->data)
        {
            pred = root;
            root = root->right;
        }
        else
            root = root->left;
    }
    return pred;
}

int main()
{
    Node *root = new Node(20);
    root->left = new Node(10);
    root->right = new Node(30);
    root->left->left = new Node(5);
    root->left->right = new Node(15);

    Node *target = root->left; // Node with value 10
    Node *succ = inorderSuccessor(root, target);
    Node *pred = inorderPredecessor(root, target);

    cout << "Inorder Successor of " << target->data << ": " << (succ ? to_string(succ->data) : "None") << endl;
    cout << "Inorder Predecessor of " << target->data << ": " << (pred ? to_string(pred->data) : "None") << endl;
    return 0;
}
