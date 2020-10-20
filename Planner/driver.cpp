#include "plan.hpp"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

void menu()
{
    cout << "======= Welcome Chase =======" << endl;
    cout << "==== Enter option number ====" << endl;
    cout << "0) Exit" << endl;
    cout << "1) Print Assignments" << endl;
    cout << "2) Add Assignment(s)" << endl;
    cout << "3) Delete Assignment" << endl;
    cout << "4) Add Class" << endl;
    cout << "5) Save" << endl;
    cout << endl;
}

int main(int argc, char *argv[])
{
    bool isDone = false;
    int num;
    string savefile = argv[1];
    Planner plan;
    string newclassname;
    string addtoclass;
    string newassname;
    ClassNode *search = NULL;
    char toSave;
    int numAss;

    while (!isDone)
    {
        menu();
        cout << "#> ";
        cin >> num;
        cout << endl;

        switch (num)
        {
        case 0:
            if (plan.isSave())
            {
                cout << "Exiting..." << endl;
                isDone = true;
            }
            else
            {
                cout << "There is unsaved progress. Exit without saving? (y/n) : " << endl;
                cin >> toSave;
                if (toSave == 'y')
                {
                    cout << "Exiting..." << endl;
                    isDone = true;
                }
            }
            break;
        case 1:
            cout << "----- All Assignments -----" << endl;
            plan.printall();
            break;
        case 2:
            cout << "Enter number of new assignments: " << endl;
            cin >> numAss;
            while (numAss > 0)
            {
                cout << "Enter assignment name to add: " << endl;
                cin >> newassname;
                cout << "Enter class name to add " << newassname << " to: " << endl;
                cin >> addtoclass;
                search = plan.searchClass(addtoclass);
                if (search == NULL)
                {
                    cout << "Invalid class : " << addtoclass << endl;
                }
                else
                {
                    plan.addAss(newassname, addtoclass);
                    numAss--;
                }
            }
            break;
        case 3:
            cout << "Enter assignment name to delete: " << endl;
            break;
        case 5:
            cout << "Saving data to " << savefile << "..." << endl;
            plan.saveall(savefile);
            cout << "Done." << endl;
            cout << endl;
            break;
        case 4:
            cout << "Enter class name to add: " << endl;
            cin >> newclassname;
            plan.addClass(newclassname);
            break;
        
        default:
            cout << "Default ?" << endl;
            break;
        }
    }
    
    return 0;
}