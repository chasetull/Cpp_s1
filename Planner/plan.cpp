#include "plan.hpp"
#include <fstream>
#include <sstream>

using namespace std;

Planner::Planner()
{
    root = NULL;
    isSaved = true;
}

Planner::~Planner()
{

}

void Planner::addAss(string assname, string classname)
{
    ClassNode *addHere = searchClass(classname);
    int i = addHere->numFull;
    if (i > 5)
    {
        cout << "Assignment array full, cannot add " << assname << endl;
        cout << endl;
    }
    else
    {
        addHere->assignments[i] = assname;
        addHere->numFull++;
        cout << "Assignment " << assname << " added to " << classname << endl;
        cout << endl;
        isSaved = false;
    }
}

void Planner::deleteAss(string assname, string classname)
{
    ClassNode *temp = searchClass(classname);
    if (temp == NULL)
    {
        cout << "Cannot delete. Class does not exist" << endl;
        return;
    }
    else
    {
        for (int i = 0; i < 5; i++)
        {
            if (temp->assignments[i] == assname)
            {
                temp->assignments[i] = "";
                temp->numFull--;
                cout << "Deleted ass: " << assname << endl;
            }
        }
    }
}

void Planner::deleteClass(string cname)
{
    
}

void Planner::printall()
{
    if (root == NULL)
    {
        cout << "Nothing to display" << endl;
    }
    else
    {
        ClassNode *parse = root;
        while (parse != NULL)
        {
            cout << "Class: " << parse->name << endl;
            cout << "Assignments:" << endl;
            printAss(parse);
            parse = parse->next;
        }
    }
    cout << endl;
}

void Planner::saveall(string fname)
{
    ofstream oFile(fname);
    ClassNode *temp = root;
    
    if (oFile.is_open())
    {
        while (temp != NULL)
        {
            oFile << "C:" << temp->name << ";";
            for (int j=temp->numFull; j>0; j--)
            {
                oFile << "A" << j << ":" << temp->assignments[j-1] << ",";
            }
            oFile << endl;
            temp = temp->next;
        }
        oFile.close();
    }
    else
    {
        cout << "Error saving to " << fname << endl;
        return;
    }
    isSaved = true;
}

bool Planner::isSave()
{
    return isSaved;
}

void Planner::addClass(string classname)
{
    if (root == NULL)
    {
        ClassNode *newclass = new ClassNode;
        newclass->name = classname;
        newclass->next = NULL;
        root = newclass;
        cout << "New class: " << classname << endl;
        cout << endl;
        isSaved = false;
    }
    else
    {
        ClassNode *temp = root;
        while (temp != NULL)
        {
            if (temp->next == NULL)
            {
                ClassNode *newclass = new ClassNode;
                newclass->name = classname;
                newclass->next = NULL;
                temp->next = newclass;
                cout << "New Class: " << classname << endl;
                cout << endl;
                isSaved = false;
                return;
            }
            temp = temp->next;
        }
    }
}

ClassNode* Planner::searchClass(string cname)
{
    ClassNode *returnClass = root;

    if (root == NULL)
    {
        return NULL;
    }
    else
    {
        while (returnClass != NULL)
        {
            if (returnClass->name == cname)
            {
                return returnClass;
            }
            returnClass = returnClass->next;
        }
    }
    return returnClass;
}

void Planner::readData(string fname)
{
    ifstream iFile(fname);
    string line;
    string dataarray[4];
    int ind = 0;
    string str;
    

    if (iFile.is_open())
    {
        while ( getline(iFile, line) )
        {
            cout << line << endl;
            dataarray[ind] = line;
            ind++;
        }
        iFile.close();
    }

    for (int i = 0; i < 4; i++)
    {
        cout << dataarray[i] << endl;
        stringstream ss(dataarray[i], ';');
        while (ss >> str)
        {
            cout << str << endl;
        }
        //cout << ss << endl;
    }
    
}






/*                    NON CLASS FUNCTIONS                  */




void printAss(ClassNode *curclass){
    //int arsize = sizeof(curclass->assignments) / sizeof(curclass->assignments[0]);
    if (curclass->assignments == 0)
    {
        cout << "No assignments" << endl;
    }
    else
    {
        for (int i=0; i<5; i++)
        {
            cout << i+1 << ". " << curclass->assignments[i] << endl;
        }
        cout << endl;
    }
}