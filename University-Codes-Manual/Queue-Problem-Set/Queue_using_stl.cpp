#include<iostream>
#include<queue>
using namespace std;
int main(){
    queue<int> q;
    q.push(100);
    q.push(200);
    q.push(300);
    q.push(400);
    q.push(500);
    queue<int> tempq = q;
    cout << "size of queue -> " << q.size()<<endl;

    q.pop();
    q.pop();
    q.pop();
    q.pop();
    cout << q.front() << endl;

    while (!tempq.empty())
    {
        cout << tempq.front() << endl;
        tempq.pop();
    }
    
    return 0;
}