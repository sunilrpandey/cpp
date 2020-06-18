#include <iostream>
using namespace std;

class Final;
class BaseFinal
{
    private:
    BaseFinal(){}
    public:
    ~BaseFinal(){};
    friend Final;
};
class Final : public virtual BaseFinal
{
    public:
    static const int i = 10;
};

#if FINAL_CLASS_OBJECT
    
class DerivedFormFinalClass : public Final
{
    public:
     DerivedFormFinalClass(){}
      ~DerivedFormFinalClass(){}

};
#endif

#define FINAL_CLASS_OBJECT 0
 
int main()
{
    #if FINAL_CLASS_OBJECT
    DerivedFormFinalClass final_obj;
    cout << final_obj.i << endl; 
    #else 
    cout << "Final class implementation, to check see #if part" << endl;
    #endif

    return 0;
}