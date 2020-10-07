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
	JobQueue *jq = new JobQueue;

	while (true)
	{
		menu();
		cout << "#>";
		getline(cin, imp);
		cout << endl;

		int inp = stoi(imp);
		
		if (inp < 1 || inp > 3)
		{
			cout << "Wrong input" << endl;
		}
		else if (inp == 1) //add jobs
		{
			string amntJobs;
			cout << "Enter the number of jobs to be created:" << endl;
			cout << "#>";
			getline(cin, amntJobs);
			cout << endl;
			int numJobs = stoi(amntJobs);
			cout << numJobs << " jobs to create" << endl;

			if (numJobs > 20 || numJobs < 1)
			{
				cout << "Error, wrong amount of jobs input" << endl;
			}
			else
			{
				int parseJob = 1;
				string indivJobName;
				while (numJobs > 0)
				{
					cout << "job" << parseJob << ":" << endl;
					cout << "#>";
					getline(cin, indivJobName);
					cout << endl;
					jq->enqueue(indivJobName);  //enqueue job
					parseJob++;
					numJobs--;
				}
				string showJob = jq->peek();
				cout << "jq peek: " << showJob << endl;
			}
		}

		else if (inp == 2) //delete jobs
		{
			string peekHead = jq->peek();
			cout << "head before: " << peekHead << endl;
			jq->dequeue();
			peekHead = jq->peek();
			cout << "head after: " << peekHead << endl;
		}

		else if (inp == 3) //show q size and exit
		{
			int qSize = jq->queueSize();
			cout << "Number of jobs in the queue:" << qSize << endl;
			exit(0);
		}
		else
		{
			cout << "???????" << endl;
		}
		
	} //end program

	return 0;
}
