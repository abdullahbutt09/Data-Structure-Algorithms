#include <iostream>
using namespace std;

struct stack
{
    int size;
    int top;
    int *arr;
};

//struct function for creation of stack!
stack *createstack(int size)
{
    stack *mystack = new stack;
    mystack->size = size;
    mystack->top = -1;
    mystack->arr = new int[size];
    return mystack;
}

// Function for checking empty

bool CheckingStackIsEmpty(stack *MyStack)
{
    if (MyStack->top == -1)
    {
        return true;
    }
    return false;
}

// Function for checking full

bool CheckingStackIsFull(stack *MyStack)
{
    if (MyStack->size - 1 == MyStack->top)
    {
        return true;
    }
    return false;
}

// Function for pushing elements

void push(stack *MyStack)
{
    if (CheckingStackIsFull(MyStack))
    {
        cout << "Cannot Push because Stack is Full!" << endl;
        return;
    }

    else
    {
        int number;
        cout << "Enter Integer to push into the stack : ";
        cin >> number;
        MyStack->arr[MyStack->top++] = number;
        cout << endl;
        cout << "Element " << number << " pushed sucessfull!" << endl;
    }
}

// Function for poping element

int pop(stack *MyStack)
{
    if (CheckingStackIsEmpty(MyStack))
    {
        cout << "Stack Is Empty nothing to Pop!" << endl;
        return -1;
    }
    cout << "Successfully Poped Element " << MyStack->arr[--MyStack->top] << endl;
    return MyStack->arr[MyStack->top];
}

// Function for checking top most element

void TopMostElement(stack *MyStack)
{
    if (CheckingStackIsEmpty(MyStack))
    {
        cout << "Empty stack LOL!" << endl;
        return;
    }
    cout << MyStack->arr[MyStack->top] << endl;
}

// Function for checking bottom most element

void BottomMostElement(stack *MyStack)
{
    if (CheckingStackIsEmpty(MyStack))
    {
        cout << "Empty stack LOL!" << endl;
        return;
    }
    cout << MyStack->arr[0] << endl;
}

// Function for searching element in stack

void FindElementInStack(stack *MyStack)
{
    if (CheckingStackIsEmpty(MyStack))
    {
        cout << "Cannot search in empty stack!" << endl;
        return;
    }
    else
    {
        cout << "Enter the integer you want to search: ";
        int integer;
        cin >> integer;

        bool found = false;

        for (int i = MyStack->top; i >= -1; i--)
        {
            if (MyStack->arr[i] == integer)
            {
                cout << "Element " << MyStack->arr[i] << " found at index " << i << endl;
                found = true;
                break;
            }
        }

        if (!found)
        {
            cout << "Element not found!" << endl;
        }
    }
}

// Function for displaying stack

void display(stack *MyStack)
{
    if (CheckingStackIsEmpty(MyStack))
    {
        cout << "Nothing to display stack is empty!" << endl;
    }
    else
    {
        for (int i = -1; i < MyStack->top; i++)
        {
            cout << MyStack->arr[i] << endl;
        }
    }
}

int main()
{
    stack *MyStack = createstack(10);

    while (true)
    {
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "| stack size is currently " << MyStack->size << " |" << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Display" << endl;
        cout << "4. Top-Most-Element" << endl;
        cout << "5. Bottom-Most-Element" << endl;
        cout << "6. Checking stack is Full" << endl;
        cout << "7. Checking stack is empty" << endl;
        cout << "8. Searching Element In Stack" << endl;
        cout << "9. Exit" << endl;
        cout << endl;

        int choice;
        cout << "Enter your choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            push(MyStack);
            break;
        case 2:
            pop(MyStack);
            break;
        case 3:
            display(MyStack);
            break;
        case 4:
            TopMostElement(MyStack);
            break;
        case 5:
            BottomMostElement(MyStack);
            break;
        case 6:
            if (CheckingStackIsFull(MyStack))
            {
                cout << "stack is Full!" << endl;
            }
            else
            {
                cout << "Not Full!" << endl;
            }
            break;
        case 7:
            if (CheckingStackIsEmpty(MyStack))
            {
                cout << "stack is empty!" << endl;
            }
            else
            {
                cout << "Not empty!" << endl;
            }
            break;
        case 8:
            FindElementInStack(MyStack);
            break;
        case 9:
            exit(0);
        default:
            cout << "Wrong choice select in between 1-9" << endl;
            break;
        }
    }

    return 0;
}

//if you find any error or logic mistake just mail me at my mail address mention in ReadME file! peace.