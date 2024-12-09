#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

node *top = nullptr;

bool IfEmpty()
{
    if (top == nullptr)
    {
        return true;
    }
    return false;
}

bool IfFull()
{
    node *temp = new node();
    if (temp == nullptr)
    {
        return true;
    }
    return false;
}

void push(int data)
{
    if (IfFull())
    {
        cout << "cannot push elements into stack coz its full!" << endl;
        return;
    }
    else
    {
        node *NewNode = new node();
        NewNode->data = data;
        NewNode->next = top;
        top = NewNode;
    }
}

int pop()
{
    if (IfEmpty())
    {
        cout << "Stack underflow!" << endl;
        return 0;
    }
    else
    {
        node * temp = top;
        int value = top->data;
        top = top->next;
        delete temp;
        return value;
    }
}

void display()
{
    node *ptr = top;
    cout << endl;
    if (ptr == nullptr)
    {
        cout << "List is empty!" << endl;
        cout << endl;
    }
    while (ptr != nullptr)
    {
        cout << "Linked-List Data -> " << ptr->data << endl;
        ptr = ptr->next;
        cout << endl;
    }
}

int main()
{
    push(5);
    push(6);
    display();
    cout << "successfully poped value: " << pop() << endl;
    cout << "successfully poped value: " << pop() << endl;
    display();

    return 0;
}