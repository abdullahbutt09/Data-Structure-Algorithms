// insertion at deleting
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

void LinkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        cout << ptr->data << endl;
        ptr = ptr->next;
    }
}

struct Node *InsertAtEnd(struct Node *head)
{
    Node *current = head;

    Node *new_node = new Node();

    new_node->data = 12789;
    new_node->next = NULL;

    while (current->next != NULL)
    {
        current = current->next;
    }

    current->next = new_node;
    return head;
}

int main(){

    Node *head = new Node();
    Node *one = new Node();
    Node *two = new Node();
    Node *three = new Node();

    head->data = 45;  
    head->next = one; 

    one->data = 109;
    one->next = two;

    two->data = 245;
    two->next = three;

    three->data = 56;
    three->next = NULL; 

    cout << "List-list before inserting element on the end of the list" << endl;
    cout << endl;
    LinkedListTraversal(head);

    // Insert a new node at the the end of the list
    head = InsertAtEnd(head);

    cout << "List-list after inserting element on the end of the list" << endl;
    cout << endl;
    LinkedListTraversal(head);
    return 0;
}