#include <iostream>
#include <string>
using namespace std;

class CppRobot
{
    public:
    string name_;
    static int counter;
    
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
void * operator new (size_t sz) = delete;
#else 
    void * operator new (size_t sz) {
        cout << endl << "allocating space for the Robot!!" << endl;
        return malloc(sizeof(CppRobot)); // can also use malloc(sz)  // we may use it for more space for given object
        //return ::new CppRobot();

    }
#endif

    void operator delete (void * p) {
        cout << endl << "freeing allocated space for the Robot!!" << endl;
        //::delete((CppRobot*)p);
        return free(p);

    }
    void * operator new [] (size_t sz) {
        cout << endl << "overloading new[] for the Robot!!" << endl;
        return malloc(sz);
        //return ::new CppRobot();

    }
    void operator delete [] (void * p) {
        cout << endl << "overloading delete[] for the Robot!!" << endl;
        //::delete((CppRobot*)p);
        return free(p);

    }
 
};

int CppRobot::counter = 0;
 