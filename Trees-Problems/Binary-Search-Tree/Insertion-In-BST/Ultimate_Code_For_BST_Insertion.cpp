#include<iostream>
using namespace std;

struct tree{
    int data;
    tree * left;
    tree * right;

    tree(int d){
        this->data = d;
        this->left = nullptr;
        this->right = nullptr;
    }
};

tree * InsertIntoBST(int data , tree * root){
    if(root == nullptr){
        root = new tree(data);
        return root;
    }

    if(data < root->data){
        root->left = InsertIntoBST(data , root->left);
    }

    if(data > root->data){
        root->right = InsertIntoBST(data , root->right);
    }
    return root;
}

void TakeInputData(tree * &root){
    int data;

    cout << "Enter any random Numbers -1 to terminate!"<<endl;
    cin >> data;

    while (data != -1)
    {
        root = InsertIntoBST(data , root);
        cin >> data;
    }
}

void PreOrderTraversal(tree * root){
    
    if(root != nullptr){
        cout << root->data <<" ";
        PreOrderTraversal(root->left);
        PreOrderTraversal(root->right);
    }
}

void PostOrderTraversal(tree * root){
    
    if(root != nullptr){
        PostOrderTraversal(root->left);
        PostOrderTraversal(root->right);
        cout << root->data <<" ";
    }
}

void InOrderTraversal(tree * root){
    
    if(root != nullptr){
        InOrderTraversal(root->left);
        cout << root->data <<" ";
        InOrderTraversal(root->right);
    }
}

int main(){

    tree * root = nullptr;
    int choice;

    do{
    cout << endl;
    cout << endl;
    cout << "1. Insert Data Into BST"<<endl;
    cout << "2. Print PreOrderTraversal Of BST"<<endl;
    cout << "3. Print InOrderTraversal Of BST"<<endl;
    cout << "4. Print PostOrderTraversal Of BST"<<endl;
    cout << endl;
    cout << "Enter Your Choice -> ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        TakeInputData(root);
        break;
    case 2:
        PreOrderTraversal(root);
        break;
    case 3:
        InOrderTraversal(root);
        break;
    case 4:
       PostOrderTraversal(root);
        break;
    default:
        cout << "Incorrect choice!"<<endl;
        break;
    }
}while(choice != 5);

    TakeInputData(root);
    PreOrderTraversal(root);
    
    return 0;
}