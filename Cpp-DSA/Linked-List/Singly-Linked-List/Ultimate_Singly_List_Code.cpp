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

        if (index == 1) // insert at index 1
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

void DeleteNodes()
{
    int index;

    cout << endl;
    cout << "Delete Having 3 choices!" << endl;
    cout << endl;
    cout << "1. Delete at front" << endl;
    cout << "2. Delete at end" << endl;
    cout << "3. Delete at specific index" << endl;
    int choice;
    cout << endl;
    cout << "Enter Your Choice : ";
    cin >> choice;

    if (head == nullptr)
    {
        cout << "Nothing to delete!" << endl;
        return;
    }

    node *ptr = head;
    node *temp1 = head;
    node *temp2 = head->next;
    node *temp3 = head;
    node *temp4 = head->next;

    switch (choice)
    {
    case 1:
        head = head->next;
        delete ptr;
        break;
    case 2:
        while (temp2->next != nullptr)
        {
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        temp1->next = nullptr;
        delete temp2;
        break;
    case 3:

        cout << "Enter index number you want to delete the node -> ";
        cin >> index;

        for (int i = 1; i < index - 1; i++)
        {
            temp3 = temp3->next;
            temp4 = temp4->next;
        }

        temp3->next = temp4->next;
        delete temp4;
        break;
    default:
        cout << "Invalid choice!" << endl;
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

void reverselist()
{
    node *PreviousNode = nullptr;
    node *CurrentNode = head;
    node *NextNode = nullptr;

    if(head == nullptr){
        cout << endl;
        cout << "nothing to reverse."<<endl;
        cout << endl;
        return;
    }
    if(head->next == nullptr){
        cout << endl;
        cout << "Reversed List -> " << head->data << endl;
        cout << endl;
        return;
    }

    while (CurrentNode != nullptr)
    {
        NextNode = CurrentNode->next;
        CurrentNode->next = PreviousNode;
        PreviousNode = CurrentNode;
        CurrentNode = NextNode;
    }
    head = PreviousNode;

    node *ptr = head;
    while (ptr != nullptr)
    {
        cout << "Linked-List Data -> " << ptr->data << endl;
        ptr = ptr->next;
        cout << endl;
    }
}

void SearchInList()
{
    if (head == nullptr)
    {
        cout << endl;
        cout << "No data in list nothing to search!" << endl;
        cout <<endl;
        return;
    }
    node *ptr = head;
    cout << "Enter the value you want to search : ";
    int value, count = 0;
    cin >> value;

    while (ptr != nullptr)
    {
        ++count;
        if (value == ptr->data)
        {
            cout << endl;
            cout << "Value found " << value << " at position " << count << endl;
            cout << endl;
            return;
        }
        ptr = ptr->next;
    }
}

void FindMiddleNode(){
    if (head == nullptr)
    {
        cout << endl;
        cout << "No data in list!" << endl;
        cout <<endl;
        return;
    }

    node * temp = head;
    int count = 0;

    while (temp != nullptr)
    {
        temp = temp->next;
        count++;
    }

    temp = head; // reseting the node

    int Index = count / 2;

    for (int i = 0; i < Index; i++)
    {
        temp = temp->next;
    }
    
    cout << endl;
    cout << "The middle node is : "<< temp->data << endl;
    cout << endl;
}

void SortSinglyList(){
    if(head == nullptr){
        cout << "Nothing to sort"<<endl;
    }

    if(head->next == nullptr){
        cout << "Sorted List " << endl;
        cout << head->data << endl;
    }

    bool swapped;

    do {
    swapped = false;
    node* current = head;

        while (current->next != nullptr) {
            if (current->data > current->next->data) {
                int temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
                swapped = true;
            }
            current = current->next;
        }
    } while (swapped); // Repeat until no swaps are needed
}

int main()
{
    cout << endl; 
    int condition = 0;

    do
    {
        cout << "1. Insert Nodes!" << endl;
        cout << "2. Delete Nodes!" << endl;
        cout << "3. Display Nodes!" << endl;
        cout << "4. To reverse Linked-List!" << endl;
        cout << "5. Search For Value!" << endl;
        cout << "6. Find Middle Node!" << endl;
        cout << "7. Sort Linked List!" << endl;
        cout << "8. Exit" << endl;
        cout << endl;
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
            reverselist();
            break;
        case 5:
            SearchInList();
            break;
        case 6:
            FindMiddleNode();
            break;
        case 7:
            SortSinglyList();
            break;
        case 8:
            exit(0);
            break;
        default:
            cout << "Invalid choice!" << endl;
            break;
        }
    } while (condition != 10);
    return 0;
}