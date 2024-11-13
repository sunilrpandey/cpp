#include <iostream>
#include <string>
using namespace std;

/*  
Only the following parameter lists are allowed on literal operators:

( const char* )	(1)	
( unsigned long long int )	(2)	
( long double )	(3)	
( char )	(4)	
( wchar_t )	(5)	
( char8_t )	(6)	(since C++20)
( char16_t )	(7)	
( char32_t )	(8)	
( const char*, std::size_t )	(9)	
( const wchar_t*, std::size_t )	(10)	
( const char8_t*, std::size_t )	(11)	(since C++20)
( const char16_t*, std::size_t )	(12)	
( const char32_t*, std::size_t )	(13)	

ref : https://en.cppreference.com/w/cpp/language/user_literal

In C++, string literals are represented as arrays of characters with a null character ('\0') at the end to mark the 
termination of the string. When a string literal is passed as an argument to a function or operator, 
it loses its array-like properties and gets decayed into a pointer to the first character.

To differentiate between string literals of different lengths, the size parameter is necessary when defining 
a user-defined literal for strings. It allows you to determine the size of the input string literal and 
create a std::string object with the appropriate length.
*/


std::string operator"" _male(const char* x, std::size_t size) {
    
    std::string custom_name = std::string("Mr") + x;
    return custom_name;
}

int operator"" _i(long double x) {
    return static_cast<int>(x);
}

long double operator"" _cm(long double x) {
    return x * 10;
}
unsigned long operator"" _kg(unsigned long long  x) {
    return x * 1000;
}

int main()
{
    int n = 3.14_i;
    cout << "\nfloat to int using user defined literals : " << n;
    std::string  name = "Alex"_male;
    long double height = 3.4_cm;
    cout << "\n height in mms : " << height;
    unsigned long wt = 12_kg;
    cout << "\n weight in GMs : " << wt;

    cout << endl;
    return 0;
}