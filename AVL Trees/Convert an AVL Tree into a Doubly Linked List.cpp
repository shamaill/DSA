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

void convertToDLL(Node *root, Node *&head, Node *&prev)
{
    if (!root)
        return;

    convertToDLL(root->left, head, prev);

    if (!head)
        head = root;
    else
    {
        prev->right = root;
        root->left = prev;
    }
    prev = root;

    convertToDLL(root->right, head, prev);
}

void printDLL(Node *head)
{
    while (head)
    {
        cout << head->key << " ";
        head = head->right;
    }
}

int main()
{
    Node *root = new Node(30);
    root->left = new Node(20);
    root->right = new Node(40);
    root->left->left = new Node(10);
    root->right->right = new Node(50);

    Node *head = nullptr, *prev = nullptr;
    convertToDLL(root, head, prev);

    cout << "Doubly Linked List: ";
    printDLL(head);
}
