//Chase Tullar - Assignment 1

#include "Problem1.hpp"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int addToArrayAsc(float sorted_Array[], int num_Elements, float new_Value)
{
    int returnInt = 0;
    int i, j, minInd;

    for(i = 0; i < num_Elements-1; i++)
    {
        minInd = i;
        for(j = i+1; j < num_Elements; j++)
        {
            if(sorted_Array[j] < sorted_Array[minInd])
            {
                minInd = j;
            }
        }

        swap(&sorted_Array[minInd], &sorted_Array[i]);
    }

    
    return returnInt;
}

void swap(float* xp, float* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}