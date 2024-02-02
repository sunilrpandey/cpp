#include <iostream>
#include <initializer_list>
using namespace std;
#define MULTIPLE_DEFINE_TEST 10 // it overwritten value would be visible to all the 

void draw_banner(const std::string& demo_name){
    std::cout << "\n============================================" << std::endl;
    std::cout << "=====         Demo: " << demo_name << "       ======" << std::endl;
    std::cout << "============================================\n" << std::endl;    
}




namespace ns_multdefine
{
void modifyDefine(){
   // #define MULTIPLE_DEFINE_TEST 20
    cout << MULTIPLE_DEFINE_TEST;
}
void testDefine(){
    cout << MULTIPLE_DEFINE_TEST;
}

void demo() {

    // multiple defines test
    cout << "init define value :" << MULTIPLE_DEFINE_TEST << endl;
    modifyDefine();
    testDefine();    
}
};

namespace ns_misc
{
void demo_typedefine(){
    std::cout << endl << "typedef doubt\n";
    typedef int * i;
    int j = 10;
    i pJ = &j;
    cout << *pJ;
}

void demo_init_static_with_local(){
    // Can static variable init with local variable ?  yes
    int x = 10;
    static int y = x;
    cout << "\nCan static variable init with local variable? Ans : " << (x == y);
}

class A
{
    int i; 
    int arr[5];
};
void demo_size_of_empty_arr(){
    A arr[] = {};
    cout << endl << "Sizeof empty array is (exected zero) : " << sizeof(arr);    // is zero
}
};

namespace ns_initlist
{
    class X 
    {
    public:
        int x;
        float y;
        float z;
    X(int i = 0, float j = 0, float k = 0):x(i),y(j),z(k){        
    }
    X(std::initializer_list<float> col){
        x = 100; 
        auto a  = col.begin();
        y = *a;
        a++;
        z = *a;
    }

    void show() {
        std::cout << "x = " << x << "y = " << y << "z = " << z << std::endl;
    }
    };
 
void demo(){
    ::draw_banner("Init from init list");
    
    X a = {10,20,30}; // initlist will get priority over constructor
    a.show();
    X b = a;
    b.show();
}  

};

namespace ns_copyconstructor
{
class Point
{
    int x, y;
public:
    Point(int i = 0, int j = 0) { x = i; y = j; }
    //Point(const Point&) = delete; // no default copy constructor would be called if uncomment this line or define and keep it in private section
    int getX() { return x; }
    int getY() { return y; }
};

void demo_no_copy_constructor() { //default would be called
    Point p1(3,5);
    Point p2 = p1; // will give error if copy constructor is private or deleted
    cout << "x = " << p2.getX() << " y = " << p2.getY() << std::endl;
    }
}

int main()
{
    ns_multdefine::demo();
    ns_misc::demo_typedefine();
    ns_misc::demo_init_static_with_local();
    ns_misc::demo_size_of_empty_arr();
    ns_initlist::demo(); 
    
    //ns_copyconstructor::demo_no_copy_constructor();
    
    return 0;
}