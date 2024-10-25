// insertion at beginning
#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

void LinkedListTraversal(struct node *ptr)
{
    while (ptr != NULL)
    {
        cout << ptr->data << endl;
        ptr = ptr->next;
    }
}

// Function to insert a new node at the beginning of the linked list
struct node *InsertBeginning(struct node *head)
{
    node *new_node = new node();
    new_node->data = 55689; // New data to be inserted
    new_node->next = head;  // Point new node's next to current head
    head = new_node;        // Update head to new node
    return head;            // Return new head
}

void CleanUpMemory(node *&head)
{
    node *current = head;
    node *nextNode;

    while (current != NULL) {
        nextNode = current->next; // Save the next node
        delete current;           // Delete the current node
        current = nextNode;       // Move to the next node
    }
    head = NULL; // Set head to NULL after cleanup
}

int main()
{
    node *head_node = new node();
    node *first_node = new node();
    node *sec_node = new node();
    node *third_node = new node();

    head_node->data = 78;
    head_node->next = first_node;

    first_node->data = 5;
    first_node->next = sec_node;

    sec_node->data = 67;
    sec_node->next = third_node;

    third_node->data = 455;
    third_node->next = NULL;

    cout << "List-list before inserting element on beginning" << endl;
    cout << endl;
    LinkedListTraversal(head_node);

    // Insert a new node at the beginning
    head_node = InsertBeginning(head_node);
    cout << endl;

    cout << "List-list after inserting element on beginning" << endl;
    cout << endl;
    LinkedListTraversal(head_node);

    CleanUpMemory(head_node);

    return 0;
}