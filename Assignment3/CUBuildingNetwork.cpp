/****************************************************************/
/*                CUBuildingNetwork Implementation                 */
/****************************************************************/
/* TODO: Implement the member functions of class CUBuildingNetwork */
/*     This class uses a linked-list of CUBuilding structs to      */
/*     represet communication paths between buildings             */
/****************************************************************/

#include "CUBuildingNetwork.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;
/*
 * Purpose: Constructer for empty linked list
 * @param none
 * @return none
 */
CUBuildingNetwork::CUBuildingNetwork() {
    /* finished. do not touch. */
    head = NULL;
}

/*
 * Purpose: Check if list is empty
 * @return true if empty; else false
 */
bool CUBuildingNetwork::isEmpty()
{
/* finished. do not touch. */
    return (head == NULL);
}

/*
 * Purpose: Add a new building to the network
 *   between the building *previous and the Building that follows it in the network.
 * @param previous name of the Building that comes before the new Building
 * @param buildingName name of the new Building
 * @param numOfroom
 * @return none
 */
void CUBuildingNetwork::addBuildingInfo(CUBuilding* previous, string buildingName, int numOfroom) {

    bool needInsert = false;
    CUBuilding *insertAdd = previous;

    //no elements in ll
    if (previous == NULL)
    {
        if (head != NULL) //change head
        {
            //add to head of ll
            CUBuilding *newBuilding = new CUBuilding;
            newBuilding->name = buildingName;
            newBuilding->totalRoom = numOfroom;

            newBuilding->next = head;
            head = newBuilding;

            cout << "adding: " << buildingName << " (HEAD)" << endl;
        }

        else
        {
            CUBuilding *newBuilding = new CUBuilding;
            newBuilding->name = buildingName;
            newBuilding->totalRoom = numOfroom;
            head = newBuilding;
            previous = head;

            cout << "adding: " << buildingName << " (HEAD)" << endl;
        }
    }

    else
    {
        
        //loop through ll to find vacancy
        CUBuilding *buildBefore = previous;
        CUBuilding *prePrev = previous;
        previous = head;

        while (previous->next != NULL)
        {
            //if prev matches node to be inserted
            if (previous->name == buildBefore->name)
            {
                needInsert = true;
                break;
            }

            prePrev = previous;
            previous = previous->next;
        }

        if (!needInsert)
        {

            //now next node is null
            //make new node to add to ll

            CUBuilding *newBuilding = new CUBuilding;
            CUBuilding *parseLL = previous;

            newBuilding->name = buildingName;
            newBuilding->totalRoom = numOfroom;
            previous->next = newBuilding;
            parseLL = previous;

            cout << "adding: " << newBuilding->name << " (prev: " << parseLL->name << ")" << endl;
        }

        else if (needInsert)
        {
            CUBuilding *newlyInsertedBuilding = new CUBuilding;
            CUBuilding *copyOfNew = previous->next;
            newlyInsertedBuilding->name = buildingName;
            newlyInsertedBuilding->totalRoom = numOfroom;

            previous->next = newlyInsertedBuilding;
            newlyInsertedBuilding->next = copyOfNew;

            cout << "adding: " << newlyInsertedBuilding->name << " (prev: " << prePrev->name << ")" << endl;
        }
    }
    
}


/*
 * Purpose: populates the network with the predetermined buildings
 * @param none
 * @return none
 */
void CUBuildingNetwork::loadDefaultSetup()
{
    //intantiate vars
    CUBuilding *firstbuild = new CUBuilding;
    CUBuilding *ptr = firstbuild;
    CUBuilding *secondbuild = new CUBuilding;
    CUBuilding *ptr2 = secondbuild;
    CUBuilding *thirdbuild = new CUBuilding;
    CUBuilding *ptr3 = thirdbuild;
    CUBuilding *fourthbuild = new CUBuilding;
    CUBuilding *ptr4 = fourthbuild;
    CUBuilding *fifthbuild = new CUBuilding;
    CUBuilding *ptr5 = fifthbuild;
    CUBuilding *sixthbuild = new CUBuilding;
    CUBuilding *ptr6 = sixthbuild;

    addBuildingInfo(NULL, "FLMG", 2); //1st instance

    addBuildingInfo(ptr, "DLC", 10); //2nd instance

    addBuildingInfo(ptr2, "ECOT", 6); //3rd instance

    addBuildingInfo(ptr3, "CASE", 5); //4th instance

    addBuildingInfo(ptr4, "AERO", 4); //5th instance

    addBuildingInfo(ptr5, "RGNT", 9); //6th instance
}

/*
 * Purpose: Search the network for the specified building and return a pointer to that node
 * @param buildingName name of the building to look for in network
 * @return pointer to node of buildingName, or NULL if not found
 *
 */
CUBuilding* CUBuildingNetwork::searchForBuilding(string buildingName)
{
    bool notFound = false;
    CUBuilding *searchTemp = head;

    while (searchTemp->name != buildingName)
    {
        if (searchTemp->next == NULL) //building name not found
        {
            notFound = true;
            break;
        }

        searchTemp = searchTemp->next;
    }

    if (searchTemp->name == buildingName) //building name found
    {
        return searchTemp;
    }

    if (notFound)
    {
        return NULL;
    }
    //return;
}


/*
 * Purpose:
 * @param string receiver
 * @param string msg
 */
void CUBuildingNetwork::transmitRoomInfo(string receiver) {
    //error check nothing in ll
    if (head == NULL)
    {
        cout << "Empty list" << endl;
        return;
    }
    
    //search ll to see if node name == receiver
    CUBuilding *searchRec = searchForBuilding(receiver);
    CUBuilding *searchTemp = searchRec;

    //if not found
    if (searchRec == NULL)
    {
        cout << "Building not found" << endl;
        return;
    }

    //if found
    else
    {
        searchRec = head;

        while (searchRec != NULL)
        {
            searchRec->message = "available room at " + searchRec->name + " is " + to_string(searchRec->totalRoom);
            searchRec->numberMessages += 1;
            cout << searchRec->name << "[# messages received: " << searchRec->numberMessages << "] received: " << searchRec->message << endl;
            searchRec = searchRec->next;

            if (searchRec->name == searchTemp->name) //if node found
            {
                searchRec->message = "available room at " + searchRec->name + " is " + to_string(searchRec->totalRoom);
                searchRec->numberMessages += 1;
                cout << searchRec->name << "[# messages received: " << searchRec->numberMessages << "] received: " << searchRec->message << endl;
                return;
            }
        }
    }
    
}

/*
 * Purpose: prints the current list nicely
 * @param ptr head of list
 */
void CUBuildingNetwork::printNetwork() {
    if (head == NULL)
    {
        cout << "=== CURRENT PATH ===" << endl;
        cout << "nothing in path" << endl;
        cout << "===" << endl;
    }

    else
    {
        cout << "=== CURRENT PATH ===" << endl;

        CUBuilding *pathParse = head;

        while (pathParse != NULL)
        {
            cout << pathParse->name << "(" << pathParse->totalRoom << ") -> ";
            pathParse = pathParse->next;
        }

        cout << "NULL" << endl;

        cout << "===" << endl;
    }
    
}

