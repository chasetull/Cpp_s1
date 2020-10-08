#include <iostream>
#include "StackCalculator.hpp"


using namespace std;
/*
 * Purpose: Determine whether some user input string is a
 *          valid floating point number
 * @param none
 * @return true if the string s is a number
 */
bool isNumber(string s)
{
    if(s.size() == 1 && s == "-")
      return false;

    else if(s.size() > 1 && s[0] == '-')
      s = s.substr(1);

    bool point = false;
    for(int i = 0; i < s.size(); i++){
      if(!isdigit(s[i]) && s[i] != '.')
        return false;
      if(s[i]=='.' and !point) point = true;
      else if(s[i]=='.' and point) return false;
    }

    return true;
}

StackCalculator::StackCalculator()
{
  //TODO:
  stackHead = nullptr;
}

StackCalculator::~StackCalculator()
{
  //TODO:
  while (!isEmpty())
  {
    pop();
  }
}

bool StackCalculator::isEmpty()
{
	//TODO:
  return (stackHead == nullptr);
}

void StackCalculator::push(float number)
{
  //TODO:
  if (isEmpty())
  {
    Operand *newOp = new Operand;
    newOp->next = nullptr;
    newOp->number = number;
    stackHead = newOp;
    //cout << "HEAD: " << stackHead->number << endl;
  }
  else
  {
    Operand *newOp = new Operand;
    newOp->number = number;
    newOp->next = stackHead;
    stackHead = newOp;
    //cout << "pushed: " << stackHead->number << endl;
  }
}

void StackCalculator::pop()
{
	//TODO:
  if (isEmpty())
  {
    cout << "Stack empty, cannot pop an item." << endl;
  }
  else if (stackHead->next == nullptr)
  {
    Operand *n = stackHead;
    stackHead = nullptr;
    //cout << "pop: " << n->number << endl;
    delete n;
  }
  else
  {
    Operand *delOp;
    delOp = stackHead;
    stackHead = stackHead->next;
    delOp->next = nullptr;
    //cout << "pop: " << delOp->number << endl;
    delete delOp;
  }
}

Operand* StackCalculator::peek()
{
	//TODO:
  Operand *toReturn = nullptr;
  if (isEmpty())
  {
    cout << "Stack empty, cannot peek." << endl;
  }
  else
  {
    toReturn = stackHead;
  }
  
    return toReturn;
}

bool StackCalculator:: evaluate(string* s, int size)
{
    /*TODO: 1.scan the array from the end
            2.Use isNumber function to check if the input is an operand
            3.push all operands to the stack
            4.If operator take two element of from the stack,
              compute and put the result back in stack
            5.Handle the boundery cases as required.
            6.Read the writeup for more details
    */
    bool isValid = false;
    bool returnValid = false;
    //Operand *tempstack = stackHead;

    for (int i=size-1; i>-1; i--) //parsing arr from back
    {
      isValid = isNumber(s[i]);

      if (isValid) //is operand (num)
      {
        //cout << s[i] << " is number" << endl;
        float si = stof(s[i]);
        push(si);
        //peek();
      }
      else if (s[i] == "*" || s[i] == "+")//is operator 
      {
        if (isEmpty())
        {
          cout << "err: not enough operands" << endl;
          return false;
        }
        else
        {
          if (s[i] == "*")
          {
            float s1 = peek()->number;
            pop();
            float s2 = peek()->number;
            pop();

            float sT = s1 * s2;
            push(sT);
            returnValid = true;
          }
          else
          {
            float s1 = peek()->number;
            pop();
            float s2 = peek()->number;
            pop();

            float sT = s1 + s2;
            push(sT);
            returnValid = true;
          }
        }
      }

      else
      {
        cout << "err: invalid operation" << endl;
        return false;
      }
    }

		return returnValid;
}
