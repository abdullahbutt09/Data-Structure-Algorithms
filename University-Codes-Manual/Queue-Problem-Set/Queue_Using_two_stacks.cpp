#include<iostream>
#include<stack>
using namespace std;

stack<int>MyStack1;
stack<int>MyStack2;

void Enqueue(int value){
    MyStack1.push(value);
    cout << "Value enqueued -> " << value<<endl;
}

int Dequeue(){
    while (MyStack2.empty())
    {
        if(MyStack1.empty()){
            cout << "cannot dequeue coz empty!"<<endl;
            return -1;
        }
        while (!MyStack1.empty()){
            MyStack2.push(MyStack1.top());
            MyStack1.pop();
        } 
    }
    int TopValue = MyStack2.top();
    MyStack2.pop();
    return TopValue;
}

bool CheckingEmpty(){
    if(MyStack1.empty() && MyStack2.empty()){
        return true;
    }
    return false;
}

int main(){

    Enqueue(126);
    Enqueue(234);
    Enqueue(980);
    Enqueue(345);
    Enqueue(222);

    cout << endl;
    cout << "Value dequeued -> " << Dequeue()<<endl;
    cout << "Value dequeued -> " << Dequeue()<<endl;
    cout << "Value dequeued -> " << Dequeue()<<endl;
    cout << "Value dequeued -> " << Dequeue()<<endl;
    cout << "Value dequeued -> " << Dequeue()<<endl;

    cout << endl;
    cout << "Value dequeued -> " << Dequeue();
    return 0;
}