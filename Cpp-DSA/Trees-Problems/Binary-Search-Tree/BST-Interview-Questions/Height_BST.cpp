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

void PreOrderTraversal(node *root)
{
    if (root != nullptr)
    {
        cout << root->data << " ";
        PreOrderTraversal(root->left);
        PreOrderTraversal(root->right);
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

int main()
{
    node *root = nullptr;
    GetDataFromUser(root);
    cout << endl;
    cout << "Pre-order traversal!" << endl;
    PreOrderTraversal(root);

    cout << endl;
    cout << "Maximum height of this BST is : " << CalculateHeightOfBST(root) << endl;
    return 0;
}