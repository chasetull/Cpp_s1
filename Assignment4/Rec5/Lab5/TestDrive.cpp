//Test driver
#include <iostream>
#include "QueueLL.hpp"
using namespace std;

int main()
{
    QueueLL tqueue;

    cout << (tqueue.isEmpty() ? "yes." : "no.");
    cout << endl;

    tqueue.enqueue(7);
    cout << tqueue.peek() << endl;

    
    tqueue.enqueue(3);
    tqueue.dequeue();
    cout << tqueue.peek() << endl;

    tqueue.dequeue();

    cout << (tqueue.isEmpty() ? "yes." : "no.");
    cout << endl;

    return 0;
}