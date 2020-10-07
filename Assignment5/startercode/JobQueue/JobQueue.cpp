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
    return (counter == 0);
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
    else if (isFull())
    {
        cout << "Queue full, cannot queue" << endl;
    }
    else
    {
        queue[queueEnd] = job;
        queueEnd++;
        counter++;
        if (queueEnd > 29)
        {
            queueEnd = 0;
        }
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
        cout << "dequeue: " << queue[queueFront] << endl;
        queue[queueFront] = "";
        queueFront++;
        counter--;
        if (queueFront > 29) //potential to break?
        {
            queueFront = 0;
            queueEnd = 0;
        }
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
        returnstr = queue[queueFront];
    }

    return returnstr;
}

int JobQueue::queueSize()
{
    int returnSize;
    int gotQFront = getQueueFront();
    int gotQEnd = getQueueEnd();
    bool qFull = isFull();

    if (isEmpty())
    {
        returnSize = 0;
    }
    else if (gotQEnd == gotQFront+1) //one elem in arr?
    {
        returnSize = 1;
    }
    else if (qFull) //array full
    {
        returnSize = 20;
    }
    else
    {
        int indexDiff = gotQEnd - gotQFront;
        returnSize = indexDiff;
    }

    return returnSize;
}

