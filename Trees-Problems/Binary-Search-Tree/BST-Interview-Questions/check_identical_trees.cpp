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

bool IsTreesAreIndentical(node *tree1, node *tree2)
{
    if (tree1 == nullptr && tree2 == nullptr)
    {
        return true;
    }

    if (tree1 == nullptr && tree2 != nullptr)
    {
        return false;
    }

    if (tree1 != nullptr && tree2 == nullptr)
    {
        return false;
    }

    bool left = IsTreesAreIndentical(tree1->left, tree2->left);
    bool right = IsTreesAreIndentical(tree1->right, tree2->right);

    bool Value = tree1->data == tree2->data;

    if (left && right && Value)
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
    node *root1 = nullptr;
    GetDataFromUser(root1);

    node *root2 = nullptr;
    GetDataFromUser(root2);

    if (IsTreesAreIndentical(root1, root2))
    {
        cout << "Identical!" << endl;
    }
    else
    {
        cout << "Not identical!" << endl;
    }

    return 0;
}