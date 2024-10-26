// deleting last node.
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

void DeleteLastNode(struct Node *&head)
{
    struct Node *p = head;
    struct Node *q = head->next;
    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }

    p->next = NULL;
    delete q; 
}

int main()
{
    // creating nodes
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

    cout << "Linked List before deleting the last node. " << endl;
    LinkedListTraversal(head);
    DeleteLastNode(head);
    cout << "Linked List after deleting the last node. " << endl;
    LinkedListTraversal(head);

    return 0;
}
