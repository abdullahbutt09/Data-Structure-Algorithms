#include<iostream>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;

    node(int d)
    {
        // this->left = this->right = nullptr;
        this->left = nullptr;
        this->right = nullptr;
        this->data = d;
    }
};

int CalculateHeightOfBST(node *root)
{
    if (root == nullptr)
    {
        return 0;
    }

    int left = CalculateHeightOfBST(root->left);
    int right = CalculateHeightOfBST(root->right);

    int answer = max(left, right) + 1;
    return answer;
}

int diameter(node * root){
    if(root == nullptr){
        return 0;
    }

    int option1 = diameter(root->left);
    int option2 = diameter(root->right);
    int option3 = CalculateHeightOfBST(root->left) + CalculateHeightOfBST(root->right) + 1;

    int answer = max(option1, max(option2 , option3));
    return answer;
}

node *InsertDataInBST(node *root, int data)
{
    if (root == nullptr)
    {
        root = new node(data);
        return root;
    }

    if (data > root->data)
    {
        root->right = InsertDataInBST(root->right, data);
    }

    else
    {
        root->left = InsertDataInBST(root->left, data);
    }
    return root;
}

void GetDataFromUser(node *&root)
{
    int data;
    cout << "Insert Data In BST -1 to terminate!" << endl;
    cin >> data;
    while (data != -1)
    {
        root = InsertDataInBST(root, data);
        cin >> data;
    }
}

int main(){

    node * root = nullptr;
    GetDataFromUser(root);
    cout << endl;
    cout << "Diameter of the tree is " << diameter(root->left) << endl;
    cout << endl;
    return 0;
}


//* 50 30 70 20 40 60 80
//* 8 4 2 1 0 50 100 110 40 90