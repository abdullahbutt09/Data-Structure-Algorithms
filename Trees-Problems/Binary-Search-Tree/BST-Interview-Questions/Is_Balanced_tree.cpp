#include <iostream>
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

bool CheckTreeIsBalanced(node *root)
{
    if (root == nullptr)
    {
        return true;
    }

    bool Left = CheckTreeIsBalanced(root->left);
    bool right = CheckTreeIsBalanced(root->right);

    bool diff = abs(CalculateHeightOfBST(root->left) - CalculateHeightOfBST(root->right)) <= 1;

    if (Left && right && diff)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{

    node *root = nullptr;

    GetDataFromUser(root);

    if (CheckTreeIsBalanced(root))
    {
        cout << endl;
        cout << "Tree is balanced!" << endl;
        cout << endl;
    }
    else
    {
        cout << endl;
        cout << "Tree not balanced" << endl;
        cout << endl;
    }

    cout << "Height of right tree is " << CalculateHeightOfBST(root->left)<<endl;
    cout << "Height of right tree is " << CalculateHeightOfBST(root->right)<<endl;
    return 0;
}

//* 8 4 2 1 0 50 100 110 40 90
//* 8 50 100 110 40 90