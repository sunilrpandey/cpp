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
    lines vecStrings{"Pyarooo", "Neetu", "Sunil"};

    #if 0 //Typical way to change till cpp 14 
        auto iter = find(begin(vecStrings),end(vecStrings),"Neetu");
        if(iter != vecStrings.end()) {
            *iter = "Neetu Pandey";
        }
    #endif

    // Now if is similar to for loop
    if(const auto& iter = find(begin(vecStrings),end(vecStrings),"Neetu"); iter != vecStrings.end()) {
        *iter = "Neetu Pandey";
    }
    // Now if is similar to for loop
    if(const auto& iter = find(begin(vecStrings),end(vecStrings),"Sunil"); iter != vecStrings.end()) {
        *iter = "Sunil Pandey";
    }
    for(auto const& str:vecStrings){
        cout << str << "\t";
    }

    
    cout << endl << "Demo: int constexpr(condition)";
    int n = 678;
    string s = "Sunil Pandey";

    cout << length(n) << endl << length(s);



    return 0;
}