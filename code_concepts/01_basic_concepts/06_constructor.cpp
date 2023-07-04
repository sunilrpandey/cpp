#include <iostream>
#include <memory>
using namespace std;
namespace ns_constructor
{
class Base
{
public:
    int x, y, z;
public:
    Base():x(0),y(0),z(0){
        cout << "\nBase Default constructor!!";
    }
    Base(int i , int j, int k):x(i),y(j),z(k){
        cout << "\nBase Parameterized constructor!!";
    }

    void show() {        
        std::cout << "\nx = " << x << "y = " << y << "z = " << z;
    }

    // virtual ~Base() {
    ~Base() {
        std::cout << "\nbase destructor";
    } 
};

class Derived : public Base
{
    public:
    Derived():Base(){
        cout << "\nDervied Parameterized constructor!!";
    }
    Derived(int i , int j, int k){
        x = i;
        y = j;
        z = k;
        cout << "\nDerived Parameterized constructor!!";
    } // this will call base class default not the 3 arg constructor , should call : Base(i,j,k)

    ~Derived() {
        std::cout << "\nDerived destructor";
    }
};

void demo_call_apt_base_constructor() {
    Derived der(10,20,30);
    der.show();
}

void demo_destructor_order_when_destructor_is_veritual() {

    Base * b = new Derived();
    delete b;
}
void demo_destructor_order_when_destructor_is_not_veritual() {

    cout << "\nget correct destruction order by using shared pointer" << endl;
    std::shared_ptr<Base> b = std::make_shared<Derived>();    
}
};

int main(int argc, char* argv[]) {
    // ns_constructor::demo_call_apt_base_constructor();

    // ns_constructor::demo_destructor_order_when_destructor_is_veritual();
    ns_constructor::demo_destructor_order_when_destructor_is_not_veritual();
    return 0;
}