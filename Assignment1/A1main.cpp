// Assignment 1 Main
#include <iostream>
#include <fstream>
#include <string>
//#include arraySort.cpp
#include "arraySort.h"

using namespace std;

int main(int argc, char const *argv[])
{
    string filePath;
    cin >> filePath;
    float inF[100];
    string line;
    ifstream inFile;
    //stringstream S (filePath);
    inFile.open(filePath);
    //cout << argv[1] << endl;

    if (inFile.is_open())
    {
        while ( getline (filePath,line) )
        {
            cout << line << endl;
        }

        inFile.close();
    }

    else
    {
        cout << "Error opening file " << argv[2];
    }

    return 0;
}