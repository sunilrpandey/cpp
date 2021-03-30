#include <iostream>
#include <typeinfo>
#include <chrono>
using namespace std;
using namespace chrono;

void printTime(milliseconds ms){
    cout << endl << "millisecond equivalend : " << ms.count();
}

int main()
{
    // h - hrs, min - min, s - second, ms - millisecond, us - microsecond, ns - nanoseconds
    seconds s{}; // initialize with zero
    cout << s.count();


    auto sa = 10s; //supported in c++ 14 only
    cout << "\n let compiler deduce its type : s means second -> " << sa.count() << endl;
    printTime(sa);

    auto m = 2min;
    cout << "\n let compiler deduce its type : min means minuts -> " << m.count() << endl;
    printTime(m);

    auto s_cstringtype = "Sunil"; // deduces const char * , 
    cout << endl << "raw string type : " << typeid(s_cstringtype).name();

    auto s_stdstringtype = "Sunil"s;
    cout << endl << "std string type : " << typeid(s_stdstringtype).name(); // deduces std::string but if it is after int it will be seconds

    cout << endl;

    return 0;
}