#include <iostream>
using namespace std;

struct Stack
{
    int size;
    int top;
    int *arr;
};

// Function to create a stack
Stack *createStack(int size)
{
    Stack *stack = new Stack;
    stack->size = size;
    stack->top = -1;
    stack->arr = new int[size];
    return stack;
}

// Function to check if the stack is full
bool isFull(Stack *s)
{
    return s->top == s->size - 1;
}

// Function to check if the stack is empty
bool isEmpty(Stack *s)
{
    return s->top == -1;
}

// Function to push an element onto the stack
void push(Stack *s, int value)
{
    if (!isFull(s))
    {
        s->arr[++s->top] = value;
    }
    else
    {
        cout << "Stack is full!" << endl;
    }
}

// Function to pop an element from the stack
int pop(Stack *s)
{
    if (!isEmpty(s))
    {
        return s->arr[s->top--];
    }
    else
    {
        cout << "Stack is empty!" << endl;
        return -1; // Error value
    }
}

// Function to reverse the stack
void reverseStack(Stack *source, Stack *destination)
{
    while (!isEmpty(source))
    {
        int value = pop(source);
        push(destination, value);
    }
}

// Function to display stack elements
void displayStack(Stack *s)
{
    if (isEmpty(s))
    {
        cout << "Stack is empty!" << endl;
        return;
    }
    cout << "Stack elements:" << endl;
    for (int i = 0; i <= s->top; i++)
    {
        cout << s->arr[i] << endl;
    }
}

// Function to free allocated memory
void freeStack(Stack *s)
{
    delete[] s->arr; // Free the array
    delete s;        // Free the structure
}

int main()
{
    // Create a source stack and push some elements
    Stack *sourceStack = createStack(5);
    push(sourceStack, 10);
    push(sourceStack, 20);
    push(sourceStack, 30);
    push(sourceStack, 40);
    push(sourceStack, 50);

    cout << "Source Stack:" << endl;
    displayStack(sourceStack);

    // Create a destination stack to hold reversed elements
    Stack *destinationStack = createStack(5);

    // Reverse the source stack into the destination stack
    reverseStack(sourceStack, destinationStack);

    cout << "Destination Stack after reversing:" << endl;
    displayStack(destinationStack);

    // Clean up memory
    freeStack(sourceStack);
    freeStack(destinationStack);

    return 0;
}