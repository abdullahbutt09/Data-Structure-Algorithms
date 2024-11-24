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
        new_node->next = head;
        cout << "List was empty. Inserted first node!" << endl;
        return;
    }

    switch (choice)
    {
    case 1:
    {
        new_node->next = head;
        node *temp = head;
        do
        {
            temp = temp->next;
        } while (temp->next != head);
        temp->next = new_node;
        head = new_node;

        cout << "Insertion on front successfull!" << endl;
        break;
    }
    case 2:
    {
        node *temp = head;
        do
        {
            temp = temp->next;
        } while (temp->next != head);
        temp->next = new_node;
        new_node->next = head;
        // node *temp = head;
        // while (temp->next != head)
        // {
        //     temp = temp->next;
        // }
        // temp->next = new_node; 
        // new_node->next = head;

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

        if (index == 1) // insert at index 1
        {
            new_node->next = head;
            node *temp = head;
            do
            {
                temp = temp->next;
            } while (temp != head);
            temp->next = new_node;
            head = new_node;
            cout << "Insertion at index 1 successful!" << endl;
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
    if (ptr == nullptr)
    {
        cout << "List is empty!" << endl;
        return;
    }

    node *temp = ptr;
    cout << endl;
    do
    {
        cout << "Linked-List data -> " << temp->data << endl;
        temp = temp->next;
        cout << endl;
    } while (temp != ptr);
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