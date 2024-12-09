#include <iostream>
using namespace std;

struct PriorityQueue
{
    int size, front, back;
    string *arr;
    int *priorityArr;
};

PriorityQueue *MakingQueue(int Size)
{
    PriorityQueue *pq = new PriorityQueue;
    pq->front = -1;
    pq->back = -1;
    pq->size = Size;
    pq->arr = new string[Size];
    pq->priorityArr = new int[Size];
    return pq;
}

bool CheckingQueueIsEmpty(PriorityQueue *pq)
{
    return pq->front == pq->back;
}

bool CheckingQueueIsFull(PriorityQueue *pq)
{
    return pq->back == pq->size - 1;
}

void Enqueue(PriorityQueue *pq, string value, int priority)
{
    if (CheckingQueueIsFull(pq))
    {
        cout << "Cannot insert element. Queue is full!" << endl;
        return;
    }

    pq->arr[++pq->back] = value;
    pq->priorityArr[pq->back] = priority;
}

void Dequeue(PriorityQueue *pq)
{
    if (CheckingQueueIsEmpty(pq))
    {
        cout << "Empty Queue!" << endl;
        return;
    }

    // int LowestPriorityIndex = pq->back; replace > to <
    int LowestPriorityIndex = pq->front;

    for (int i = pq->front + 1; i <= pq->back; i++)
    {
        if (pq->priorityArr[i] > pq->priorityArr[LowestPriorityIndex])
        {
            LowestPriorityIndex = i;
        }
    }

    cout << "Removed element: " << pq->arr[LowestPriorityIndex] << " with priority: " << pq->priorityArr[LowestPriorityIndex] << endl;

    for (int i = LowestPriorityIndex; i < pq->back; ++i)
    {
        pq->arr[i] = pq->arr[i + 1];
        pq->priorityArr[i] = pq->priorityArr[i + 1];
    }

    pq->back--;
}

void DisplayTheQueue(PriorityQueue *pq)
{
    if (CheckingQueueIsEmpty(pq))
    {
        cout << "Queue is empty!" << endl;
        return;
    }

    cout << "Queue contents (Name - priority):" << endl;
    for (int i = pq->front + 1; i <= pq->back; ++i)
    {
        cout << pq->arr[i] << " - " << pq->priorityArr[i] << endl;
    }
}

int main()
{
    PriorityQueue *pq = MakingQueue(10);

    Enqueue(pq, "abdullah", 45);
    Enqueue(pq, "zain", 8);
    Enqueue(pq, "malik", 3);

    DisplayTheQueue(pq);
    Dequeue(pq);
    return 0;
}