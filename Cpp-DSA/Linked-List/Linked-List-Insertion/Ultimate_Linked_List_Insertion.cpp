#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};
node *head = nullptr;

void InsertNode()
{
    cout << endl;
    cout << "Insert Having 3 choices!" << endl;
    cout << endl;
    cout << "1. Insert at front" << endl;
    cout << "2. Insert at end" << endl;
    cout << "3. Insert at specific index" << endl;
    int choice;
    cout << endl;
    cout << "Enter Your Choice : ";
    cin >> choice;
    node *new_node = new node();
    cout << "Enter integer number to insert: ";
    cin >> new_node->data;
    cout << endl;

    if (head == nullptr)
    {
        head = new_node;
        return;
    }

    switch (choice)
    {
    case 1:
    {
        new_node->next = head;
        head = new_node;
        cout << "Insertion on front successfull!" << endl;
        break;
    }
    case 2:
    {
        new_node->next = nullptr;
        node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = new_node;
        cout << "Element insertion on last successfull!" << endl;
        cout << endl;
        break;
    }
    case 3:
    {
        int index;
        node *temp = head;
        cout << "Insert The index Number you want to insert element:";
        cin >> index;

        if (index <= 0)
        {
            cout << "Invalid index!" << endl;
            delete new_node; 
            return;
        }

        if (index == 1) //insert at index 1
        {
            new_node->next = head;
            head = new_node;
            cout << "Insertion at index 1 successful!" << endl;
            break;
        }

        for (int i = 1; i < index - 1; i++)
        {
            if (temp == nullptr)
            {
                cout << "Index out of bounds!" << endl;
                delete new_node; 
                return;
            }
            temp = temp->next;
        }

        new_node->next = temp->next;
        temp->next = new_node;
        break;
    }
    default:
        cout << "Invalid Choice!" << endl;
        delete new_node;
        break;
    }
}

void display()
{
    node *ptr = head;
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
    int condition = 0;

    do
    {
        cout << "1. Insert Node!" << endl;
        cout << "2. Display Nodes!" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> condition;

        switch (condition)
        {
        case 1:
            InsertNode();
            break;
        case 2:
            display();
            break;
        case 3:
            exit(0);
            break;
        default:
            cout << "Invalid choice!" << endl;
            break;
        }
    } while (condition != 3);
    return 0;
}