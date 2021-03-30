#include <iostream>
#include <memory>
namespace ns_constructor
{
class Base
{
    int x, y, z;
public:
    Base():x(0),y(0),z(0){}
    Base(int i , int j, int k):x(i),y(j),z(k){}

    void show() {        
        std::cout << "x = " << x << "y = " << y << "z = " << z;
    }

    ~Base() {
        std::cout << "base destructor";
    } 
};

class Derived : public Base
{
    public:
    Derived():Base(){}
    Derived(int i , int j, int k){} // this will call base class default not the 3 arg constructor , should call : Base(i,j,k)

    ~Derived() {
        std::cout << "Derived destructor";
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

    std::shared_ptr<Base> b = std::make_shared<Derived>();    
}
};

int main(int argc, char* argv[]) {
    //ns_constructor::demo_call_apt_base_constructor();

    ns_constructor::demo_destructor_order_when_destructor_is_veritual();
    //ns_constructor::demo_destructor_order_when_destructor_is_not_veritual();
    return 0;
}