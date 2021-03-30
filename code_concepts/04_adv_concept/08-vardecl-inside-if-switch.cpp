#include <iostream>
#include <vector>
#include <algorithm>
#include <type_traits>

using namespace std;

//if constexpr(condition)
// used for template mainly, only section under condition will be compiled

template<typename T>
auto length(T const& value){
    if constexpr (is_integral<T>::value) {
        return value;
    } else {
        return value.length();
    }
}

int main()
{
    //use of using
    using line = std::string;
    using lines = std::vector<line>;
    lines vecStrings{"abc", "def", "ghi"};

    #if 0 //Typical way to change till cpp 14 
        auto iter = find(begin(vecStrings),end(vecStrings),"abc");
        if(iter != vecStrings.end()) {
            *iter = "ABC";
        }
    #endif

    // Now if is similar to for loop
    if(const auto& iter = find(begin(vecStrings),end(vecStrings),"abc"); iter != vecStrings.end()) {
        *iter = "ABC DEF";
    }
    // Now if is similar to for loop
    if(const auto& iter = find(begin(vecStrings),end(vecStrings),"def"); iter != vecStrings.end()) {
        *iter = "GHI JKL";
    }
    for(auto const& str:vecStrings){
        cout << str << "\t";
    }

    
    cout << endl << "Demo: int constexpr(condition)";
    int n = 678;
    string s = "abc def";

    cout << length(n) << endl << length(s);



    return 0;
}