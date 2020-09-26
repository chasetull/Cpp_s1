//Array Doubling MAIN
#include <iostream>
#include <string>
#include "linkedArray.hpp"

using namespace std;

int main()
{
    // __init__ vars
    int arrSize = 5;
    string arraytemp[arrSize];
    string *ptr = *&arraytemp;
    string ss;
    int numEnt = 0;
    int i = 0;
    int maxSize = 80;

    //add elems to array
    while (numEnt < maxSize)
    {
        if (numEnt == arrSize+1)
        {
            //double arr and set ptr to new arr
            cout << "DOUBLE FUNC" << endl;
            arrSize = arrSize * 2;
            string newArrTemp[arrSize];
            for (int k=0; k<arrSize/2; k++)
            {
                newArrTemp[k] = arraytemp[k];
            }
            ptr = newArrTemp;
        }

        ss = "Val_" + to_string(numEnt);
        cout << ss << " @" << numEnt << endl;
        append(*&ptr, ss, numEnt, arrSize); //bool didAppend = 
    
        numEnt++;
    }
/*
        if (didAppend)
        {
            cout << "ADDED VAL" << endl;
        }

        else if (!didAppend)
        {
            cout << "FAILED ADD" << endl;
        }

        else
        {
            cout << "NOTHING?" << endl;
        }
        i++;
*/
        /*
        arraytemp[i] = "Suh" + to_string(i+1);
        cout << "START: " << arraytemp[i] << endl;

        if (i == arrSize-1) //array doubling
        {
            cout << "Performing doubling..." << endl;
            if (append(ptr, ss, numEnt, arrSize))
            {
                cout << "WORKED" << endl;
            }

            else
            {
                cout << "didn't work" << endl;
            }
            
        }
        i++;
        */
    

    cout << "DONE" << endl;

    return 0;
}