//linked list deletion -> deleting first node.
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

void DeletingFirstNode(struct Node * &head){
    struct Node * ptr = head;
    head = head->next;
    delete ptr;
    // free(ptr);
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
    three->next = NULL; 
    cout << "Linked List before deleting the first node"<<endl;
    LinkedListTraversal(head); 
    DeletingFirstNode(head);
    cout << "Linked List after deleting the first node" << endl;
    LinkedListTraversal(head);

    return 0;
}