#include "ex1.hpp"
#include "string"

using namespace std;

int main()
{
    QueArrCir q0;

    q0.enque("wind");

    string s;
    s = q0.deque();
    return 0;
}