#include <iostream>
using namespace std;

// Definition for a binary search tree node
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Function to insert a node in BST
Node* insert(Node* root, int key) {
    if (root == nullptr) {
        return new Node(key);
    }
    if (key < root->data) {
        root->left = insert(root->left, key);
    } else {
        root->right = insert(root->right, key);
    }
    return root;
}

// Function to calculate height of BST
int calculateHeight(Node* root) {
    if (root == nullptr) {
        return -1; // Height of empty tree
    }
    int leftHeight = calculateHeight(root->left);
    int rightHeight = calculateHeight(root->right);
    return max(leftHeight, rightHeight) + 1; // Add 1 for current node
}

// Example usage
int main() {
    Node* root = nullptr;

    // Insert nodes into BST
    int keys[] = {15, 10, 20, 8, 12, 17, 25, 6, 9, 11, 14, 16 , 30 , 35 , 40};
    for (int key : keys) {
        root = insert(root, key);
    }

    cout << "Height of BST: " << calculateHeight(root) << endl;
    return 0;
}
