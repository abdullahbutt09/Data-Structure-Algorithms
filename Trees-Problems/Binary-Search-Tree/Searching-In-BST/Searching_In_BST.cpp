#include <iostream>
using namespace std;

struct tree
{
    int data;
    tree *left;
    tree *right;
};

bool IsBST(tree *);

bool FindingElementInBST(tree *, int); // bool function approach is used!
tree *FindingKeyInBST(tree *, int);    // struct function approach is used!

tree *CreateNode(int data)
{
    tree *NewNode = new tree();
    NewNode->right = nullptr;
    NewNode->left = nullptr;
    NewNode->data = data;
    return NewNode;
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

    cout << endl;

    bool BST_Check = IsBST(NewNode1);

    if (BST_Check)
    {
        cout << "-> This is a Binary Search Tree!" << endl;
    }
    else
    {
        cout << "-> This is not a Binary Search Tree!" << endl;
    }
    cout << endl;

    int key = 20; // key value to search

    // using bool function concept
    bool CheckingKeyInBST = FindingElementInBST(NewNode1, key);

    if (CheckingKeyInBST)
    {
        cout << "-> Key is present in Tree!" << endl;
    }
    else
    {
        cout << "-> Key is not present in Tree!" << endl;
    }
    cout << endl;

    // using struct function concept

    tree *Temp = FindingKeyInBST(NewNode1, key);

    if (Temp)
    {
        cout << "-> Key is present " << Temp->data << endl;
    }
    else
    {
        cout << "-> No presence of key " << endl;
    }
    cout << endl;
    return 0;
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

bool FindingElementInBST(struct tree *root, int key)
{
    if (root == nullptr)
    {
        return false;
    }

    if (root->data == key)
    {
        return true;
    }

    if (key < root->data)
    {
        return FindingElementInBST(root->left, key);
    }

    if (key > root->data)
    {
        return FindingElementInBST(root->right, key);
    }
    return false;
}

tree *FindingKeyInBST(struct tree *root, int key)
{
    if (root == nullptr)
    {
        return nullptr;
    }

    if (root->data == key)
    {
        return root;
    }

    if (key < root->data)
    {
        return FindingKeyInBST(root->left, key);
    }

    if (key > root->data)
    {
        return FindingKeyInBST(root->right, key);
    }
    return nullptr;
}

/*
-> BST RULES <-
1. Left sub-tree nodes are lesser.
2. Right sub-tree nodes are greater.
3. Right and Left sub tree are also BST.
4. No duplicate nodes in BST.
5. In-Order Traversal of BST give assending sorted Array or Numbers.

        10
       /  \
      5    15
     / \   / \
    2   7 12  20

*/