//deprecated attrib demo
// using this before any function you can give user an headup that this func is deprecated you can use ohter function instead.
// But adding warning does stop you to run the code
#include <iostream>
using namespace std;
[[deprecated("use updated version of this fun -> deprcFunUpdated()")]]
void deprcFun()
{
    cout << endl << "********\n\nI am old\n\n**********";
}
void deprcFunUpdated()
{
    cout << endl << "********\n\nold is classic\n\n********";
}
int main()
{
    deprcFun();
    cout << endl;
    return 0;
}
