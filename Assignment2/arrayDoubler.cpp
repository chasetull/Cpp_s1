//
#include "arrayDoubler.h"
#include <iostream>
#include <fstream>

using namespace std;

//pulls words to be ignored from file
void getIgnoreWords(const char *ignoreWordFileName, string ignoreWords[])
{
    ifstream inFile;
    string line;
    int i = 0;

    //read in ignore words
    try
    {
        inFile.open(ignoreWordFileName);
        while (inFile >> line)
        {
            ignoreWords[i] = line;
            i++;
        }
        inFile.close();
    }

    catch(exception e)
    {
        cout << "Failed to open " << ignoreWordFileName << endl;
    }
};

//
bool isIgnoreWord(string word, string ignoreWords[])
{
    bool answer = false;

    for (int i=0; i<50; i++)
    {
        //if word should be IGNORED
        if (ignoreWords[i] == word)
        {
            answer = true;
        }
    }

    return answer;
};

//Computes total number of words in doc by adding up wordRecord amounts
int getTotalNumberNonIgnoreWords(wordRecord distinctWords[], int length)
{
    int totalCount = 0;

    for (int i=0; i<length; i++)
    {
        totalCount += distinctWords[i].count;
    }

    return totalCount;
};

//Sorts distinctWords array, most frequent are at beginning
void sortArray(wordRecord distinctWords[], int length)
{
    int i = 1;
    wordRecord *ptr1 = &distinctWords[0];
    wordRecord *ptr2 = &distinctWords[1];

    while (true)
    {
        if (ptr1 > ptr2)
        {
            wordRecord *temp = ptr2;
            ptr2 = ptr1;
            ptr1 = temp;
        }
    }
};

//
void printTenFromN(wordRecord distinctWords[], int N, int totalNumWords)
{
    int startInd = N;
    int endInd = N+10;

    cout << "Probability of next 10 words from rank " << N << ": " << endl;

    while (endInd != startInd)
    {
        cout << distinctWords[endInd].word << endl;
        endInd -= 1;
    }
};

int sortArrayDistinct(wordRecord distinctWords[], int length)
{
    int totalDist = 0;

    for (int i =0; i < length; i++)
    {
        if ((distinctWords[i].count == 1) || (distinctWords[i].count == 2) || (distinctWords[i].count == 3) || (distinctWords[i].count == 4) || (distinctWords[i].count == 5) || (distinctWords[i].count == 6) || (distinctWords[i].count == 7) || (distinctWords[i].count == 8) || (distinctWords[i].count == 9) || (distinctWords[i].count == 10))
        {
            totalDist += 1;
        }
    }

    return totalDist;
};