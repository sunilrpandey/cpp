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

int sum3(int a, int b, int c) 
{
	return a - b + c;
}

int main()
{
	// binding params to func arg using placeholders
	auto diff_func = std::bind(&diff, _1, _2);

	cout << endl << "8 - 2 = " <<  diff_func(8, 2);

	// you can change placeholder order, in below function first param in func call will be second argument of func
	// it means placeholders are nothing but position of arguments
	auto diff_func_rev = std::bind(&diff, _2, _1);
	cout << endl << "2 - 8 = " << diff_func_rev(8, 2);

	// Here first param is provided by caller
	auto divisibleBy5 = std::bind(&devisible, _1, 5);

	std::function<bool(int)> divFun = divisibleBy5;
	cout << endl << "55 is divisible by 5 : "<< std::boolalpha << divFun(55) << endl;

	// Here first param is bound and second param is to provided by caller
	auto divide_110 = std::bind(&divideBy,  110, _1);
	std::function<int(int,int)> divFun11 = divideBy;
	decltype(divideBy) x;
	cout << "Type of divideBy : " << typeid(x).name() << endl ;
	cout << endl << "Divide 110 by 11 = " << divide_110(11); 

    
	int arr[5] = { 10,3,45,21,90 };
	cout << std::boolalpha << "\ntotal num divided by 5 : " << count_if(arr, arr + 5, divisibleBy5) << endl;

	
	// a - b + c	== 200
	cout << "\nsum3 = " << sum3(100, 200, 300);
	
	// in below example 50  is bound as first argument, first param provided to sum2 will go as second param and 
	// second param as first argument 
	auto sum2 = std::bind(&sum3,50,_2,_1);
	// here a = 50 b = 300(_2), c = 200(_1)
	// 50 - 300 + 200 = -50
	cout << "\nsum2 = " << sum2(200,300);

	auto sum4 = std::bind(&sum3,_2,50,_1);
	cout << "\nsum4 = " << sum4(200,300);
	// here a = 300(_2) b = 50, c = 200(_1)
	// 300 - 50 + 200 = 450

	cout << endl;
	return 0;
}