#include "sum_class.h"

template <typename T>
SumElements<T>::SumElements(std::initializer_list<T> lst)
{
    for(auto i: lst){
        arr.push_back(i);
    }
}
template <typename T>
T SumElements<T>::sum(){
    T total = 0;
    for(auto i : arr){
        total += i;
    }
    return total;
} 
template class SumElements<int>;
template class SumElements<double>;