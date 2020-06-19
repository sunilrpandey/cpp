#include <iostream>
#include "cpprobot.h"
using namespace std;

/*
Ref: CppRobot has overridden new and delete, it can be verified if you delete (=delete) you can not instantiate on heap
 check it using g++ 01_override_new_delete.cpp -Iincludes -DNO_OBJECT_ON_HEAP
*/

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

#if 0 //placement new  demo
    {
        // to demo placement new we need to comment overloaded new and delete operator
        CppRobot buffer[2];
        CppRobot * rbt = new (buffer) CppRobot("sunil"); 
        cout << endl << rbt->name_ ;
    }
#endif
    return 0;
}