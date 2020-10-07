#include <iostream> // predefined header file (defined for you)
#include <string>
using namespace std;

#include "SLL.hpp" // your own header file
// <> vs "" -- compiler looks for the file in the C++ implementation
// vs in the current directory


SLL::SLL(){ // constructor definition
	headOne = nullptr;
	headTwo = nullptr;
}

SLL::SLL(string demo)
{
	headOne = nullptr;
	headTwo = nullptr;
	if (demo == "demo")
	{
		string def[]= {"che","the","fluffy","cat"};
		insert(nullptr, def[0]);
		for(int i=1;i<4;i++)
		{
				Node* prev = search(def[i-1]);
				insert(prev, def[i]);
		}
	}
	else{
		insert(nullptr, demo);
	}
}

SLL::~SLL(){
    //todo
    Node *temp1 = headOne;
    Node *temp2 = headTwo;

    if (headOne == nullptr && headTwo == nullptr)
    {
        return;
    }
    else
    {
        if (temp1 != nullptr)
        {
            while (temp1 != nullptr)
            {
                if (temp1->next == nullptr)
                {
                    headOne = nullptr;
                    delete temp1;
                    break;
                }
                else
                {
                    headOne = headOne->next;
                    temp1->next = nullptr;
                    delete temp1;
                    temp1 = headOne;
                }
            }
        }

        if (temp2 != nullptr)
        {

            while (temp2 != nullptr)
            {
                if (temp2->next == nullptr)
                {
                    headTwo = nullptr;
                    delete temp2;
                    break;
                }
                else
                {
                    headTwo = headTwo->next;
                    temp2->next = nullptr;
                    delete temp2;
                    temp2 = headTwo;
                }
            }
        }
    }
}

Node* SLL::search(string sKey){

    Node* crawler = headOne;

    while( crawler != nullptr && crawler->key != sKey){
        crawler = crawler->next;
    }

    return crawler;

}

void SLL::displayList(){
    Node* crawler = headOne;
    cout<< "LL1:";
    while( crawler != nullptr ){
        cout << crawler->key << "->";
        crawler = crawler->next;
    }
    cout << "END" << endl;

    crawler = headTwo;
    cout<< "LL2:";
    while( crawler != nullptr ){
        cout << crawler->key << "->";
        crawler = crawler->next;
    }
    cout << "END" << endl;
}


void SLL::insert(Node* afterMe, string newValue){

    if(headOne == nullptr){
        // first case: empty list
        // add new node and make headOne point to it
        headOne = new Node;
        headOne->key = newValue;
        headOne->next = nullptr; // what if we forget this line?
    }
    else if(afterMe == nullptr){
        // This condition implies that the list is not empty, but
        // the caller wants to add node before the headOne node
        Node* newNode = new Node;
        newNode->key = newValue;
        newNode->next = headOne;
        headOne = newNode;
        // at this point, we can test our code for this use case

    }
    else{
        Node* newNode = new Node;
        newNode->key = newValue;
        newNode->next = afterMe->next;
        afterMe->next = newNode;
    }


}

void SLL::deleteNode(string sKey)
{
    Node *deleteNode = search(sKey);
    if( deleteNode != nullptr)
    {
        // check if deleteNode is headOne
        if( deleteNode == headOne ){
            headOne = headOne->next;
            delete deleteNode;
        }
        //traverse the list:
        else
        {
            Node* crawler = headOne;
            // Stop at node prior the node to be deleted
            while(crawler->next != deleteNode){
                crawler = crawler->next;
            }

            // reconnect the LL around the node about to
            // be removed
            crawler->next = crawler->next->next;

            // deallocate
            delete deleteNode;
        }

    }
    else{
        cout << "Node doesn't exist. Nothing to do." << endl;
    }
}

int SLL::split(string searchKey)
{
    /*
     * Todo
     */
    Node *findK = search(searchKey);
    int returnInt = -1;

    if (headOne == nullptr && headTwo == nullptr) //both empty
    {
        returnInt = 1;
    }
    else if (findK == nullptr) //not found
    {
        returnInt = 1;
    }
    else if (headTwo != nullptr)
    {
        returnInt = 2;
    }
    else if (findK == headOne)
    {
        headTwo = headOne;
        headOne = nullptr;
        returnInt = 0;
    }
    else
    {
        headTwo = findK;
        findK = headOne;
        while (findK != headTwo)
        {
            if (findK->next == headTwo)
            {
                findK->next = nullptr;
                returnInt = 0;
                break;
            }
            findK = findK->next;
        }
    }
    
    return returnInt;
}
