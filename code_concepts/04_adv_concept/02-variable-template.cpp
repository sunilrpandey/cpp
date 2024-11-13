#include <iostream>
using namespace std;
template<typename T>
constexpr T maxValue = T(1000);

template<>
constexpr double maxValue<double> = 2000;

template<>
constexpr char maxValue<char> = 'z';

template<typename T>
T maxValue_Var = T(1000);


int main()
{
    maxValue_Var<float> = 3000; 

    cout << maxValue<int>;
    cout << maxValue<char>;
    cout << maxValue<double>;

    cout << endl;
    return 0;
}