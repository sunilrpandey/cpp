#include <iostream>
using namespace std;

//this example mimics runtime polymorphism
template <typename T>
class Base
{
    public:
    void init() { cout << endl << "init done";}
    void funToBeOverridden() {cout << "\nBase Impl";}
    void cleanup() { cout << endl << "cleanup done";}
    void demoDynamicPolymorphism() {
        init();
        static_cast<T*>(this)->funToBeOverridden();
        cleanup();
    }
};
class Derived : public Base<Derived>
{
    public:
    void funToBeOverridden() {cout << "\nDerived Impl";}
};

int main()
{
    Base<Derived> der_base;
    der_base.demoDynamicPolymorphism();

    Derived d;
    d.demoDynamicPolymorphism();

    cout << endl;
    return 0;
}
