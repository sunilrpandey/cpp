#include <iostream>
#include <stdlib.h>
using namespace std;

/*
    Observation : 
    1. const ref version is used for ravlue if && veriosn is not available
    2. if both are available && version would be preferred.
    3. if string& (l value) value is not available const & version is used for lvalue but if 
    l value and const ref verson both are available 'lvalue' verison would be preferred by compiler
    void printName(std::string& name)
    void printName(const std::string& name)
    void printName std::string&& name)
*/


// to take both i & 
//i.e. works if && version of function is not available
void setValue(const int& value)
{


}
void printName(std::string& name)
{
    cout << endl << "[lalue version,pure]" << endl;

}

//i.e. works if && version of function is not available
void printName(const std::string& name)
{
    cout << endl << "[lalue version, if ravlue impl available]" << endl;

}

//preferred over const string& verson for temp values 
void printName(std::string&& name)
{
    cout << endl << "[ralue version]" << endl;

}

int main()
{
    int i = 10;
    const int& a = 10;
    setValue(i);
    setValue(10);

    string fn = "sunil";
    string ln = "pandey";
    string n = fn + ln;
    printName(fn);
    printName(fn + ln);

    return 0;
}
