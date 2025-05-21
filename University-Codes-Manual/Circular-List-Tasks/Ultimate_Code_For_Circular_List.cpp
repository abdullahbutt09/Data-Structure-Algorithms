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

void DeleteNodes()
{
    cout << endl;
    cout << "Delete Having 2 choices!" << endl;
    cout << endl;
    cout << "1. Delete at Front" << endl;
    cout << "2. Delete at End" << endl;
    cout << "3. Delete at position" << endl;
    cout << endl;
    int choice;
    cout << "Enter your choice -> ";
    cin >> choice;

    node *ptr = head;
    if (ptr == nullptr)
    {
        cout << "List is empty!" << endl;
        return;
    }

    if (head->next == head)
    {
        delete head;
        head = nullptr;
        return;
    }
    int position = 0;
    node *TraversalNode = head;
    node *StoringHead = head;
    node *Temp = head;
    node *Pre = nullptr;
    int count = 1;
    node* current = head;
    node* prev = nullptr;
    switch (choice)
    {
    case 1:
        do
        {
            TraversalNode = TraversalNode->next;
        } while (TraversalNode->next != head);
        TraversalNode->next = StoringHead->next;
        head = StoringHead->next;
        delete StoringHead;
        break;
    case 2:
        do
        {
            Pre = Temp;
            Temp = Temp->next;
        } while (Temp->next != head);
        Pre->next = head;
        delete Temp;
        break;
    case 3:
        cout << "Enter the position you want to delete";
        cin >> position;
        if (position == 1)
        {
            TraversalNode = head;
            StoringHead = head;
            do
            {
                TraversalNode = TraversalNode->next;
            } while (TraversalNode->next != head);
            TraversalNode->next = StoringHead->next;
            head = StoringHead->next;
            delete StoringHead;
        }
        do
        {
            prev = current;
            current = current->next;
            count++;
        } while (current != head && count < position);

        if (current == head) // Position out of range
        {
            cout << "Position out of range!" << endl;
            return;
        }
        // Update the links and delete the node
        prev->next = current->next;
        delete current;
        break;
    default:
        cout << "Not valid" << endl;
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

void SearchElement()
{
    if (head == nullptr)
    {
        cout << "No nodes Nothing to search!" << endl;
        return;
    }
    node *ptr = head;
    int value;
    cout << "Enter the value you want to search! -> ";
    cin >> value;

    do
    {
        if (ptr->data == value)
        {
            cout << endl;
            cout << "Value Founded!" << endl;
            cout << endl;
            return;
        }
        ptr = ptr->next;
    } while (ptr != head);
    cout << endl;
    cout << "Value Not Found!" << endl;
    cout << endl;
}

void CountLength()
{
    node *ptr = head;
    int count = 0;

    if (head == nullptr)
    {
        cout << endl;
        cout << "No nodes In list" << endl;
        cout << endl;
        return;
    }
    do
    {
        ptr = ptr->next;
        count++;
    } while (ptr != head);

    cout << endl;
    cout << "Length of list is -> " << count << endl;
    cout << endl;
}

int main()
{
    int condition = 0;

    do
    {
        cout << "1. Insert Node!" << endl;
        cout << "2. Delete Node!" << endl;
        cout << "3. Display Nodes!" << endl;
        cout << "4. Search Node By Value!" << endl;
        cout << "5. Find Length!" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> condition;

        switch (condition)
        {
        case 1:
            InsertNode();
            break;
        case 2:
            DeleteNodes();
            break;
        case 3:
            display();
            break;
        case 4:
            SearchElement();
            break;
        case 5:
            CountLength();
            break;
        case 6:
            exit(0);
            break;
        default:
            cout << "Invalid choice!" << endl;
            break;
        }
    } while (condition != 6);
    return 0;
}