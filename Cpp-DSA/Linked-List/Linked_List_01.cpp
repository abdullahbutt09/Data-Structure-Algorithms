#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

void LinkedListTraversal(struct Node* ptr)
{
    while (ptr != NULL)
    {
        cout << ptr->data<<endl;
        ptr = ptr->next;
    }
    
};

int main()
{
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

    LinkedListTraversal(head);

    return 0;
}