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

void reverselist(struct Node *head)
{
    Node *pre = NULL;
    Node *current = head;
    Node *next = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = pre;
        pre = current;
        current = next;
    }
    head = pre;

    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
}

int main()
{
    // creating nodes
    Node *head = new Node();
    Node *one = new Node();
    Node *two = new Node();
    Node *three = new Node();

    head->data = 45;  // storing data in linked list
    head->next = one; // storing the address of next node element

    one->data = 109;
    one->next = two;

    two->data = 245;
    two->next = three;

    three->data = 56;
    three->next = NULL; // NULL indicates that the list END!

    LinkedListTraversal(head); // Function for printing the stored elements in linked-list by giving head to it and traversing to the NULL means -> head != NULL;
    cout << "reverse linked list : " << endl;
    reverselist(head);

    return 0;
}
