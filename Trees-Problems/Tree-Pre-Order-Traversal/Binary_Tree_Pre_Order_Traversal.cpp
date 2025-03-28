#include <iostream>
using namespace std;

struct tree
{
    int data;
    tree *left;
    tree *right;
};

tree *CreateNode(int data)
{
    tree *NewNode = new tree();
    NewNode->right = nullptr;
    NewNode->left = nullptr;
    NewNode->data = data;
    return NewNode;
}

void PreOrderTraversal(struct tree *root)
{
    if (root != nullptr)
    {
        cout << root->data << " ";
        PreOrderTraversal(root->left);
        PreOrderTraversal(root->right);
    }
}

int main()
{
    tree *NewNode1 = CreateNode(1);
    tree *NewNode2 = CreateNode(2);
    tree *NewNode3 = CreateNode(3);
    tree *NewNode4 = CreateNode(4);
    tree *NewNode5 = CreateNode(5);
    tree *NewNode6 = CreateNode(6);
    tree *NewNode7 = CreateNode(7);

    NewNode1->left = NewNode2;
    NewNode1->right = NewNode3;
    NewNode2->left = NewNode4;
    NewNode2->right = NewNode5;
    NewNode3->left = NewNode6;
    NewNode3->right = NewNode7;

    PreOrderTraversal(NewNode1);
    return 0;
}