#include <iostream>
using namespace std;


template<class T>
T max(T x, T y) {
	if (x > y)
		return x;
	return y;
}
template<>
double max<double>(double x, double y) {

	cout << "called double specialized fun" << endl;
	if (x > y)
		return x;
	return y;
}

//template<>
//double max<double>(double x, double y) {
//	
//	cout << "called specialized fun";
//	if (x > y)
//		return x;
//	return y;
//}
template<>
char  max<char>(char x, char y) {

	cout << "called specialized char fun" << endl;
	if (x > y)
		return x;
	return y;
}

int main()
{
#if 0 // copy const issue
	D d1;
	D d2 = d1;
#endif 
	cout << max(4, 9);
	cout << max(3.4, 2.5);
	cout << max('a', 'b');
	
return 0;

}