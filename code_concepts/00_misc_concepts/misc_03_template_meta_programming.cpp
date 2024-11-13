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

	template<int N>
	int get_factorial()
	{
		if (N == 0)
			return 1;
		else if (N == 1)
			return N;
		else
			return N * get_factorial<N - 1>();
	}

	void demo_factorial_using_meta_programming() {

		// somehow not working giving C1202 compilation issues on windows/vs2022
		cout << "Demo : Factorial 5 using Function : " << get_factorial<5>() << endl;
		//cout << "Demo : Factorial 5 using class 'int' member : " << Factorial<5>::value << endl;
	}

int main()
{
    cout << "Factorial using template meta programming \n";
    cout << "Factorial of 7 : " << Fact<7>::result;
    cout << endl;

    cout << "Factorial(enum version) of 7 : " << (int)Fact_EnmVer<7>::result::Value;
    cout << endl;

    return 0;
}
