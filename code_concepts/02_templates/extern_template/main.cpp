#include "sum_class.h"
<<<<<<< HEAD
extern template class SumElements<int>;
extern template class SumElements<double>;
extern void callSpecializeFunc(); // need to declare it extern since header definition wont work
=======
// compile using 
// g++ -g  .\sum_class.cpp .\main.cpp

extern template class SumElements<int>;
extern template class SumElements<double>;
>>>>>>> ab4d1cd6b68696245ad1ad2ec398320a5787cc63
int main(){
    SumElements<int> num{1,2,3,4,5};
    std::cout << "Sum : " <<  num.sum() << std::endl;

    //SumElements<int> num1{1,2,3,4,5};
    //std::cout << "Sum : " <<  num1.sum() << std::endl;


    SumElements<double> num2{1.1,2.1,3.1,4.1,5.1};
    std::cout << "Sum : " <<  num2.sum() << std::endl;

    callSpecializeFunc();

    //std::cout << "Nothing done";
    return 0;
}


