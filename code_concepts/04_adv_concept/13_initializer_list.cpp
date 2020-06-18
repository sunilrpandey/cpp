#include <iostream>
#include <initializer_list>
using namespace std;

struct Number
{
    int value_{30}; // last priority
    Number(){}
    Number(int val): value_(val)
    { 
        cout << "\nSecond priority: Constructor called.";
    }
    Number(const std::initializer_list<int>& vec) {
        cout << "\nFirst priority: initializer list called..";
        value_ = *vec.begin();
    }
};

int main()
{
    Number number; // can not say number = {30} , if Number(int) or Number(init_list ) is not defined
    cout << "\ninit member directly, value : " << number.value_;
    
    Number number_from_uniform_init_value{30};// same as number_from_initlist{40}
    cout << "\nvalue : " << number_from_uniform_init_value.value_;

    Number number_from_initlist{40}; // same as number_from_initlist{40}
    cout << "\nvalue : " << number_from_initlist.value_;
    
    cout << endl;
    return 0;
}