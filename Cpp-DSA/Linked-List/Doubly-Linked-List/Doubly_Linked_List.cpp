#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
    node *prev;
};

node *head = nullptr;

void PrintList()
{
    if (head == nullptr)
    {
        cout << endl;
        cout << "List empty!" << endl;
        return;
    }

    node *ptr = head;
    cout << endl;
    cout << "\t \t \t Simple Doubly List." << endl;
    cout << endl;
    while (ptr != nullptr)
    {
        cout << " \t " << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;

    node *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    cout << endl;
    cout << "\t \t \t Reverse Doubly List." << endl;
    cout << endl;
    while (temp != nullptr)
    {
        cout << " \t " << temp->data << " ";
        temp = temp->prev;
    }
    cout << endl;
}

void InsertNodeEnd(int key)
{
    node *StartingNode = new node();
    StartingNode->data = key;
    StartingNode->next = nullptr;
    StartingNode->prev = nullptr;

    if (head == nullptr)
    {
        head = StartingNode;
        return;
    }

    node *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = StartingNode;
    StartingNode->prev = temp;
}

void InsertNodeFront(int key)
{
    node *NewNode = new node();
    NewNode->data = key;
    if (head == nullptr)
    {
        head = NewNode;
        return;
    }
    NewNode->next = head;
    head->prev = NewNode;
    head = NewNode;
    NewNode->prev = nullptr;
}

void InsertNodeSpecificPosition(int key, int position)
{
    node *NewNode = new node();
    NewNode->data = key;

    node *temp = head;
    node *temp2 = head->next;
    if (head == nullptr)
    {
        head = NewNode;
        return;
    }

    if (position == 1)
    {
        InsertNodeFront(key);
        return;
    }

    for (int i = 1; i < position - 1; i++)
    {
        temp = temp->next;
        temp2 = temp2->next;
    }

    if (temp2 == nullptr)
    {
        cout << "Position nahi mele " << endl;
        return;
    }

    if (temp->next == nullptr)
    {
        InsertNodeEnd(key);
        return;
    }

    temp->next = NewNode;
    NewNode->prev = temp;
    NewNode->next = temp2;
    temp2->prev = NewNode;
}

void DeleteFrontNode()
{
    head = head->next;
    head->prev = nullptr;
    delete head;
}

void DeleteEndNode1()
{ // approach 1

    if (head == nullptr)
    {
        cout << "List empty Nothing to delete" << endl;
        return;
    }

    if (head->next == nullptr) {
        // Only one node in the list
        delete head;
        head = nullptr;
        return;
    }

    node *temp = head;

    while (temp->next != nullptr)
    {
        temp = temp->next;
    }

    temp->prev->next = nullptr;
    delete temp;
}

void DeleteEndNode2()
{ // approach 2

    if (head == nullptr)
    {
        cout << "List empty Nothing to delete" << endl;
        return;
    }
    node *temp = head;

    while (temp->next->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = nullptr;
    delete temp->next;
}

void DeleteSpecificPosition(int position){
    // last function remaining
}

int main()
{
    InsertNodeEnd(45);
    InsertNodeEnd(50);
    InsertNodeEnd(75);
    InsertNodeEnd(85);
    InsertNodeEnd(100);

    PrintList();
    DeleteSpecificPosition(5);
    PrintList();

    cout << endl;
    return 0;
}