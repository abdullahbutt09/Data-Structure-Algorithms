#include <iostream>
using namespace std;

struct queue
{
    int data, front, back, size = 0;
    int *arr;
};

queue *MakingQueue(int Size)
{
    queue *MyQueue = new queue;
    MyQueue->front = 0;
    MyQueue->back = 0;
    MyQueue->size = Size;
    MyQueue->arr = new int[Size];
    return MyQueue;
}

bool CheckingQueueIsEmpty(queue *myqueue)
{
    if (myqueue->front == myqueue->back)
    {
        return true;
    }
    return false;
}

bool CheckingQueueIsFull(queue *myqueue)
{
    if ((myqueue->back + 1) % myqueue->size == myqueue->front)
    {
        return true;
    }
    return false;
}

void Enqueue(queue *myqueue, int value)
{
    if (CheckingQueueIsFull(myqueue))
    {
        cout << "ALERT QUEUE IS FULL" << endl;
        return;
    }
    myqueue->arr[myqueue->back] = value;
    myqueue->back = (myqueue->back + 1) % myqueue->size;
}

int Dequeue(queue *myqueue)
{
    if (CheckingQueueIsEmpty(myqueue))
    {
        cout << "ALERT QUEUE IS empty" << endl;
        return -1;
    }
    else
    {
        int value = myqueue->arr[myqueue->front];
        myqueue->front = (myqueue->front + 1) % myqueue->size;
        return value;
    }
}

void DisplayTheQueue(queue *myqueue)
{
    if (CheckingQueueIsEmpty(myqueue))
    {
        cout << "Queue is empty!" << endl;
        return;
    }
    for (int i = myqueue->front; i != myqueue->back;)
    {
        cout << myqueue->arr[i] << endl;
        i = (i + 1) % myqueue->size;
    }
}

int main()
{
    cout << endl;
    queue *FirstQueue = MakingQueue(5);
    Enqueue(FirstQueue, 78);
    Enqueue(FirstQueue, 67);
    Enqueue(FirstQueue, 30);
    Enqueue(FirstQueue, 63);
    cout << "Adding starting elements of queue:" << endl;
    DisplayTheQueue(FirstQueue);
    cout << endl;

    cout << "Dequeing Element : " << Dequeue(FirstQueue) << endl;
    cout << "Dequeing Element : " << Dequeue(FirstQueue) << endl;
    cout << "Dequeing Element : " << Dequeue(FirstQueue) << endl;
    cout << "Dequeing Element : " << Dequeue(FirstQueue) << endl;
    cout << endl;
    DisplayTheQueue(FirstQueue);

    cout << endl;

    cout << "Adding new elements in queue!" << endl;
    Enqueue(FirstQueue, 71);
    Enqueue(FirstQueue, 72);
    Enqueue(FirstQueue, 33);
    Enqueue(FirstQueue, 36);
    DisplayTheQueue(FirstQueue);
    cout << endl;

    cout << "Dequeing Element : " << Dequeue(FirstQueue) << endl;
    cout << "Dequeing Element : " << Dequeue(FirstQueue) << endl;
    cout << "Dequeing Element : " << Dequeue(FirstQueue) << endl;
    cout << "Dequeing Element : " << Dequeue(FirstQueue) << endl;
    cout << endl;
    DisplayTheQueue(FirstQueue);
    return 0;
}