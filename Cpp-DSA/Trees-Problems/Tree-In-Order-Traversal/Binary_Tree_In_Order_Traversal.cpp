#include<iostream>
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

void InOrderTraversal(struct tree * root){
    if(root != nullptr){
        InOrderTraversal(root->left);
        cout << root->data << " ";
        InOrderTraversal(root->right);
    }
}

int main(){
    tree *NewNode1 = CreateNode(4);
    tree *NewNode2 = CreateNode(1);
    tree *NewNode3 = CreateNode(6);
    tree *NewNode4 = CreateNode(5);
    tree *NewNode5 = CreateNode(2);
    tree *NewNode6 = CreateNode(7);
    tree *NewNode7 = CreateNode(8);
    tree *NewNode8 = CreateNode(11);
    tree *NewNode9 = CreateNode(12);
    tree *NewNode10 = CreateNode(13);
    tree *NewNode11 = CreateNode(14);
    tree *NewNode12 = CreateNode(15);
    tree *NewNode13 = CreateNode(16);
    tree *NewNode14 = CreateNode(17);
    tree *NewNode15 = CreateNode(18);

    NewNode1->left = NewNode2;
    NewNode1->right = NewNode3;

    NewNode2->left = NewNode4;
    NewNode2->right = NewNode5;

    NewNode3->left = NewNode6;
    NewNode3->right = NewNode7;

    NewNode4->left = NewNode8;
    NewNode4->right = NewNode9;

    NewNode5->left = NewNode10;
    NewNode5->right = NewNode11;

    NewNode6->left = NewNode12;
    NewNode6->right = NewNode13;

    NewNode7->left = NewNode14;
    NewNode7->right = NewNode15;

    InOrderTraversal(NewNode1);
    return 0;
}

/*
            4
       /        \
      1           6
    /   \       /   \
   5     2     7     8
  / \   / \   / \   / \
 11 12 13 14 15 16 17 18

*/