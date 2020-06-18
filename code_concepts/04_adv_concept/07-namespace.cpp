// namespace demo
// Now you need not to write inner namespace inside outer space, even outside you can do using namespace outer::inner
#include <iostream>

using namespace std;

namespace outer
{
    void outerFun(){ cout << "Hello from outer namespace" << endl;}
}
namespace outer::inner
{
    void innerFun(){ cout << "Hello from inner namespace" << endl;}
}

int main()
{
    outer::inner::innerFun();
    return 0;
}