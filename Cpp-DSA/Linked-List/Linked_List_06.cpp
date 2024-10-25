//linked list deletion.
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

    return 0;
}