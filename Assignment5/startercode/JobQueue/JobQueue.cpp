#include "JobQueue.hpp"
#include <string>
#include <iostream>
using namespace std;

JobQueue::JobQueue()
{
    queueFront = 0;
    queueEnd = 0;
    counter = 0;
}

JobQueue::~JobQueue()
{
    while (!isEmpty())
    {
        dequeue();
    }
}

bool JobQueue::isEmpty()
{
    return (queueFront == 0);
}

bool JobQueue::isFull()
{
    return (queueFront == queueEnd);
}

void JobQueue::enqueue(std::string job)
{
    if (isEmpty())
    {
        queue[queueFront] = job;
        queueEnd++;
        counter++;
    }
}

void JobQueue::dequeue()
{
    if (isEmpty())
    {
        cout << "empty, nothing to dequeue" << endl;
    }
    else
    {
        /* code */
    }
    
}

std::string JobQueue::peek()
{
    string returnstr = "";
    if (isEmpty())
    {
        cout << "Queue empty, cannot peek" << endl;
    }
    else
    {
        returnstr = queueFront;
    }

    return returnstr;
}

int JobQueue::queueSize()
{
    return 0;
}

