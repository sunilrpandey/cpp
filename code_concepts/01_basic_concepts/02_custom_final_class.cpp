#include <iostream>
using namespace std;

// Create a Base class with its constructor in private section so that it can be used/derived by a class that is friend to it.
// Create a derived class(Custom Final class) and make it friend with base class so that it can access its base's constructor.
// Now no class can derive from derived class above as it indirectly it would have to access base class constructor which would not be allowed 
// if it is not friend to base class 

class Final;
//class DerivedFormFinalClass;
class BaseFinal
{
    private:
    BaseFinal(){}
    public:
    ~BaseFinal(){};
    friend Final;
    //friend DerivedFormFinalClass;
};
class Final : public virtual BaseFinal
{
    public:
    static const int i = 10;
};

#define FINAL_CLASS_OBJECT 0

#if FINAL_CLASS_OBJECT
    
class DerivedFormFinalClass : public Final
{
    public:
     DerivedFormFinalClass(){}
      ~DerivedFormFinalClass(){}

};
#endif

 
int main()
{
    #if FINAL_CLASS_OBJECT
    DerivedFormFinalClass final_obj;
    cout << final_obj.i << endl; 
    #else 
    #endif

    return 0;
}