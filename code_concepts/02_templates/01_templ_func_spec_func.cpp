#include <iostream>
using namespace std;

/*
Learning
Can delete any specialized template function/class (#define DELETE_DOUBLE_SPECIALIZE_TEMP_FUNCTION 0
)
*/

#define DELETE_CHAR_SPECIALIZE_TEMP_FUNCTION 1

namespace ns_templ 
{

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

#if DELETE_CHAR_SPECIALIZE_TEMP_FUNCTION 
template<>
char  max<char>(char x, char y) = delete; 
#else 
template<>
char  max<char>(char x, char y) {

	cout << "\nInfo : Specialized fun for char\n";
	if (x > y)
		return x;
	return y;
}
#endif

void demo_delete_specilized_impl(){

	cout << max(4, 9);
	cout << max(3.4, 2.5);
	//cout << max('a', 'b'); // this line will givedemo_delete_specilized_impl
};
}

int main()
{
	ns_templ::demo_delete_specilized_impl();
	return 0;
}
