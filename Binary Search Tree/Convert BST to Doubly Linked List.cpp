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

Node *prevNode = nullptr;

void convertToDLL(Node *root, Node *&head)
{
    if (!root)
        return;
    convertToDLL(root->left, head);
    if (!prevNode)
        head = root;
    else
    {
        root->left = prevNode;
        prevNode->right = root;
    }
    prevNode = root;
    convertToDLL(root->right, head);
}

void printDLL(Node *head)
{
    while (head)
    {
        cout << head->data << " ";
        head = head->right;
    }
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(2);
    root->left->right = new Node(7);

    Node *head = nullptr;
    convertToDLL(root, head);
    cout << "Doubly Linked List: ";
    printDLL(head);
    return 0;
}
