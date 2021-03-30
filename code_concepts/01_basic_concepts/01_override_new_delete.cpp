#include <iostream>
#include "cpprobot.h"
using namespace std;

/*
Ref: CppRobot has overridden new and delete, it can be verified if you delete (=delete) you can not instantiate on heap
 check it using g++ 01_override_new_delete.cpp -Iincludes -DNO_OBJECT_ON_HEAP
*/

class CppRobot_PN
{
    public:
    string name_;
    static unsigned int count_;

    CppRobot_PN(){
        count_++;
        name_ = std::string("myrobo").append(std::to_string(count_));
    }
};
unsigned int CppRobot_PN::count_ = 0;


void demo_placement_new()
{
    // to demo placement new we need to comment overloaded new and delete operator
    CppRobot_PN buffer[2];
    CppRobot_PN * rbt = new (&buffer[1]) CppRobot_PN(); 
    cout << endl << rbt->name_ ;
}

void demo_overload_new_delete(){
    CppRobot * rbt = new CppRobot("Robo");
    cout <<endl << "Welcome " << rbt->name_  << "!!" << endl;
    delete rbt;
}

void demo_overload_new_delete_array(){
    CppRobot * rbt = new CppRobot[2];
    cout << endl << rbt[0].name_ << " and " << rbt[1].name_;
    delete [] rbt;
}

int main()
{
    //demo_overload_new_delete();
    //demo_overload_new_delete_array();

    //placement new only provides space from the buffer.. it will call its own constructor.
    //its not casting
    demo_placement_new();

    return 0;
}