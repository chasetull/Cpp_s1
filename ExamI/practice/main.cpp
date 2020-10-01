#include "ex1.hpp"
#include <iostream>
using namespace std;

int main()
{
    cout << "MAIN" << endl;
    //Node *head;
    IntList listoi;
    Node *n1 = new Node;
    Node *n2 = new Node;
    Node *n3 = new Node;
    Node *n4 = new Node;
    Node *n5 = new Node;
    head = n1;

    n1->key = 0;

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = nullptr;

    //newList.lengthIsEven(head);

    return 0;
}

