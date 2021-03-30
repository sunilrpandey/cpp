#include "sum_class.h"
//extern template class SumElements<int>;
//extern template class SumElements<double>;
int main(){
    SumElements<int> num{1,2,3,4,5};
    std::cout << "Sum : " <<  num.sum() << std::endl; 
    
    //SumElements<int> num1{1,2,3,4,5};
    //std::cout << "Sum : " <<  num1.sum() << std::endl; 
    

    SumElements<double> num2{1.1,2.1,3.1,4.1,5.1};
    std::cout << "Sum : " <<  num2.sum() << std::endl; 
    
    //std::cout << "Nothing done";
    return 0;
}