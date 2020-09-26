#include <iostream>
#include "QueueLL.hpp"

using namespace std;

QueueLL::QueueLL()
{
    queueFront = nullptr;
    queueEnd = nullptr;
}

QueueLL::~QueueLL()
{
    while( !isEmpty() )
        dequeue();
}

bool QueueLL::isEmpty()
{
    /*if(queueFront == nullptr || queueEnd == nullptr)
        return true;
    return false;*/
    return (!queueFront || !queueEnd);
}

// TODO
void QueueLL::enqueue(int key)
{
    Node *nn = new Node;
    nn->key = key;
    nn->next = nullptr;

    // TODO Complete this function, handle the case when you're enqueuing in an empty queue
    if(isEmpty()) //empty
    {
        queueFront = nn; //front & back set to first node
        queueEnd = nn;

    }

    else if(!isEmpty()) //not empty
    {
        nn->next = queueEnd; //set new node ptr to end of queue node
        queueEnd = nn; //set end ptr to new node

    }
}

//TODO
void QueueLL::dequeue()
{
    if(!isEmpty())
    {
        // TODO Complete this function, handle the case when your queue becomes empty after dequeuing
        Node *delNode = queueEnd;
        Node *preDel = queueEnd;

        if (delNode == queueFront)
        {
            delete delNode;
            queueFront = nullptr;
            queueEnd = nullptr;
        }

        else
        {
            while(delNode != queueFront)
            {
                preDel = delNode;
                delNode = delNode->next;
                //now prev is val before front, del should be deleted
            }

            delete delNode;
            queueFront = preDel;
        }

        
    }
    else{
        cout<<"queue is empty. can not deque"<<endl;
    }
}

int QueueLL::peek()
{
    if( !isEmpty() )
        return queueFront->key;
    else
    {
        cout<< " queue is empty. can not peek"<<endl;
        return -1;
    }
    //return 0;
}
