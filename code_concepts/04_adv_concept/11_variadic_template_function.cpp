#include <iostream>
using namespace std;

void log()
{
    return;
}

template <typename T, typename... Args>
void log(T val, Args... args){
    cout << val << "\t";
    log(args...);
}

int main()
{
    log("variadic", 12, 3.444);
    return 0;   
}
