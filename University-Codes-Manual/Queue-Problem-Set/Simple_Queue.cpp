#include<iostream>
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
    cout << "Successfully enqueue value -> " << value << endl;
}

void Dequeue(queue * myqueue){
    if(IsEmpty(myqueue)){
        cout << "queue is empty"<<endl;
        return;
    }
    cout << "successfully dequeue value -> " << myqueue->arr[myqueue->front++] << endl;
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
int main(){
    queue * MyQueue = CreateQueue(10);
    Enqueue(MyQueue , 7);
    Enqueue(MyQueue , 9);
    Enqueue(MyQueue , 10);
    Enqueue(MyQueue , 7);
    Enqueue(MyQueue , 189);
    cout << endl;
    
    DisplayQueue(MyQueue);
    cout << endl;
    
    Dequeue(MyQueue);
    Dequeue(MyQueue);
    Dequeue(MyQueue);
    Dequeue(MyQueue);
    cout << endl;
    cout << "New queue elements"<<endl;
    cout << endl;
    DisplayQueue(MyQueue);
    cout << endl;
    return 0;
}