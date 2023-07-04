#include <iostream>
#include "cpprobot.h"
#include <string>
using namespace std;
/* // Uncomment it if find any issues with includes file while debugging
class CppRobot
{
    public:
    string name_;
    static const int k = 32;
    static int counter;
    char ar[100];
    
    // constructor 
    CppRobot(const string & str = ""):name_(str){
        name_.append(to_string(counter++));
        cout <<  "\nBirth : " << name_.c_str(); 
    }
    // construction from init list 
    CppRobot(const initializer_list<string>& vec_str){
        name_ = *(vec_str.begin());
        CppRobot(name_);
    }


    // construction from init list 
    CppRobot(const CppRobot& rhs){
        name_ = rhs.name_;
    }
    // assignment operator
    CppRobot& operator = (const CppRobot& rhs) {
        name_ = rhs.name_;
        return *this;
    }
    // construction from init list 
    CppRobot(CppRobot&& rhs){
        name_ = rhs.name_;
        rhs.name_ = "";
    }
    // assignment operator
    CppRobot& operator = (CppRobot&& rhs) {
        name_ = rhs.name_;
        rhs.name_ = "";
        return *this;
    }
        
    //distructor 
    ~CppRobot(){
        cout << "\nDeath : " << name_.c_str(); 
    }

#if NO_OBJECT_ON_HEAP
cout << "NO_OBJECT_ON_HEAP is defined now :";
void * operator new (size_t sz) = delete;
#elif 0 
    void * operator new (size_t sz) {// sz is size of class 
        #if 1
        cout << "May not needed sz :" << sz;
        #endif
        cout << endl << "Allocating space for the Robot using custom new!!" << endl;
        return malloc(sizeof(CppRobot)); // can also use malloc(sz)  // we may use it for more space for given object
        //return ::new CppRobot();

    }
#endif

    // void operator delete (void * p) {
    //     cout << endl << "freeing allocated space for the Robot!!" << endl;
    //     //::delete((CppRobot*)p);
    //     return free(p);

    // }
    // void * operator new [] (size_t sz) { 
    //     cout << "Total object :" << sz << endl;
    //     cout << "Size of CPPRobot :" << sizeof(CppRobot);
    //     cout << endl << "overloading new[] for the Robot!!" << endl;
    //     return malloc(sz);
    //     //return ::new CppRobot();

    // }
    // void operator delete [] (void * p) {
    //     cout << endl << "overloading delete[] for the Robot!!" << endl;
    //     //::delete((CppRobot*)p);
    //     return free(p);

    // }
 
};

int CppRobot::counter = 0;
*/

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