#include <iostream>
#include <queue>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;

    node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

node *BuildTree(node *root)
{
    cout << "Enter Data: ";
    int data;
    cin >> data;

    root = new node(data);

    if (data == -1)
    {
        return NULL;
    }

    cout << "Enter data to put on left of " << data << endl;
    root->left = BuildTree(root->left);
    cout << "Enter data to put on right of " << data << endl;
    root->right = BuildTree(root->right);
    return root;
}

void PreOrderTraversal(node *root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        PreOrderTraversal(root->left);
        PreOrderTraversal(root->right);
    }
}

void LevelOrderTraversal(node *root)
{
    queue<node *> q;

    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            cout << endl;

            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";

            if (temp->left)
            {
                q.push(temp->left);
            }

            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

int main()
{

    node *root = NULL;
    root = BuildTree(root);
    cout << endl;
    cout << endl;
    cout << "Pre order Traversal ";
    PreOrderTraversal(root);
    cout << endl;
    cout << endl;
    cout << "Level order Traversal "<<endl;
    cout << endl;
    LevelOrderTraversal(root);
    //  1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    cout << endl;
    return 0;
}