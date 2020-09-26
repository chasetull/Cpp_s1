//Array Doubling
#include <iostream>
using namespace std;

//
struct wordRecord
{
    int count;
    string word;
};

//
void getIgnoreWords(const char *ignoreWordFileName, string ignoreWords[]);

//
bool isIgnoreWord(string word, string ignoreWords[]);

//
int getTotalNumberNonIgnoreWords(wordRecord distinctWords[], int length);

//
void sortArray(wordRecord distinctWords[], int length);

//
void printTenFromN(wordRecord distinctWords[], int N, int totalNumWords);

int sortArrayDistinct(wordRecord distinctWords[], int length);