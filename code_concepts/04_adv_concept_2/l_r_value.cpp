#include <iostream>
#include <stdlib.h>
using namespace std;

/*
    Observation : 
    1. const ref version is used for ravlue if && veriosn is not available
    2. if both are available, && version would be preferred.
    3. if string& (l value) value is not available const & version is used for lvalue but if 
    l value and const ref verson both are available 'lvalue' verison would be preferred by compiler
    void printName(std::string& name)
    void printName(const std::string& name)
    void printName std::string&& name)
*/


template<typename T>
void print(T& name) {
    cout << endl << "[lalue version,pure]" << endl;
}
template<typename T>
void print(const T& name){
    cout << endl << "[lalue (const ref)version, if ravlue impl is not available]" << endl;
}
template<typename T>
void print(T&& name){
    cout << endl << "[ralue version]" << endl;
}

int main()
{
    auto fn = "first";
    string ln = "last";
    auto n = fn + ln;
    print(fn);
    print(fn + ln);

    return 0;
}
