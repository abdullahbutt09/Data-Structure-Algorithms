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

void InOrderTraversal(struct tree *root)
{
    if (root != nullptr)
    {
        InOrderTraversal(root->left);
        cout << root->data << " ";
        InOrderTraversal(root->right);
    }
}

bool IsBST(struct tree *root)
{
    static tree *pre = nullptr;
    if (root != nullptr)
    {
        if (!IsBST(root->left))
        {
            return false;
        }
        if (pre != nullptr && root->data < pre->data)
        {
            return false;
        }
        pre = root;
        return IsBST(root->right);
    }
    else
    {
        return true;
    }
}

int main()
{
    tree *NewNode1 = CreateNode(10);
    tree *NewNode2 = CreateNode(5);
    tree *NewNode3 = CreateNode(30);
    tree *NewNode4 = CreateNode(4);
    tree *NewNode5 = CreateNode(20);
    tree *NewNode6 = CreateNode(6);
    tree *NewNode7 = CreateNode(0);

    NewNode1->left = NewNode2;  // 10 -> 5
    NewNode1->right = NewNode3; // 10 -> 30

    NewNode2->left = NewNode7;  // 5 -> 0
    NewNode2->right = NewNode6; // 5 -> 6

    NewNode3->left = NewNode5; // 30 -> 20

    InOrderTraversal(NewNode1);
    cout << endl;

    if (IsBST(NewNode1))
    {
        cout << "-> This is a Binary Search Tree!" << endl;
    }
    else
    {
        cout << "-> This is not a Binary Search Tree!" << endl;
    }
    return 0;
}

/*
-> BST RULES <-
1. Left sub-tree nodes are lesser.
2. Right sub-tree nodes are greater.
3. Right and Left sub tree are also BST.
4. No duplicate nodes in BST.
5. In-Order Traversal of BST give assending sorted Array or Numbers.
*/