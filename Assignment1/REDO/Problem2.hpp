#include <iostream>
#include <string>

using namespace std;

struct studentData
{
    string studentName;
    int homework;
    int recitation;
    int quiz;
    int exam;
    double average;
};


void addStudentData(studentData students[], string studentName, int homework, int recitation, int quiz, int exam, int length);

char calcLetter(double avg);

void printList(studentData students[], int length);
