#include <iostream>
#include "cpprobot.h"
using namespace std;

int main()
{
    //Operator new and delete
    {
        CppRobot * rbt = new CppRobot("Robo");
        cout <<endl << "Welcome " << rbt->name_  << "!!" << endl;
        delete rbt;
    }
    //Operator new[] and delete[]
    {
        CppRobot * rbt = new CppRobot[2];
        cout << endl << rbt[0].name_ << " and " << rbt[1].name_;
        delete [] rbt;
    }
    {
        // to demo placement new we need to comment overloaded new and delete operator
        CppRobot buffer[2];
        CppRobot * rbt = new (buffer) CppRobot("sunil"); 
        cout << endl << rbt->name_ ;
    }
    return 0;
}