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

void callSpecializeFunc()
{
    std::cout << std::endl << "calling from sum_class.cpp" << std::endl;
    SumElements<int> num{1,2,3,4,5};
    std::cout << "Sum : " <<  num.sum() << std::endl;

    //SumElements<int> num1{1,2,3,4,5};
    //std::cout << "Sum : " <<  num1.sum() << std::endl;


    SumElements<double> num2{1.1,2.1,3.1,4.1,5.1};
    std::cout << "Sum : " <<  num2.sum() << std::endl;
}

// if it is not being called in any function say callSpecializeFunc() one can write below if specialized function are being called in another tranlation unit

    //template class SumElements<int>;
    //template class SumElements<double>;
