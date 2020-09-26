#include "LinkedList.h"

using namespace std;

// Add a new node to the list
void LinkedList::insert(Node* prev, int newKey){

  //Check if head is Null i.e list is empty
  if(head == NULL){
    head = new Node;
    head->key = newKey;
    head->next = NULL;
  }

  // if list is not empty, look for prev and append our node there
  else if(prev == NULL)
  {
      Node* newNode = new Node;
      newNode->key = newKey;
      newNode->next = head;
      head = newNode;
  }

  else{

      Node* newNode = new Node;
      newNode->key = newKey;
      newNode->next = prev->next;
      prev->next = newNode;

    }
  }


// TODO: SILVER PROBLEM
// Delete node at a particular index
bool LinkedList::deleteAtIndex(int n)
{
  bool isDeleted = false;

  if(head == NULL){
    cout<< "List is already empty"<<endl;
    return isDeleted;
  }

  // Special case to delete the head
  if (n == 0) {
      //TODO
      Node *temp = head;
      //temp = head->next;
      head = head->next;
      temp->next = NULL;

      isDeleted = true;
  }

  else
  {
    Node *pres = head;
    Node *prev = NULL;

      // TODO
    int count = 0;

    while (count < n)
    {
      prev = pres;
      pres = pres->next;
      count++;
    }

    if (pres->next != NULL)
    {
      prev->next = pres->next;
      pres->next = NULL;

      isDeleted = true;
    }
  }
  
	return isDeleted;
}

// TODO: GOLD PROBLEM
// Swap the first and last nodes (don't just swap the values)
bool LinkedList::swapFirstAndLast()
{
    bool isSwapped = false;

    if(head == NULL) {
        cout << "List is empty. Cannot swap" << endl;
        return false;
    }

    // TODO (take care of the edge case when your linkedlist has just 2 nodes)
    if (head->next != NULL)
    {
      Node *prev = head;
      Node *nextNode = head->next;
      
      //2 links in list
      if (nextNode->next == NULL)
      {
        prev->next = NULL;
        nextNode->next = prev;
        head = nextNode;
        isSwapped = true;
      }

      //more than 2 nodes in ll
      else
      {
        while (nextNode->next != NULL)
        {
          prev = nextNode;
          nextNode = nextNode->next;
        }

        //swap 1st and last
        Node *newHead = head->next;
        prev->next = NULL;
        head->next = NULL;
        prev->next = head;
        
        head = newHead;
        nextNode->next = NULL;

        nextNode->next = head;
        head = nextNode;
        
        isSwapped = true;
      }
    }

    return isSwapped;
}

// Print the keys in your list
void LinkedList::printList(){
  Node* temp = head;

  while(temp->next != NULL){
    cout<< temp->key <<" -> ";
    temp = temp->next;
  }

  cout<<temp->key<<endl;
}

// Search for a specified key and return a pointer to that node
Node* LinkedList::searchList(int key) {

    Node* ptr = head;
    while (ptr != NULL && ptr->key != key)
    {
        ptr = ptr->next;
    }
    return ptr;
}
