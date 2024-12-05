#include <iostream>
#include <stack>
using namespace std;

struct node
{
    int data;
    node *next;
};

node *root = nullptr;

void AddNode(int data) // I use logic of insert at end!
{
    node *NewNode = new node();
    NewNode->next = nullptr;
    NewNode->data = data;

    if (root == nullptr)
    {
        root = NewNode;
        return;
    }

    node *temp = root;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = NewNode;
}

void PrintData()
{
    node *ptr = root;
    if (ptr == nullptr)
    {
        cout << "List is empty!" << endl;
        return;
    }
    cout << endl;
    while (ptr != nullptr)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

bool CheckingListIsPalindrome()
{
    node *temp = root;
    if (temp == nullptr || temp->next == nullptr)
    {
        return true;
    }

    stack<int> MyStack;

    while (temp != nullptr)
    {
        MyStack.push(temp->data);
        temp = temp->next;
    }

    temp = root;
    while (temp != nullptr && !MyStack.empty())
    {
        if (MyStack.top() != temp->data)
        {
            return false;
        }
        temp = temp->next;
        MyStack.pop();
    }

    return true;
}

int main()
{
    AddNode(1);
    AddNode(2);
    AddNode(3);
    AddNode(2);
    AddNode(1);
    PrintData();

    if (CheckingListIsPalindrome())
    {
        cout << endl;
        cout << "List Is palindrome" << endl;
    }
    else
    {
        cout << endl;
        cout << "Not palindrome list" << endl;
    }

    cout << endl;
    return 0;
}