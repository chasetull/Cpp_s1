#include "Problem2.hpp"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void addStudentData(studentData students[], string studentName, int homework, int recitation, int quiz, int exam, int length)
{
    studentData newStud;
    newStud.studentName = studentName;
    newStud.homework = homework;
    newStud.recitation = recitation;
    newStud.quiz = quiz;
    newStud.exam = exam;
    newStud.average = (homework + recitation + quiz + exam)/4;

    students[length] = newStud;
    //cout << "adding " << newStud.studentName <<  " len: " << length << endl;
};

char calcLetter(double avg)
{
    char letterGrade;
    
    if (avg > 90)
    {
        letterGrade = 'A';
    }
    else if (avg < 89.9 && avg > 80)
    {
        letterGrade = 'B';
    }
    else if (avg < 79.9 && avg > 70)
    {
        letterGrade = 'C';
    }
    else if (avg < 69.9 && avg > 60)
    {
        letterGrade = 'D';
    }
    else if (avg < 60)
    {
        letterGrade = 'F';
    }
    else
    {
        letterGrade = 0;
    }
    

    return letterGrade;
};

void printList(studentData students[], int length)
{
    //cout << "-------CURRENT DATA-------" << endl;
    if (length == 0)
    {
        cout << "nothing in array" << endl;
    }
    else
    {
        for (int i=0; i<length; i++)
        {
            cout << students[i].studentName << " earned " << students[i].average << " which is a(n) " << calcLetter(students[i].average) << endl;
        }
    }
    
};
