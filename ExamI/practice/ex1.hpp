//#include <iostream>
using namespace std;

struct Node
{
    char key;
    Node *next;
};

class IntList
{
  public:
    Node *head;
    IntList();
    ~IntList();
    bool isEmpty();
    bool lengthIsEven(Node *head);

};