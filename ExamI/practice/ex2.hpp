#include <iostream>
#include <string>
using namespace std;

struct Node
{
    Node *next;
    int val;
};

struct Listoi
{
    Node *head = nullptr;
    void insert(int inV)
    {
        if (isEmpty())
        {
            Node *newInt = new Node;
            newInt->val = inV;
            newInt->next = nullptr;
            head = newInt;
            cout << "added " << newInt->val << endl;
        }
        else
        {
            Node *s = head;
            Node *newInt = new Node;
            newInt->val = inV;
            newInt->next = nullptr;

            while (s != nullptr)
            {
                if (s->next == nullptr)
                {
                    s->next = newInt;
                    cout << "added " << s->val << " -> " << newInt->val << endl;
                    break;
                }
                else
                {
                    s = s->next;
                }
            }
        }
    }
    void delall()
    {
        if (isEmpty())
        {
            cout << "Empty" << endl;
        }
        else
        {
            Node *d = head;
            Node *pd = head;
            while (d != nullptr)
            {
                cout << "deleting " << d->val << endl;
                pd = d;
                d = d->next;
                pd->next = nullptr;
                delete pd;
            }
            head = nullptr;
            cout << "deleted LL" << endl;
        }
    }

    bool isEmpty()
    {
        return (head==nullptr);
    }

    void printL()
    {
        if (isEmpty())
        {
            cout << "Empty path" << endl;
        }
        else
        {
            Node *f = head;
            cout << "=== PATH ===" << endl;
            while (f != nullptr)
            {
                cout << f->val << " -> ";
                if (f->next == nullptr)
                {
                    break;
                }
                f = f->next;
            }
            cout << " NULL" << endl;
        }
    }
    bool lengthIsEven()
    {
        bool isEven = false;
        int count = 0;
        Node *l = head;

        if (isEmpty())
        {
            isEven = true;
        }
        else
        {
            while (l != nullptr)
            {
                count++;
                l = l->next;
            }
            if (count%2 == 0)
            {
                isEven = true;
            }
        }
        return isEven;
    }
    Node* deleteNegatives()
    {
        Node *cur = head;
        Node *prev = nullptr;
        Node *returnNode = nullptr;

        if (isEmpty())
        {
            cout << "Empty list" << endl;
        }
        else
        {
            while (cur != nullptr)
            {
                if (cur->val < 0)
                {
                    if (cur == head)
                    {
                        head = head->next;
                        delete cur;
                        cur = head;
                    }
                    else
                    {
                        prev->next = cur->next;
                        delete cur;
                        cur = prev->next;
                    }
                    
                }
                else
                {
                    prev = cur;
                    cur = cur->next;
                }
            }
            returnNode = head;
        }
        return returnNode;
    }
};

//Array doubling function
int* arrDouble(int *arrPtr, int &capacity)
{
    int newCap = capacity * 2;
    cout << "Resizing from " << capacity << " to " << newCap << endl;
    int *newArr = new int[newCap];

    for (int i=0; i<capacity; i++)
    {
        newArr[i] = arrPtr[i];
        //cout << "copying " << newArr[i] << endl;
    }

    delete arrPtr;
    capacity = newCap;

    return newArr;
};

//length is even and delNegs alternate
bool lengthIsEvenInp(Node *head)
{
    bool isEven = false;
    int count = 0;
    Node *l = head;

    if (head==nullptr)
    {
        isEven = true;
    }
    else
    {
        while (l != nullptr)
        {
            count++;
            l = l->next;
        }
        if (count%2 == 0)
        {
            isEven = true;
        }
    }
    return isEven;
};

//
Node* deleteNegativesInp(Node *head)
{
    Node *cur = head;
    Node *prev = nullptr;
    Node *returnNode = nullptr;    

    if (head==nullptr)
    {
        cout << "Empty list" << endl;
    }
    else
    {
        while (cur != nullptr)
        {
            if (cur->val < 0)
            {
                if (cur == head)
                {
                    head = head->next;
                    delete cur;
                    cur = head;
                }
                else
                {
                    prev->next = cur->next;
                    delete cur;
                    cur = prev->next;
                }
                
            }
            else
            {
                prev = cur;
                cur = cur->next;
            }
        }
        returnNode = head;
    }
    return returnNode;
};

void printl(Node *head)
{
    Node *l = head;

    if (head==nullptr)
    {
        cout << "nothing in list" << endl;
    }
    else
    {
        while (l != nullptr)
        {
            cout << l->val << " -> ";
            l = l->next;
        }
        cout << "NULL" << endl;
    }
};