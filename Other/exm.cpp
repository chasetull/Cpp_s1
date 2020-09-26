#include <iostream>
using namespace std;

int sumNum = 19;

void change(int* &ptr)
{
    ptr = &sumNum;
}

int main()
{
    int a = 9;
    int *pa = &a;
    change(pa);
    cout << *pa << endl;
}