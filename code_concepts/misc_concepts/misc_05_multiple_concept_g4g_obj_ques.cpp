#include <iostream>
using namespace std;
#define MULTIPLE_DEFINE_TEST 10 // it overwritten value would be visible to all the 
class Base
{
    public:
    int arr[10];

};
class MidDer1 : public Base
{

};
class MidDer2 : public Base
{
    
};
class Derived :public MidDer1, public MidDer2{

};

Base fun1()
{
    return Base();
}

void modifyDefine(){
   // #define MULTIPLE_DEFINE_TEST 20
    cout << MULTIPLE_DEFINE_TEST;
}
void testDefine(){
    cout << MULTIPLE_DEFINE_TEST;
}

int main()
{
    #if 1 // SIZEOF DERIVED CLASS 
    cout << endl << "Check size of derived to observe how top base data is copied to bottom derived if not virtually derived.";
    int sz = sizeof(Derived)/sizeof(int);
    cout << "Check if Derived has two copy of top base, sizeof Derived : " << sz  ;

    //Base fun1(); // Compilable even if it does not receive return value in any variable
    #endif

    // multiple defines test
    cout << "init define value :" << MULTIPLE_DEFINE_TEST << endl;
    modifyDefine();
    testDefine();
    
    
    cout << endl << "typedef doubt\n";
    typedef int * i;
    int j = 10;
    i pJ = &j;
    cout << *pJ;

    // Can static variable init with local variable ?
    int x = 10;
    static int y = x;
    cout << "\nCan static variable init with local variable? Ans : " << (x == y);

    // size of empty array
    int arr[] = {};
    cout << endl << "Sizeof empty array is (exected zero) : " << sizeof(arr);
    
    
    cout << endl << "Init from init list";
    class X 
    {
    public:
        int x;
    };
 
    X a = {10};
    X b = a;
    cout << a.x << " " << b.x;

    cout << endl << "What if copy constructor not defined,(default will be used) ";
    class Point
    {
        int x, y;
    public:
    Point(int i = 0, int j = 0) { x = i; y = j; }
    int getX() { return x; }
    int getY() { return y; }
    };
 
    Point p1;
    Point p2 = p1;
    cout << "x = " << p2.getX() << " y = " << p2.getY() ;

    cout << endl;
    return 0;
}