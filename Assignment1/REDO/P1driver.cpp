// Problem 1 Main
#include <iostream>
#include <fstream>
#include <string>
#include "Problem1.hpp"

using namespace std;

int main(int argc, char const *argv[])
{
    string filePath = argv[1];
    const int SIZE = 100;
    float intArr[SIZE];
    string line;
    ifstream inFile (filePath);
    int currSize = 0;

    if (inFile.is_open())
    {
        while (! inFile.eof() )
        {
            getline(inFile, line);
            float linetofloat = stof(line); //get new float from file
            //currSize = sizeof(intArr) / sizeof(intArr[0]);

            addToArrayAsc(intArr, currSize, linetofloat); //pass arr, amnt passed so far, new float to function

            currSize++;
        }

        inFile.close();

    }
    else
    {
        cout << "Failed to open the file." << endl;
    }
    
    return 0;
}