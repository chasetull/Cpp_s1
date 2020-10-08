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
		getline(cin, imp);

		int inp = stoi(imp);
		
		if (inp < 1 || inp > 3)
		{
			cout << "Wrong input" << endl;
		}
		else if (inp == 1) //add jobs
		{
			string amntJobs;
			cout << "Enter the number of jobs to be created:" << endl;
			getline(cin, amntJobs);
			int numJobs = stoi(amntJobs);
			//cout << numJobs << " jobs to create" << endl;

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
					getline(cin, indivJobName);
					jq->enqueue(indivJobName);  //enqueue job
					parseJob++;
					numJobs--;
				}
				/*
				string showJob = jq->peek();
				cout << "jq peek: " << showJob << endl;
				*/
			}
		}

		else if (inp == 2) //delete jobs
		{
			string amntJobs;
			cout << "Enter the number of jobs to be dispatched:" << endl;
			getline(cin, amntJobs);
			int numJobs = stoi(amntJobs);

			if (numJobs < 0)
			{
				cout << "Error, wrong input" << endl;
			}
			else
			{
				int qSize = jq->queueSize();
				bool overBoundMessage = false;
				if (numJobs > qSize)
				{
					overBoundMessage = true;
					numJobs = jq->getQueueEnd();
				}

				while (numJobs > 0)
				{
					cout << "Dispatched: " << jq->peek() << endl;
					jq->dequeue();
					numJobs--;
				}

				if (overBoundMessage)
				{
					cout << "No more jobs to be dispatched from queue" << endl;
				}
			}
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
