#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void ConcatenateList(Node*& FirstList, Node*& SecondList) {
    Node* temp1 = FirstList;
    while (temp1->next != FirstList) {  // Traverse to the last node of FirstList
        temp1 = temp1->next;
    }

    Node* temp2 = SecondList;
    while (temp2->next != SecondList) {  // Traverse to the last node of SecondList
        temp2 = temp2->next;
    }

    // Connect the last node of FirstList to the head of SecondList
    temp1->next = SecondList;

    // Connect the last node of SecondList to the head of FirstList
    temp2->next = FirstList;
}

void PrintCircularList(Node* head) {
    Node* temp = head;
    if (head == nullptr) return;

    do {
        cout << " - " << temp->data;
        temp = temp->next;
    } while (temp != head);
}

int main() {
    // Create First Circular Linked List
    Node* a = new Node();
    Node* b = new Node();
    Node* c = new Node();

    a->data = 1;
    b->data = 2;
    c->data = 3;

    a->next = b;
    b->next = c;
    c->next = a;

    // Create Second Circular Linked List
    Node* e = new Node();
    Node* f = new Node();
    Node* g = new Node();

    e->data = 4;
    f->data = 5;
    g->data = 6;

    e->next = f;
    f->next = g;
    g->next = e;

    cout << "First Circular Linked List: "<<endl;
    PrintCircularList(a);

    cout << endl;
    cout << "Second Circular Linked List: "<<endl;
    PrintCircularList(e);

    // Concatenate the two circular linked lists
    ConcatenateList(a, e);

    cout << endl;
    cout << "Concatenated Circular Linked List: "<<endl;
    PrintCircularList(a);

    return 0;
}