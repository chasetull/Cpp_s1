#include <iostream>
using namespace std;

int main()
{
    int a = 10;
    int b = 35;
    int *pa = &a;
    int *pb = &b;
    *pa = *pa + *pb;
    b = b - 15;

    cout << a << *pb << endl;
}