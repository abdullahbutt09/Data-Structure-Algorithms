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
    if (myqueue->size - 1 == myqueue->back)
    {
        return true;
    }
    return false;
}

void InsertInQueue(queue *myqueue, int value)
{
    if (CheckingQueueIsFull(myqueue))
    {
        cout << "cannot insert element Queue is Full!" << endl;
        return;
    }

    if (myqueue->front == -1)
    { // If queue is empty, set front to 0
        myqueue->front = 0;
    }

    myqueue->arr[++myqueue->back] = value;
}

void DeleteElementFromQueue(queue *myqueue)
{
    if (CheckingQueueIsEmpty(myqueue))
    {
        cout << "Queue is empty!" << endl;
        return;
    }
    for (int i = ++myqueue->front; i >= myqueue->back; i--)
    {
        myqueue->arr[i] = myqueue->arr[i - 1];
    }
}

void DisplayTheQueue(queue *myqueue)
{
    if (CheckingQueueIsEmpty(myqueue))
    {
        cout << "Queue is empty!" << endl;
        return;
    }
    for (int i = myqueue->front; i <= myqueue->back; i++)
    {
        cout << myqueue->arr[i] << endl;
    }
}

// void ReversingQueue(queue *myqueue)
// {
//     int left = myqueue->front, right = myqueue->back;

//     // Reverse the elements between front and back
//     while (left < right)
//     {
//         // Swap the elements at left and right indices
//         int temp = myqueue->arr[left];
//         myqueue->arr[left] = myqueue->arr[right];
//         myqueue->arr[right] = temp;

//         // Move the pointers towards the center
//         left++;
//         right--;
//     }
// }

int main()
{
    queue *FirstQueue = MakingQueue(10);
    InsertInQueue(FirstQueue, 23);
    InsertInQueue(FirstQueue, 56);
    InsertInQueue(FirstQueue, 12);
    InsertInQueue(FirstQueue, 2);
    InsertInQueue(FirstQueue, 8);
    InsertInQueue(FirstQueue, 5);
    InsertInQueue(FirstQueue, 4);
    InsertInQueue(FirstQueue, 889);
    InsertInQueue(FirstQueue, 2990);
    InsertInQueue(FirstQueue, 2556);

    DisplayTheQueue(FirstQueue);

    DeleteElementFromQueue(FirstQueue);
    DeleteElementFromQueue(FirstQueue);
    DeleteElementFromQueue(FirstQueue);
    DeleteElementFromQueue(FirstQueue);
    DeleteElementFromQueue(FirstQueue);
    DeleteElementFromQueue(FirstQueue);
    DeleteElementFromQueue(FirstQueue);
    DeleteElementFromQueue(FirstQueue);
    DeleteElementFromQueue(FirstQueue);
    DeleteElementFromQueue(FirstQueue);
    
    InsertInQueue(FirstQueue, 69);
    DisplayTheQueue(FirstQueue);

    return 0;
}