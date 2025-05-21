#include<iostream>
#include<stack>
using namespace std;

struct queue{
    int data , front , back , size;
    int *arr;
};

queue * CreateQueue(int size){
    queue * myqueue = new queue;
    myqueue->back = -1;
    myqueue->front = -1;
    myqueue->size = size;
    myqueue->arr = new int[size];
    return myqueue;
}

bool IsEmpty(queue * myqueue){
    if(myqueue->front == myqueue->back){
        return true;
    }
    return false;
}

bool IsFull(queue * myqueue){
    if(myqueue->back == myqueue->size - 1){
        return true;
    }
    return false;
}

void Enqueue(queue * myqueue , int value){
    if(IsFull(myqueue)){
        cout << "Cannot enqueue queue is full"<<endl;
        return;
    }

    myqueue->arr[myqueue->back++] = value;
}

void Dequeue(queue * myqueue){
    if(IsEmpty(myqueue)){
        cout << "queue is empty"<<endl;
        return;
    }
    myqueue->front++;
}

void DisplayQueue(queue * myqueue){
    if(IsEmpty(myqueue)){
        cout << "queue is empty"<<endl;
        return;
    }

    for (int i = myqueue->front; i < myqueue->back; i++)
    {
        cout << "Queue Elements -> " << myqueue->arr[i] << endl;
    }
}

void ReverseQueue(queue * &myqueue){
    stack<int> st1;
    for (int i = myqueue->front; i < myqueue->back; i++)
    {
        st1.push(myqueue->arr[i]);
    }
    myqueue->back = -1;
    while (!st1.empty())
    {
        int value = st1.top();
        Enqueue(myqueue , value);
        st1.pop();
    } 
}

int main(){
    queue * MyQueue = CreateQueue(10);
    cout << endl;
    cout << "Enqueueing elements "<<endl;
    cout << endl;
    Enqueue(MyQueue , 7);
    Enqueue(MyQueue , 9);
    Enqueue(MyQueue , 10);
    Enqueue(MyQueue , 7);
    Enqueue(MyQueue , 189);
    
    DisplayQueue(MyQueue);
    cout << endl;
    cout << "Reversed Queue "<<endl;
    cout << endl;
    ReverseQueue(MyQueue);
    DisplayQueue(MyQueue);
    cout << endl;
    return 0;
}