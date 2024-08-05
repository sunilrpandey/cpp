/*
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
class Final : public BaseFinal
{
    public:
    Final():BaseFinal(){}
    static const int i = 10;
};

//test comments for final class object
#define FINAL_CLASS_OBJECT 1

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
*/
#include <iostream>

class Final;

// Uncommenting this line will cause compilation error because of access to private constructor of BaseFinal
// class DerivedFormFinalClass;

class BaseFinal {
private:
    BaseFinal() {} // Private constructor
    // void funtest() {
    //     std::cout << "\n..testing";
    // }

public:
    ~BaseFinal() {}
    friend class Final; // Only Final is a friend and can instantiate BaseFinal
};

class Final : public BaseFinal {
public:
    static const int i = 1001;

    Final() : BaseFinal() {
        //funtest();
    } // Provide access to BaseFinal's private constructor
};

// The following class will not compile because it tries to derive from Final,
// which is designed to be the final class in the hierarchy.
class DerivedFormFinalClass : public virtual Final {
public:
    DerivedFormFinalClass() {}
    ~DerivedFormFinalClass() {}
};

int main() {
    // This line will fail to compile because DerivedFormFinalClass cannot access the private constructor of BaseFinal
    DerivedFormFinalClass final_obj;

    // Uncommenting the line above will cause a compilation error
    std::cout << final_obj.i << std::endl; // This will also fail because final_obj is not instantiated
    // Instead, you can create an object of the Final class directly
    //Final final_obj;
    //std::cout << final_obj.i << std::endl; // This will print 10

    return 0;
}
