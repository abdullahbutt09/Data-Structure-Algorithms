//deleting node by index.

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

void LinkedListTraversal(struct Node *ptr)
{
    int i = 0;
    while (ptr != NULL)
    {
        cout << "element: " << i << " " << ptr->data << endl;
        ptr = ptr->next;
        i++;
    }
}

void DeletingNodeByIndex(struct Node *&head , int index)
{
   struct Node * p = head;
   struct Node * q = head->next;

   for (int i = 0; i < index - 1; i++)
   {
        p = p->next;
        q = q->next;
   }
   
   p->next = q->next;
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

    cout << "Linked List before deleting the node on index " << endl;
    LinkedListTraversal(head);

    int index = 1;
    cout << "Linked List after deleting the node on index " << index << endl;
    DeletingNodeByIndex(head , index);
    LinkedListTraversal(head);

    return 0;
}
