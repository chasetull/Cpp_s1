//main
#include <iostream>
#include <fstream>
#include <string>
#include "arrayDoubler.h"

using namespace std;

int main(int argc, char const *argv[])
{
    //get vals / init
    //ifstream inFile;
    string line;
    string ignoredWords[49];
    wordRecord *uniqueWords;
    wordRecord *uniqueTemp;
    string filePath;
    const char *fileIgnore = argv[3];
    int N = stoi(argv[1]);

    //error check input
    if (argc != 4)
    {
        cout << "Usage: Assignment2Solution <number of words> <inputfilename.txt> <ignoreWordsfilename.txt>" << endl;
        exit(0);
    }
    else
    {
        
        filePath = argv[2];
        

    }
    
    //get ignore words
    getIgnoreWords(fileIgnore, ignoredWords);

    //get words from mobydick
    int j = 0;
    int size = 100;
    int doubledCount = 0;
    uniqueWords = new wordRecord[size];

    ifstream inFile;
    inFile.open(filePath);
    
    while (inFile >> line)
    {
        bool isIgnore = isIgnoreWord(line, ignoredWords);

        //IS A GOOD WORD
        if (!isIgnore)
        {
            //IF FULL, DOUBLE ARRAY
            if (j == size)
            {
                
                int incr = 0;
                int prevSize = size;
                size = size * 2;
                doubledCount += 1;

                uniqueTemp = new wordRecord[prevSize];
                
                while (incr < prevSize)
                {
                    uniqueTemp[incr].word = uniqueWords[incr].word;
                    uniqueTemp[incr].count = uniqueWords[incr].count;
                    incr++;
                }
                
                
                delete[] uniqueWords;
                
                uniqueWords = new wordRecord[size];
                
                incr = 0;

                while (incr < prevSize)
                {
                    uniqueWords[incr].word = uniqueTemp[incr].word;
                    uniqueWords[incr].count = uniqueTemp[incr].count;
                    incr++;
                }
                

                delete[] uniqueTemp;
                
                
            }

            //bool to hinge word placement or tally
            bool insertNeed = true;

            for (int i=0; i < size; i++)
            {
                //if incoming unique word is already in array, add tally
                if (line == uniqueWords[i].word)
                {
                    uniqueWords[i].count += 1;
                    insertNeed = false;
                }
                
            }

            //if incoming unique word is not found, add it
            if (insertNeed)
            {
                uniqueWords[j].word = line;
                uniqueWords[j].count = 1;
                j++;
            }
            
        }
        
    }
    inFile.close();

    int totalIgnored = getTotalNumberNonIgnoreWords(uniqueWords, size);
    int totalDistinct = sortArrayDistinct(uniqueWords, size);
    //sortArray(uniqueWords, size);

    cout << "--- UNIQUE WORDS ARRAY ---" << endl;

    cout << "Array doubled: " << doubledCount << endl;
    cout << "Distinct non-common words: " << totalDistinct << endl;
    cout << "Total non-common words: " << totalIgnored << endl;
    printTenFromN(uniqueWords, N, totalDistinct);
    

    return 0;
}

 


