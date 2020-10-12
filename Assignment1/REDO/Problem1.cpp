//Chase Tullar - Assignment 1

#include "Problem1.hpp"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int addToArrayAsc(float sorted_Array[], int num_Elements, float new_Value)
{
    int i, j, minInd;

    if(num_Elements == 0)
    {
        sorted_Array[num_Elements] = new_Value;
    }
    else
    {
        sorted_Array[num_Elements] = new_Value;

        for(i = 0; i < num_Elements; i++)
        {
            minInd = i;
            for(j = i+1; j < num_Elements+1; j++)
            {
                if(sorted_Array[j] < sorted_Array[minInd])
                {
                    minInd = j;
                }
            }

            swap(&sorted_Array[minInd], &sorted_Array[i]);
        }
    }
    
    float arrSize = sizeof(*sorted_Array) / sizeof(sorted_Array[0]);
    int returnInt = int(arrSize);
    
    return returnInt;//num_Elements+1;
};



void swap(float* xp, float* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
};

void printArr(float sorted_arr[], int saSize)
{
    for(int i=0; i<saSize; i++)
    {
        if (i < saSize-1)
        {
            cout << sorted_arr[i] << ", ";
        }
        else
        {
            cout << sorted_arr[i];
        }
        
    }
    cout << endl;
};
