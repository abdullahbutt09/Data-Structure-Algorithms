#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

// Function to create nodes and return the head
node *CreateNodes()
{
    node *head = new node();
    return head; // Only create the head node initially
}

// Function to connect nodes and assign data
void ConnectNodes(node *head)
{
    node *one = new node();
    node *two = new node();
    node *three = new node();

    // Connect nodes and assign data
    head->data = 67;
    head->next = one;

    one->data = 45;
    one->next = two;

    two->data = 89; // Example data for the second node
    two->next = three;

    three->data = 100;  // Example data for the third node
    three->next = NULL; // Last node points to NULL
}

// Function to traverse the linked list and print its data
void LinkedListTraversal(node *ptr)
{
    while (ptr != NULL)
    {
        cout << ptr->data << endl;
        ptr = ptr->next;
    }
}

int main()
{
    node *head = CreateNodes(); // Create head node
    ConnectNodes(head);         // Connect nodes and assign data
    LinkedListTraversal(head);  // Traverse and print the linked list

    // Clean up memory
    // node *current = head;
    // while (current != NULL)
    // {
    //     node *nextNode = current->next;
    //     delete current;
    //     current = nextNode;
    // }

    return 0;
}
