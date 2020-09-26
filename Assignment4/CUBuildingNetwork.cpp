/****************************************************************/
/*                CUBuildingNetwork Implementation                 */
/****************************************************************/
/* TODO: Implement the member functions of class CUBuildingNetwork */
/*     This class uses a linked-list of Building structs to      */
/*     represet communication paths between nations             */
/****************************************************************/

#include "CUBuildingNetwork.hpp"
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
 * Purpose: Add a new building to the network between the building *previous and the building that follows it in the network.
 * @param previous name of the Building that comes before the new Building
 * @param buildingName name of the new Building
 * @param numOfroom
 * @return none
 */
void CUBuildingNetwork::addBuildingInfo(CUBuilding* previous, string buildingName, int numOfroom) {
    // if we are passed an empty list, just create a new head node, and return

    if (head == NULL)
    {
        cout << "adding: " << buildingName << " (HEAD)" << endl;
        head = new CUBuilding;
        head->name = buildingName;
        head->numberMessages = 0;
        head->totalRoom = numOfroom;

        head->next = NULL;
    }
    // if it's not empty, we need to search for previous and append our node there.
    else if(previous == NULL )
    {
        cout << "adding: " <<buildingName<< " (HEAD)" << endl;
        CUBuilding *c = new CUBuilding;
        c->name = buildingName;
        c->numberMessages = 0;
        c->next = head;
        c->totalRoom = numOfroom;

        head = c;
    }else{
        cout << "adding: " << buildingName << " (prev: " << previous->name << ")" << endl;
        CUBuilding *newBuilding = new CUBuilding;
        newBuilding->name = buildingName;
        newBuilding->numberMessages = 0;
        newBuilding->next = previous->next;
        newBuilding->totalRoom = numOfroom;

        previous->next = newBuilding;
    }
}

/*
 * Purpose: populates the network with the predetermined buildings
 * @param none
 * @return none
 */
void CUBuildingNetwork::loadDefaultSetup()
{
    int num_buildings = 6;
    string buildings[] = {"FLMG", "DLC", "ECOT", "CASE", "AERO", "RGNT"};
    int rooms[] = {2,10,6,5,4,9};
    head = NULL;
    CUBuilding* prev = NULL;
    for(int i = 0; i < num_buildings; i++)
    {
        addBuildingInfo(prev, buildings[i],rooms[i]);
        prev = searchForBuilding(buildings[i]);
    }
}

/*
 * Purpose: Search the network for the specified building and return a pointer to that node
 * @param buildingName name of the building to look for in network
 * @return pointer to node of buildingName, or NULL if not found
 *
 */
CUBuilding* CUBuildingNetwork::searchForBuilding(string buildingName)
{
    // Search until the head is NULL, or we find the building
    CUBuilding* ptr = head;
    while (ptr != NULL && ptr->name != buildingName)
    {
        ptr = ptr->next;
    }
    // Return the node, or NULL
    return ptr;
}

/*
 * Purpose: prints the current list nicely
 * @param ptr head of list
 */
void CUBuildingNetwork::printNetwork() {
    cout << "== CURRENT PATH ==" << endl;
    // If the head is NULL
    CUBuilding* ptr = head;
    if (ptr == NULL)
        cout << "nothing in path" << endl;

    // Otherwise print each node, and then a NULL
    else
    {
        while (ptr != NULL)
        {
            cout << ptr->name << "(" << ptr->totalRoom << ")" <<" -> ";
            ptr = ptr->next;
        }
        //cout << ptr->name << " -> ";
        cout << "NULL" << endl;
    }
    cout << "===" << endl;
  }

/*
 * Purpose: delete the building in the network with the specified name.
 * @param buildingName name of the building to delete in the network
 * @return none
 */
void CUBuildingNetwork::deleteCUBuilding(string buildingName) {
    //TODO: Complete this function
    if (isEmpty())
    {
        cout << "List is empty" << endl;
    }
    else
    {
        CUBuilding *curr = head;
        CUBuilding *previous = head;
        CUBuilding *temp;
        temp = searchForBuilding(buildingName);

        if (temp == nullptr)
        {
            cout << "Building does not exist" << endl;
        }
        else if (temp == head)
        {
            if (head->next != nullptr)
            {
                head = head->next;
                curr->next = nullptr;
                cout << "deleting: " << curr->name << endl;
                delete curr;
                curr = head;
                
            }
            else
            {
                cout << "deleting: " << curr->name << endl;
                delete curr;
                head = nullptr;
            }
        }
        else
        {
            while (curr != nullptr)
            {

                if (curr->name == buildingName)
                {
                    cout << "Building found: " << buildingName << endl;
                    previous->next = curr->next;
                    curr->next = nullptr;
                    delete curr;
                    break;

                }
                else
                {
                    previous = curr;
                    curr = curr->next;
                }
                
            }
        }

        
    }
    
    
}

/*
* Purpose: Creates a loop from last node to the building specified.
* @param buildingName name of the building to loop back
* returns the last node before loop creation (to break the loop)
*/
CUBuilding* CUBuildingNetwork::createLoop(string buildingName) {
    //TODO: Complete this function
    CUBuilding *temp = searchForBuilding(buildingName);

    if (temp == nullptr)
    {

    }
}

/*
 * Purpose: deletes all buildings in the network starting at the head building.
 * @param: none
 * @return: none
 */
void CUBuildingNetwork::deleteEntireNetwork()
{
    //TODO: Complete this function
    CUBuilding *curr = head;
    CUBuilding *prev = head;

    if (isEmpty())
    {
        return;
    }
    else
    {
        while (curr != nullptr)
        {
            if (head->next == nullptr)
            {
                head = nullptr;
                cout << "deleting: " << curr->name << endl;
                delete curr;
                cout << "Deleted network" << endl;
                break;
            }
            prev = curr;
            curr = curr->next;
            prev->next = nullptr;
            head = curr;
            cout << "deleting: " << prev->name << endl;
            delete prev;
            

        }
    }
}

/*
 * Purpose: to detect loop in the linkedlist
 * @return: true if loop is detected.
 */
bool CUBuildingNetwork::detectLoop() {
    //TODO: Complete this function
}

/*
 * Purpose: Take the chunk of nodes from start index to end index
 *          Move that chunk at the end of the List
 * @param: start index, end index
 * @return: none
 */
void CUBuildingNetwork:: readjustNetwork(int start_index, int end_index)
{
    //TODO: Complete this function
}