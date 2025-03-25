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

    // case 2 if value is greater the root
    else if (data > root->data)
    {
        root->right = InsertDataIntoBST(root->right, data);
    }

    // case 3 if value is lesser the root
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

node *DeleteFromBST(node *root, int data)
{
    // case 1 if there if root is null
    if (root == nullptr)
    {
        return root;
    }

    // case 2 i have find the node to be deleted
    if (root->data == data)
    {
        // delete logic here

        // case 1 if root left root right is null
        if (root->left == nullptr && root->right == nullptr)
        {
            delete root;
            return nullptr;
            /*
                 20
                /  \
               x    x
            */
        }

        // case 2 have further 2 more cases

        // case 2.1 left is not null and right is null
        else if (root->right == nullptr && root->left != nullptr)
        {
            node *temp = root->left;
            delete root;
            return temp;
            /*
                 20
                /  \
               3    x
            */
        }

        // case 2.2 left is null right is not null
        else if (root->right != nullptr && root->left == nullptr)
        {
            node *temp = root->right;
            delete root;
            return temp;
            /*
                  20
                 /  \
                x    3
            */
        }

        // last case if right and left both are not null
        else 
        {
            // is case mein apko left tree say high value lani hogi ya phr right say low value lani hogi to maintain bst order!

            int MinValue = MinVal(root->right);
            root->data = MinValue;
            root->right = DeleteFromBST(root->right, MinValue);
            return root;
            /*
                  20
                 /  \
                5    3
            */
        }
    }
    
    // case 3 if value greater the root
    else if (data > root->data)
    {
        root->right = DeleteFromBST(root->right, data);
    }

    // case 4 if value is lesser the root
    else
    {
        root->left = DeleteFromBST(root->left, data);
    }
    return root;
}

int main()
{
    node *root = nullptr;
    cout << "Insert data into BST | -1 to terminate" << endl;
    TakeDataFromUser(root);

    cout << "Pre-order traversal before deletion" << endl;
    cout << endl;
    PreTraversal(root);
    cout << endl;
    cout << "Pre-order traversal after deletion" << endl;
    DeleteFromBST(root, 84);
    PreTraversal(root);
    cout << endl;
    return 0;
}

// 50 5 6 75 84 92 64 82 25 15 10 2 -1