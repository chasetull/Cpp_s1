#include <iostream>
#include <string>
#include <vector>
using namespace std;
#include "SLL.hpp"
int main()
{
  SLL s1("demo");
  cout<< "before"<<endl;
  s1.displayList();
  cout<< "after"<<endl;
  s1.split("fluffy");
  s1.displayList();

  //my tests
  SLL s2("demo");
  cout<< "before"<<endl;
  s2.displayList();
  cout<< "after"<<endl;
  s2.split("the");
  s2.displayList();

  SLL s3("demo");
  cout<< "before"<<endl;
  s3.displayList();
  cout<< "after"<<endl;
  s3.split("cat");
  s3.displayList();

  return 0;
}
