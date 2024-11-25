#include <iostream>
#include <stack>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Function to traverse and print the linked list
void LinkedListTraversal(Node* ptr) {
    while (ptr != NULL) {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

// Function to check if the linked list is a palindrome
bool isPalindrome(Node* head) {
    if (head == NULL || head->next == NULL){ 
    return true;  
    }

    stack<int> s;
    Node* current = head;

    while (current != NULL)
    {
        s.push(current->data);
        current = current->next;
    }
    
    current = head;

    while (current != NULL)
    {
        int top = s.top();
        s.pop();
        if (current->data != top)
        {
            return false;
        }
        current = current->next;
    }
    return true;
}

int main() {
    // Creating nodes
    Node* head = new Node();
    Node* one = new Node();
    Node* two = new Node();
    Node* three = new Node();

    head->data = 1;
    head->next = one;

    one->data = 2;
    one->next = two;

    two->data = 2;
    two->next = three;

    three->data = 1;
    three->next = NULL;  // Null indicates the end of the list

    // Check if the linked list is a palindrome
    if (isPalindrome(head)) {
        cout << "The linked list is a palindrome." << endl;
    } else {
        cout << "The linked list is not a palindrome." << endl;
    }

    return 0;
}