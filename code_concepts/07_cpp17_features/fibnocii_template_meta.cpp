#include <iostream>
using namespace std;

/* Learning
The real value of constexpr is as a guarantee that the function will be computable at compile-time.
Unlike templates and preprocessor macros, constexpr allows for loops and recursion at compile-time without extreme boilerplate.
*/


template<int n>
struct fibonacii{
    static const int value = fibonacii<n-1>::value + fibonacii<n-2>::value;    
};
template<>
struct fibonacii<0> {
    static const int value = 0;
};

template<>
struct fibonacii<1> {
    static const int value = 1;
};

constexpr int fibonaccii_constfun_cpp11(const int& x) {
    if(x <= 1 ) {
        return x;
    } else {
        return fibonaccii_constfun_cpp11(x-1) + fibonaccii_constfun_cpp11(x-2);
    }
}

int main()
{
    cout << "using meta programming fib<7> : " <<  fibonacii<7>::value << endl;
    cout << "using constexpr fib<7> : " << fibonaccii_constfun_cpp11(7) << endl;

// why this is working ?? 
    int x = 12;
    cout << fibonaccii_constfun_cpp11(x);
    return 0;
}