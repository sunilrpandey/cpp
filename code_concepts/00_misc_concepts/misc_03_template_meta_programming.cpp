#include <iostream>
using namespace std;
template <int N>
struct Fact{
    static int const result = N * Fact<N-1>::result;
};
template <>
struct Fact<1> {
    static int const result =  1;
};

template<int N>
struct Fact_EnmVer
{
    enum class result{Value = N * (int)Fact_EnmVer<N-1>::result::Value};
};
template<>
struct Fact_EnmVer<1>
{
    enum class result{Value = 1};

};


int main()
{
    cout << "Factorial using template meta programming \n";
    cout << "Factorial of 7 : " << Fact<7>::result;
    cout << endl;

    cout << "Factorial(enum version) of 7 : " << (int)Fact_EnmVer<7>::result::Value;
    cout << endl;

    return 0;
}
