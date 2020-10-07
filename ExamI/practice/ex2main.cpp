#include <iostream>
#include <string>
#include "ex2.hpp"
using namespace std;

int main()
{
    int *ptrr = 10;
    bool quitNow = false;
    while (!quitNow)
    {
        cout << "+++ SELECT OPTION +++" << endl;
        cout << "0: Quit" << endl;
        cout << "1: Linked List (lenEven, delNegs)" << endl;
        cout << "2: Array doubling" << endl;
        cout << "3: delNegs & checkEven" << endl;

        int chc = -1;

        cin >> chc;

        if (chc == 0)
        {
            quitNow = true;
            cout << "quitting..." << endl;
        }

        //LINKEDLIST
        else if (chc == 1)
        {
            Listoi intList;
            intList.printL();
            intList.insert(1);
            intList.insert(2);
            intList.insert(3);
            intList.insert(4);
            intList.printL();

            //length is even check
            bool is_even = intList.lengthIsEven();
            cout << "Path is ";
            if (is_even)
            {
                cout << "even" << endl;
            }
            else
            {
                cout << "odd" << endl;
            }

            //delete negatives check
            intList.insert(-1);
            cout << "Pre deleteNegatives" << endl;
            intList.printL();

            intList.deleteNegatives();

            cout << "Post deleteNegatives" << endl;
            intList.printL();

            cout << endl;
        }
        
        //ARRAY DUB
        else if (chc == 2)
        {
            int arrCap = 10;
            int *arrayoi = new int[arrCap];

            for (int j=0; j<arrCap; j++)
            {
                arrayoi[j] = j;
                //cout << "adding " << arrayoi[j] << endl;
            }

            //printing
            cout << "=== ARR PATH ===" << endl;
            for (int j=0; j<arrCap; j++)
            {
                cout << arrayoi[j] << " -> ";
            }
            cout << "end" << endl;

            arrDouble(arrayoi, arrCap);

            cout << "=== ARR PATH ===" << endl;
            for (int j=0; j<arrCap; j++)
            {
                cout << arrayoi[j] << " -> ";
            }
            cout << "end" << endl;

            cout << endl;
        }

        else if (chc == 3)
        {
            Node *n1 = new Node;
            Node *n2 = new Node;
            Node *n3 = new Node;
            Node *head;

            n1->next = n2;
            n2->next = n3;
            n3->next = nullptr;
            n1->val = 1;
            n2->val = 2;
            n3->val = -3;
            head = n1;

            if (lengthIsEvenInp(head))
            {
                cout << "list is even" << endl;
            }
            if (!lengthIsEvenInp(head))
            {
                cout << "list is odd" << endl;
            }

            printl(head);

            deleteNegativesInp(head);

            if (lengthIsEvenInp(head))
            {
                cout << "list is even" << endl;
            }
            if (!lengthIsEvenInp(head))
            {
                cout << "list is odd" << endl;
            }

            printl(head);
            
        }

        else
        {
            cout << "Wrong input" << endl;
        }
    }

    return 0;
}



