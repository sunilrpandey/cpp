#include <iostream>

// Its compiler dependent, even depend on debug or release mode
// i.e undefined.
// C++ 17 suggests to do post increment first out of arguments but does define order
// ref : theCherno
void print(int a, int b) {
    std::cout  << a << "  " << b << "    " << a + b << std::endl;
}
int main()
{
    int i = 0;
    print(i++,i++);
    return 0;
}