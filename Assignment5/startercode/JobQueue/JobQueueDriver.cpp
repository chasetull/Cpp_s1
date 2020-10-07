/****************************************************************/
/*                Job Queue Driver File                 */
/****************************************************************/
/* TODO: Implement menu options as described in the writeup     */
/****************************************************************/

#include "JobQueue.hpp"
#include <iostream>
#include <fstream>
#include <string>
// you may include more libraries as needed

using namespace std;

/*
 * Purpose: displays a menu with options
 * @param none
 * @return none
 */
void menu()
{
	cout << "*----------------------------------------*" << endl;
	cout << "Choose an option:" << endl;
    cout << "1. Add jobs into the queue" << endl;
	cout << "2. Dispatch jobs from the queue" << endl;
	cout << "3. Return the queue size and exit" << endl;
	cout << "*----------------------------------------*" << endl;
}
// Use getline for reading
int main(/*int argc, char const *argv[]*/)
{
	string imp;
	//bool isQuit = false;
	while (true)
	{
		menu();
		getline(cin, imp);

		int inp = stoi(imp);
		
		if (inp < 1 || inp > 3)
		{
			cout << "Wrong input" << endl;
		}
		else if (inp == 1) //add jobs
		{
			cout << "ADD JOB" << endl;
			break;
		}
		else if (inp == 2) //delete jobs
		{
			cout << "DELETE JOB" << endl;
			break;
		}
		else if (inp == 3) //show q size and exit
		{
			//isQuit = true;
			cout << "quitting..." << endl;
			exit(0);
		}
		else
		{
			cout << "???????" << endl;
		}
		
	}
}
