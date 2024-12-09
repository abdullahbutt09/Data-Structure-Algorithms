/*      -REVERSING STACK WITH THE HELP OF RECURSION!-        */

#include <iostream>
#include <stack>
using namespace std;

// function declaration!
void InsertAtBottom(stack<int> &, int);
void ReversingStack(stack<int> &);

void InsertAtBottom(stack<int> &mystack, int number)
{
    if (mystack.empty())
    {
        mystack.push(number);
        return;
    }

    int LastNumberOfStack = mystack.top();
    mystack.pop();
    InsertAtBottom(mystack, number);
    mystack.push(LastNumberOfStack);
}

void ReversingStack(stack<int> &mystack)
{
    if (mystack.empty())
    {
        return;
    }
    int TempNumber = mystack.top();
    mystack.pop();

    ReversingStack(mystack);
    InsertAtBottom(mystack, TempNumber);
}

int main()
{
    stack<int> mystack;

    mystack.push(14);
    mystack.push(16);
    mystack.push(23);
    mystack.push(40);
    mystack.push(90);

    // sabse pehle 500 bahir aye ga LIFO -> last in first out!

    stack<int> temp = mystack;

    cout << endl;
    cout << "Original stack : ";
    while (!temp.empty())
    {
        cout << temp.top() << " ";
        temp.pop();
    }

    cout << endl;
    cout << endl;
    cout << "Reversed stack : ";

    ReversingStack(mystack);

    while (!mystack.empty())
    {
        cout << mystack.top() << " ";
        mystack.pop();
    }
    cout << endl;
    cout << endl;

    return 0;
}

/*

NOTE -> copying stack just because when i pop elements from the original stack for displaying it will effect the original stack so i cannot pass the stack to reverse stack function!

Using temp stack and copying it from mystack and using temp just to display elements of the original stack so when i pop elements from the temp stack it will not effect the original stack!

*/