#include <cstdarg>
#include <iostream>
#include <vector>
using namespace std;

int varArgFunCumulativeSum(int num_element, ...){
    va_list arg_list;
    int cum_sum = 0;
    va_start(arg_list, num_element);
    for(int i = 0; i < num_element; i++) {
        cum_sum += va_arg(arg_list,int);
    }
    va_end(arg_list);
    return cum_sum;
}

int main()
{
    cout << "Cumulative Sum from 1 to 5 : " << varArgFunCumulativeSum(5,1,2,3,4,5) << endl;
    return 0;
}