//deprecated attrib demo
// using this before any function you can give user an headup that this func is deprecated you can use ohter function instead.
#include <iostream>
using namespace std;
[[deprecated("use updated version of this fun -> deprcFunUpdated()")]]
void deprcFun()
{
    cout << endl << "I am old";
}
void deprcFunUpdated()
{
    cout << endl << "old is classic";
}
int main()
{
    deprcFun();
    cout << endl;
    return 0;
}
