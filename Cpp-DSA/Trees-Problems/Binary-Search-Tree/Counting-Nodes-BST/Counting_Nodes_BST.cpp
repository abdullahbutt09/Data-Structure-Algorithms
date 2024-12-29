#include <iostream>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;

    node(int d)
    {
        this->data = d;
        this->left = nullptr;
        this->right = nullptr;
    }
};

node *InsertDataIntoBST(node *root, int data)
{
    // case 1 if root is null insert node
    if (root == nullptr)
    {
        root = new node(data);
        return root;
    }

    else if (data > root->data)
    {
        root->right = InsertDataIntoBST(root->right, data);
    }

    else
    {
        root->left = InsertDataIntoBST(root->left, data);
    }
    return root;
}

void PreTraversal(node *root)
{
    if (root != nullptr)
    {
        cout << root->data << " ";
        PreTraversal(root->left);
        PreTraversal(root->right);
    }
}

void TakeDataFromUser(node *&root)
{
    int data;

    cout << "Insert Data into BST | -1 to terminate " << endl;
    cin >> data;

    while (data != -1)
    {
        root = InsertDataIntoBST(root, data);
        cin >> data;
    }
}

void FindHighSmallElementInBST(node *root)
{
    node *RightPart = root;
    node *LeftPart = root;

    while (RightPart->right != nullptr)
    {
        RightPart = RightPart->right;
    }
    cout << endl;
    cout << "Sabse bari value in BST " << RightPart->data << endl;
    cout << endl;

    while (LeftPart->left != nullptr)
    {
        LeftPart = LeftPart->left;
    }
    cout << "Sabse choti value in BST " << LeftPart->data << endl;
    cout << endl;
}

int MinVal(node *root)
{
    // agar right say min value lene ha to apko left jana hoga
    node *temp = root;
    while (temp->left != nullptr)
    {
        temp = temp->left;
    }
    return temp->data;
}

int CountNodesInBST(node *root)
{
    if (root == nullptr)
    {
        return 0;
    }

    return 1 + CountNodesInBST(root->left) + CountNodesInBST(root->right);
}

int main()
{
    node *root = nullptr;
    TakeDataFromUser(root);
    cout << CountNodesInBST(root) << endl;
    return 0;
}

// 50 5 6 75 84 92 64 82 25 15 10 2 -1