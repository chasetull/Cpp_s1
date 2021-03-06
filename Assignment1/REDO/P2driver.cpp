#include "Problem2.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    cout << "---INTRO---" << endl;
    cout << "input: <infile>, <outfile>, <lowergrade>, <highergrade>" << endl;

    string ifpath = argv[1]; //read data from file
    string ofpath = argv[2]; //write data to file
    string low = argv[3]; //lower grade bound
    string high = argv[4]; //upper grade bound
    

    string line;
    studentData studentsArray[10];
    ifstream inFile (ifpath);
    int itemcount = 0;

    if (inFile.is_open())
    {
        while (! inFile.eof())
        {
            getline(inFile, line);
            stringstream ss(line);
            string token;
            int tk = 0;

            string name;
            int hw, rectn, qz, exam;

            while ( getline (ss, token, ',') )
            {
                switch (tk)
                {
                case 0:
                    //cout << "name: " << token << endl;
                    name = token;
                    break;
                case 1:
                    //cout << "hw: " << token << endl;
                    hw = stoi(token);
                    break;
                case 2:
                    //cout << "rec: " << token << endl;
                    rectn = stoi(token);
                    break;
                case 3:
                    //cout << "qz: " << token << endl;
                    qz = stoi(token);
                    break;
                case 4:
                    //cout << "exm: " << token << endl;
                    exam = stoi(token);
                    addStudentData(studentsArray, name, hw, rectn, qz, exam, itemcount);
                    itemcount++;
                    break;
                
                default:
                cout << "error" << endl;
                    break;
                }

                tk++;
            } 
        }

        inFile.close();
        printList(studentsArray, itemcount);
    }
    else
    {
        cout << "Cannot open file." << endl;
    }

    //studentData withinBounds[10];

    string a = "A";
    string b = "B";
    string c = "C";
    string d = "D";
    string f = "F";

    float highbound;
    if (high == a)
    {
        highbound = 99.9;
    }
    else if (high == b)
    {
        highbound = 89.9;
    }
    else if (high == c)
    {
        highbound = 79.9;
    }
    else if (high == d)
    {
        highbound = 69.9;
    }
    else if (high == f)
    {
        highbound = 59.9;
    }
    else
    {
        cout << "error" << endl;
    }
    

    float lowbound;
    if (low == a)
    {
        lowbound = 90;
    }
    else if (low == b)
    {
        lowbound = 80;
    }
    else if (low == c)
    {
        lowbound = 70;
    }
    else if (low == d)
    {
        lowbound = 60;
    }
    else if (low == f)
    {
        lowbound = 0;
    }
    else
    {
        cout << "error" << endl;
    }

    

    ofstream outFile (ofpath);

    if (outFile.is_open())
    {
        for (int i=0; i<10; i++) {
            if (studentsArray[i].average >= lowbound && studentsArray[i].average <= highbound)
            {
                outFile << studentsArray[i].studentName << ", " << studentsArray[i].average << ", " << calcLetter(studentsArray[i].average) << '\n';
            }
        }

        outFile.close();
    }
    else
    {
        cout << "Cannot open file." << endl;
    }
    

    return 0;
}


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