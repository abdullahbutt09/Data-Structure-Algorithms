// Delete By Value.

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

void DeleteByValue(struct Node *&head, int value)
{
    struct Node *p = head;
    struct Node *q = head->next;

    while (head != NULL && head->data == value)
    {
        head = head->next; // Move head to next node
        delete p;       // Delete old head
        return;
    }

    while (q->data != value && q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    if (q->data == value)
    {
        p->next = q->next;
        delete q;
        return;
    }

    cout << "NOT SUCH VALUE PRESENT IN LINKED LIST : " << value<<endl;
    
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

    int value = 4775;
    cout << "Linked List before deleting the node by value " << value << endl;
    LinkedListTraversal(head);

    cout << "Linked List before deleting the node by value " << value << endl;
    DeleteByValue(head, value);
    LinkedListTraversal(head);

    return 0;
}
