#include <iostream>
using namespace std;

struct tree
{
    int data;
    tree *left;
    tree *right;
};

void InsertionInBST(tree *, int);
void InOrderTraversal(tree *);

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

    int key = 9; // key value to insert    

    InsertionInBST(NewNode1 , key);
    cout << endl;

    cout << "In Order Traversal of Tree:";
    InOrderTraversal(NewNode1);
    cout << endl;
    cout << endl;
    return 0;
}

void InsertionInBST(struct tree *root, int key)
{
    tree *NewNode = CreateNode(key);
    tree *Prev = new tree();

    while (root != nullptr)
    {
        Prev = root;

        if (root->data == key)
        {
            cout << "-> Key is present in BST Cannot Insert!" << endl;
            return;
        }

        if (key < root->data)
        {
            root = root->left;
        }

        if (key > root->data)
        {
            root = root->right;
        }
    }

    if (key < Prev->data)
    {
        cout << "-> Inserted Successfully! <-"<<endl;
        Prev->left = NewNode;
    }
    if(key > Prev->data)
    {
        cout << "-> Inserted Successfully! <-"<<endl;
        Prev->right = NewNode;
    }
}

void InOrderTraversal(tree * root){
    if (root != nullptr)
    {
        InOrderTraversal(root->left);
        cout << " -> " << root->data <<"";
        InOrderTraversal(root->right);
    }
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