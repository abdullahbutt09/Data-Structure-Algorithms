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

void PreTraversal(node *root)
{
    if (root != nullptr)
    {
        cout << root->data << " ";
        PreTraversal(root->left);
        PreTraversal(root->right);
    }
}

void PostTraversal(node *root)
{
    if (root != nullptr)
    {
        PreTraversal(root->left);
        PreTraversal(root->right);
        cout << root->data << " ";
    }
}

void InOrderTraversal(node *root)
{
    if (root != nullptr)
    {
        PreTraversal(root->left);
        cout << root->data << " ";
        PreTraversal(root->right);
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

        // case 2.1 right is null left not null
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

        // last case if right and left both not null
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

bool FindingElementInBST(node *root, int key)
{
    if (root == nullptr)
    {
        return false;
    }

    while (root != nullptr)
    {
        if (root->data == key)
        {
            return true;
        }

        if (key < root->data)
        {
            root = root->left;
        }

        if (key > root->data)
        {
            root = root->right;
        }
    }
    return false;
}

node *FindingElementInBSTNew(int key, node *root)
{
    if (root == nullptr || root->data == key)
    {
        return root;
    }

    if (key > root->data)
    {
        return FindingElementInBSTNew(key, root->right);
    }

    if (key < root->data)
    {
        return FindingElementInBSTNew(key, root->left);
    }
    return root;
}

int FindHeightOfTree(node *root)
{
    if (root == nullptr)
    {
        return 0;
    }

    int leftHeight = FindHeightOfTree(root->left);
    int rightHeight = FindHeightOfTree(root->right);

    int answer = max(leftHeight, rightHeight) + 1;
    return answer;
}

int CountLeafNodes(node *root)
{
    if (root == nullptr)
    {
        return 0; // Base case: empty tree has no leaf nodes
    }

    if (root->left == nullptr && root->right == nullptr)
    {
        return 1; // This is a leaf node
    }

    // Recursively count leaf nodes in left and right subtrees
    return CountLeafNodes(root->left) + CountLeafNodes(root->right);
}

int CountTotalNodesInBST(node *root)
{
    if (root == nullptr)
    {
        return 0; // Base case: no nodes
    }

    // Count this node (1) and recursively count left and right subtrees
    return 1 + CountTotalNodesInBST(root->left) + CountTotalNodesInBST(root->right);
}

void CountLeftRightNodes(node *root, int &leftCount, int &rightCount)
{
    if (root == nullptr)
    {
        return; // Base case: no nodes in this subtree
    }

    // Count left nodes
    if (root->left != nullptr)
    {
        leftCount = CountTotalNodesInBST(root->left); // Recursive count for left subtree
    }

    // Count right nodes
    if (root->right != nullptr)
    {
        rightCount = CountTotalNodesInBST(root->right); // Recursive count for right subtree
    }
}

bool IsBST(node *  root , int min , int max){
    if(root == nullptr){
        return true;
    }

    if(min < root->data && max > root->data){
        bool LeftCall = IsBST(root->left , min , root->data);
        bool RightCall = IsBST(root->right , root->data , max);
        return true;
    }
    else{
        return false;
    }
}


int solve(node * root , int &i , int k){
    if(root == nullptr){
        return -1;
    }

    //L
    int left = solve(root->left , i , k);

    if(left != -1){
        return left;
    }

    //N

    i++;
    if(i == k){
        return root->data;
    }

    //R

    return solve(root->right , i , k);
}

int KthSmallestValue(node * root , int k){
    int i = 0;
    int answer = solve(root , i , k);
    return answer;
}

int solveLargest(node* root, int &i, int k) {
    if (root == nullptr) {
        return -1; // Return -1 if the tree is empty or we don't find the k-th largest
    }

    // Traverse Right (reverse inorder: largest to smallest)
    int right = solveLargest(root->right, i, k);
    if (right != -1) {
        return right; // If right subtree has the k-th largest, return it
    }

    // Current Node (Inorder Position)
    i++;
    if (i == k) {
        return root->data; // Return the k-th largest node
    }

    // Traverse Left
    return solveLargest(root->left, i, k);
}

int KthLargestValue(node* root, int k) {
    int i = 0;
    return solveLargest(root, i, k); // Call solveLargest and return the result
}

void PrintRange(node* root, int k1, int k2) {
    if (root == nullptr) {
        return; // Base case: If the node is nullptr, return
    }

    if (k1 <= root->data) {
        PrintRange(root->left, k1, k2); // Recurse into the left subtree
    }

    if (k2 >= root->data) {
        PrintRange(root->right, k1, k2); // Recurse into the right subtree
    }

    if (k1 <= root->data && k2 >= root->data) {
        cout << root->data << " "; // Print the node's value
    }
}

int main()
{
    node *root = nullptr;
    cout << "Insert data into BST | -1 to terminate" << endl;
    TakeDataFromUser(root);
    PrintRange(root , 10 , 20);

    return 0;
}

//* 50 5 6 75 84 92 64 82 25 15 10 2 -1
// 50 5 6 75 84 92 64 82 25 2 -1