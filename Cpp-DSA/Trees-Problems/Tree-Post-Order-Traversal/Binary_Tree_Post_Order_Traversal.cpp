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

void PostOrderTraversal(struct tree * root){
    if(root != nullptr){
        PostOrderTraversal(root->left);
        PostOrderTraversal(root->right);
        cout << root->data << " ";
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

    NewNode1->left = NewNode2;
    NewNode1->right = NewNode3;

    NewNode2->left = NewNode4;
    NewNode2->right = NewNode5;

    NewNode3->left = NewNode6;
    NewNode3->right = NewNode7;

    PostOrderTraversal(NewNode1);
    return 0;
}