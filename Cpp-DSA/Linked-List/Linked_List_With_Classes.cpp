#include <iostream>
using namespace std;

class linked_list
{
private:
    struct node
    {
        int data;
        node *next;
    };
    node *head = nullptr;

public:
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

        if (head == nullptr)
        {
            head = new_node;
            return;
        }

        if (choice == 1)
        {
            new_node->next = head;
            head = new_node;
            return;
        }

        else if (choice == 2)
        {
            new_node->next = nullptr;
            node *temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = new_node;
            cout << "Element insertion on last successfull!" << endl;
            return;
        }

        else if (choice == 3)
        {
            int index;
            node *temp = head;
            cout << "Insert The index Number you want to insert element:" << endl;
            cin >> index;
            for (int i = 1; i < index - 1; i++)
            {
                temp = temp->next;
            }
            new_node->next = temp->next;
            temp->next = new_node;
            return;
        }

        else
        {
            cout << "IDK what u click!" << endl;
        }
    }

    void display()
    {
        node *ptr = head;
        cout << endl;
        if (ptr == nullptr)
        {
            cout << "List is empty!" << endl;
        }
        while (ptr != nullptr)
        {
            cout << "Linked-List Data -> " << ptr->data << endl;
            ptr = ptr->next;
            cout << endl;
        }
    }
};

int main()
{
    linked_list link;
    int condition = 0;

    do
    {
        cout << "1. Insert Node!" << endl;
        cout << "2. Display Nodes!" << endl;
        cout << "Enter your choice: ";
        cin >> condition;

        switch (condition)
        {
        case 1:
            link.InsertNode();
            break;
        case 2:
            link.display();
            break;

        default:
            cout << "Invalid choice!" << endl;
            break;
        }
    } while (condition != 3);
    return 0;
}