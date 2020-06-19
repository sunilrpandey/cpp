#include <iostream>
using namespace std;
/* Learning
1. Cant overried deleted function
2. Cant delete overriding function (i.e. if it is there in base)
*/

class Base
{
    public:
    virtual void funToDelete() = delete;
    virtual void funImplemented() {
        cout << "Base Implementation " << endl;
    } 
};

class Derived : public Base
{
    public:

    #if 0 
    // Cant overried deleted function
    virtual void funToDelete() override {
        cout << endl << "Was deleted in Base" << endl;
    //Cant delete overriding function (i.e. if it is there in base)
    virtual void funImplemented() = delete;
    }
    #endif
    
};

int main()
{
    Derived der;

}