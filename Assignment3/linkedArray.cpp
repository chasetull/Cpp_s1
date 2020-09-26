#include <iostream>
#include <fstream>
#include <string>
#include "linkedArray.hpp"
using namespace std;

//1st problem
bool append(string* &str_arr, string s, int &numEntries, int &arraySize)
{
    str_arr[numEntries] = s;

    if (str_arr[numEntries] == s)
    {
        return true;
    }

    else
    {
        return false;
    }
    
};