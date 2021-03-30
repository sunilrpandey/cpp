#include <iostream>
#include <algorithm>
#include <functional>
#include <array>

using namespace std;
using namespace placeholders;


bool greaterThan(int num, int val)
{
    return num > val;
}
//template<typename T> // cpp 14 onward passing param as auto is allowed
bool passLambdaFunctionTest_ifAny(const std::array<int,5>& int_array,auto func){

    auto greaterthan_5 = std::bind(greaterThan,_1,50);
    return std::any_of(int_array.cbegin(), int_array.cend(), func); 
}
int main() 
{
    auto a = 5; // double
    auto d{2.3};// works

    array<int,5> int_array = {3,4,5,6,7};

    cout << "\n ..use auto for var to iterate for loop, use const ref if you dont want to get copy \n";
    for(auto i : int_array) 
        cout << i << "\t";

    cout << "\n...Using auto ref in for values to update container content";
    for(auto& i : int_array)
        i*=10;

    cout << "\nDisplay values after modification using for_each and lambda function for display value";
    for_each(int_array.begin(), int_array.begin() + sizeof(int_array)/sizeof(int_array[0]),[](int n) {cout << n << "\t";});

    auto greaterthan_n = std::bind(greaterThan,_1,50);
    cout <<"\nAll greater than 50 ? Ans : " << std::boolalpha << std::all_of(int_array.begin(), int_array.end(), [&](int n ) {
                                                        return greaterthan_n(n);
                                                    });

    auto checkIfAnyGreaterThan_n = [&](int n ) {
        //auto greaterthan_n1 = std::bind(greaterThan,_1,50); // to avoid [&] use this
    
                                                    return greaterthan_n(n);
                                                };

    cout <<"\nAny greater than 65 ? Ans : " << std::boolalpha << passLambdaFunctionTest_ifAny(int_array,checkIfAnyGreaterThan_n);
    
    
    return 0;
}
