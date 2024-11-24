// insertion in between of lists
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

struct Node* InsertInBetween(struct Node * head, int index){

    Node * new_node = new Node();
    Node * p = head;
    int i = 0;

    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    new_node->data = 55555;

    new_node->next = p->next; // pointing new_node to the next node
    p->next = new_node;       // assigning previous node next to new_node
    
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

    cout << "List-list before inserting element in between of the list" << endl;
    cout << endl;
    
    LinkedListTraversal(head);

    head = InsertInBetween(head , 2);

    cout << "List-list after inserting element in between of the list" << endl;
    cout << endl;

    LinkedListTraversal(head);
    return 0;
}