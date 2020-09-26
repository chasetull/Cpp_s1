//Chase Tullar - Assignment 1

#include "arraySort.h"
#include <iostream>

using namespace std;

int addToArrayAsc(float sorted_Array[], int num_Elements, float new_Value)
{
    float temp = new_Value;
    try
    {
        sorted_Array[num_Elements+1] = temp;
        sorted_Array.sort();
    }
    catch(const exception& e)
    {
        cout << e.what() << '\n';
    }
    
}

void addStudentData(studentDatastudents[], stringstudentName, inthomework, intrecitation, intquiz, intexam, intlength)
{
    string stud1.stringstudentName = '';
    int stud1.inthomework;
    int stud1.intrecitation;
    int stud1.intquiz;
    int stud1.intexam;
    int stud1.intlength
}

void printList(studentDatastudents[])
{
    for (int i = 0; i<studentDatastudents.length(); i++)
    {
        cout << studentDatastudents[i] << endl;
    }
}