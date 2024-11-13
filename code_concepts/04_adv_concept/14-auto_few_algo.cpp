#include <iostream>
#include <algorithm>
#include <functional>
#include <array>

using namespace std;
using namespace placeholders;


void displayUpdatedValues_usingLambdaFunc(array<int, 5>& int_array) {
    
    // for_each is an algo which applies a function on each element of container
    for_each(int_array.begin(), 
        int_array.begin() + sizeof(int_array) / sizeof(int_array[0]), 
        [](int n) {
            std::cout << n << "\t"; 
        }
    );
}

bool greaterThan(int num, int val)
{
    return num > val;
}

int main()
{
    auto a = 5; // double
    auto d{ 2.3 };// works

    array<int, 5> int_array = { 3,4,5,6,7 };

    std::cout << "\n ..use auto for var to iterate for loop, use const ref if you dont want to get copy \n";
    for (auto i : int_array)
        std::cout << i << "\t";

    std::cout << "\n...Using auto ref in for values to update container content";
    for (auto& i : int_array)
        i *= 10;

    std::cout << "\nDisplay values after modification using for_each and lambda function for display value" << endl;
    displayUpdatedValues_usingLambdaFunc(int_array);

    // Another algo std::bind
    auto greaterthan_n = std::bind(greaterThan, _1, 50);
    std::cout << "\nAll greater than 50 ? Ans : " << std::boolalpha << std::all_of(int_array.begin(), int_array.end(), [&](int n) {
        return greaterthan_n(n);
        });


    //check if any array item is greater than 65
    auto res = std::any_of(int_array.cbegin(), int_array.cend(), [](int n) { return n > 65;
        });
    std::cout << "\nAny greater than 65 ? Ans : " << std::boolalpha << res;

    auto cnt = count_if(int_array.cbegin(), int_array.cend(), [](int n) { return n > 50;});
    std::cout << "\nNumbers greater than 50 : " << cnt << endl;
    
    auto greaterthan_40 = std::bind(greaterThan, std::placeholders::_1, 40);
    cnt = count_if(int_array.cbegin(), int_array.cend(), greaterthan_40);
    std::cout << "\nNumbers greater than 40 : " << cnt << endl;

    cnt = 0;
    std::for_each(int_array.cbegin(), int_array.cend(), [&](int n) { if (n > 50) cnt++; });
    std::cout << "\nNumbers greater than 50 : " << cnt << endl;

    return 0;
}
