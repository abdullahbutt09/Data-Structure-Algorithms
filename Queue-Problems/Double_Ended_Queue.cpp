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
    MyQueue->front = -1;
    MyQueue->back = -1;
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
    if (myqueue->back == myqueue->size - 1)
    {
        return true;
    }
    return false;
}

void EnqueueOnFront(queue *myqueue)
{
    if (myqueue->front < 0)
    {
        cout << endl;
        cout << "CANNOT PUSH ELEMENT FROM FRONT BECAUSE FRONT IS CURRENTLY -1 OR QUEUE IS FULL!!!" << endl;
        cout << endl;
        return;
    }
    int value = 0;
    cout << "ENTER AN INTEGER NUMBER : ";
    cin >> value;
    --myqueue->front;
    cout << endl;
    cout << "SUCCESSFULLY EN-QUEUED ELEMENT " << value << " ON FRONT!" << endl;
    cout << endl;
    myqueue->arr[myqueue->front] = value;
}

void EnqueueOnBack(queue *myqueue)
{
    if (CheckingQueueIsFull(myqueue))
    {
        cout << endl;
        cout << "CANNOT INSERT ELEMENT QUEUE IS FULL!!!" << endl;
        cout << endl;
        return;
    }
    int value = 0;
    cout << "ENTER AN INTEGER NUMBER : ";
    cin >> value;
    cout << endl;
    cout << "SUCCESSFULLY EN-QUEUED ELEMENT " << value << " ON BACK!" << endl;
    cout << endl;
    myqueue->arr[myqueue->back++] = value;
}

int DequeueFromFront(queue *myqueue)
{
    if (CheckingQueueIsEmpty(myqueue))
    {
        cout << endl;
        cout << "QUEUE IS EMPTY!!!" << endl;
        cout << endl;
        return 0;
    }
    return myqueue->arr[myqueue->front++];
}

int DequeueFromBack(queue *myqueue)
{
    if (CheckingQueueIsEmpty(myqueue))
    {
        cout << endl;
        cout << "QUEUE IS EMPTY!!!" << endl;
        cout << endl;
        return 0;
    }
    return myqueue->arr[--myqueue->back];
}

void DisplayTheQueue(queue *myqueue)
{
    if (CheckingQueueIsEmpty(myqueue))
    {
        cout << endl;
        cout << "QUEUE IS EMPTY!!!" << endl;
        cout << endl;
        return;
    }
    cout << endl;
    for (int i = myqueue->front; i < myqueue->back; i++)
    {
        cout << "DOUBLE ENDED-QUEUE ELEMENTS -> " << myqueue->arr[i] << endl;
        cout << endl;
    }
}

int main()
{
    queue *FirstQueue = MakingQueue(5);

    cout << endl;
    cout << "\t ~~~~~~~~ Currently Size Of Double Ended-Queue is " << FirstQueue->size << " ~~~~~~~~" << endl;
    cout << endl;

    int choice = 0;

    cout << "Welcome to double ended queue Code!" << endl;
    cout << endl;
    cout << "This queue has 5 major choices!" << endl;
    cout << endl;

    do
    {
        cout << "1. Insert On Back!" << endl;
        cout << "2. Insert On Front!" << endl;
        cout << "3. Delete From Back!" << endl;
        cout << "4. Delete From Front!" << endl;
        cout << "5. Display The Queue!" << endl;
        cout << "6. Exit!" << endl;
        cout << endl;
        cout << "Enter your choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            EnqueueOnBack(FirstQueue);
            break;
        case 2:
            EnqueueOnFront(FirstQueue);
            break;
        case 3:
            cout << endl;
            cout << "SUCESSFULLY DE-QUEUED ELEMENT FROM BACK: " << DequeueFromBack(FirstQueue) << endl;
            cout << endl;
            break;
        case 4:
            cout << endl;
            cout << "SUCESSFULLY DE-QUEUED ELEMENT FROM FRONT: " << DequeueFromFront(FirstQueue) << endl;
            cout << endl;
            break;
        case 5:
            DisplayTheQueue(FirstQueue);
            break;
        case 6:
            delete[] FirstQueue->arr;
            delete FirstQueue;
            exit(0);
            break;
        default:
            cout << endl;
            cout << "Invalid Choice!" << endl;
            cout << endl;
            break;
        }
    } while (choice != 6);

    return 0;
}

// If anyone found any type of syntax & logical error kindly report me the issue through mail. My email is provided in My README FILE!

// Peace.