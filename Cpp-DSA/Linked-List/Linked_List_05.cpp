// insertion after node
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

struct Node *InsertAfterNode(struct Node *previos_node, struct Node *head)
{
    Node *new_node = new Node();
    new_node->data = 110099;
    new_node->next = previos_node->next; // connecting old node with next.
    previos_node->next = new_node;       // now connecting prevoius_node to the new node.

    // add some more and clear explanation.😶

    return head;
}

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

    head->data = 45;
    head->next = one;

    one->data = 109;
    one->next = two;

    two->data = 245;
    two->next = three;

    three->data = 56;
    three->next = NULL;

    cout << "List-list after insertion after node of the list" << endl;
    cout << endl;

    LinkedListTraversal(head);

    head = InsertAfterNode(two, head);

    cout << "List-list after insertion after node of the list" << endl;
    cout << endl;

    LinkedListTraversal(head);
    return 0;
}