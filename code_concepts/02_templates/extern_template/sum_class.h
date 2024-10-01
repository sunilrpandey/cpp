#include <iostream>
#include <vector>

template <typename T>
class SumElements
{
    public:
    SumElements(std::initializer_list<T> lst);
    T sum();
    private:
    std::vector<T> arr;

};

void callSpecializeFunc();
