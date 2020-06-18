#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
using namespace std::placeholders;
int diff(int x, int y) {
	return x - y;
}

bool devisible(int num, int fac) {
	if (!(num%fac)) {
		return true;
	}
	return false;
}
int divideBy(int num, int fac) {
	return num/fac;
}


int main()
{
	auto diff_func = std::bind(&diff, _1, _2);

	cout << endl << "8 - 2 = " <<  diff_func(8, 2);

	auto diff_func_rev = std::bind(&diff, _2, _1);
	cout << endl << "2 - 8 = " << diff_func_rev(8, 2);

	auto divisibleBy5 = std::bind(&devisible, _1, 5);

	std::function<bool(int)> divFun = divisibleBy5;
	cout << endl << "55 is divisible by 5 : "<< std::boolalpha << divFun(55) << endl;

	auto divide_110 = std::bind(&divideBy,  110, _1);
	std::function<int(int,int)> divFun11 = divideBy;
	decltype(divideBy) x;
	cout << "Type of divideBy : " << typeid(x).name() << endl ;
	cout << endl << "Divide 110 by 11 = " << divide_110(11); 

    
	int arr[5] = { 10,3,45,21,90 };
	cout << std::boolalpha << "\ntotal num divided by 5 : " << count_if(arr, arr + 5, divisibleBy5) << endl;

	return 0;
}