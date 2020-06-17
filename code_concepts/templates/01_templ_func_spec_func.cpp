#include <iostream>
using namespace std;

namespace ly {
template<class T>
T max(T x, T y) {
	if (x > y)
		return x;
	return y;
}

template<>
double max<double>(double x, double y) {
	cout << "\nInfo : Specialized fun for double\n";
	if (x > y)
		return x;
	return y;
}

template<>
char  max<char>(char x, char y) {

	cout << "\nInfo : Specialized fun for char\n";
	if (x > y)
		return x;
	return y;
}
};

int main()
{
	cout << ly::max(4, 9);
	cout << ly::max(3.4, 2.5);
	cout << ly::max('a', 'b');
return 0;
}