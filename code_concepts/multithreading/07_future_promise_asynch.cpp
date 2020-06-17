#include <iostream>
#include <thread>
#include <future>
using namespace std;

// what if you want thread to return some value, you can pass this value as ref, use mutex and condition
// variable to notify calling thread and use the value passed as ref. but its headache

//std::async to rescue which returns future object ,  may or may not create function 

// future/promise can not be copied only be moved just lik thread and unique_lock
// but shared future can be copied

int calculateFactorial(int n)
{
    cout << "\nCalled Thread id : " << std::this_thread::get_id() << endl;
    
    int res = 1;
    while(n > 0){
        res *= n;
        n--;
    }
    return res;
}

int calculateFactorialPassParamAsPromise(std::future<int>& fu)
{
    int n = fu.get();
    return calculateFactorial(n);
}
int calculateFactorialPassParamAsSharedFuture(std::shared_future<int> fu)
{
    int n = fu.get();
    return calculateFactorial(n);
}


int main()
{
    int fact;
    int num = 4; 
    cout << "\nMain Thread id : " << std::this_thread::get_id() << endl;
    //std::future<int> fu = std::async(std::launch::deferred,calculateFactorial,4); // wont create a thread
    //std::future<int> fu = std::async(std::launch::async,calculateFactorial,4); // will create a thred 
    std::future<int> fu = std::async(std::launch::async|std::launch::deferred,calculateFactorial,4); // depends/default
    fact = fu.get();

    cout << "Factorial Value of " << num << " : " << fact << endl;
    
    // use promise
    int num2 = 5;
    std::promise<int> p;
    std::future<int> futNum = p.get_future(); 
    std::future<int> retValue = std::async(calculateFactorialPassParamAsPromise,std::ref(futNum)); // depends
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    
    bool set_exception_check = false;
    if(set_exception_check)
        p.set_exception(std::make_exception_ptr(std::runtime_error("To err is human")));
    else 
        p.set_value(num2);
    fact = retValue.get();
    cout << "Factorial Value of " << num << " : " << fact << endl;

    //when to pass same value, pass as shared future 
    std::promise<int> p1;
    std::future<int> futNum1 = p1.get_future(); 
    
    std::shared_future<int> sf = futNum1.share();
    std::future<int> retValue1 = std::async(calculateFactorialPassParamAsSharedFuture,sf); // depends
    std::future<int> retValue2 = std::async(calculateFactorialPassParamAsSharedFuture,sf); // depends
    std::future<int> retValue3 = std::async(calculateFactorialPassParamAsSharedFuture,sf); // depends
    p1.set_value(6);
    int res3 = retValue3.get();
    int res1 = retValue1.get();
    int res2 = retValue2.get();
    
    cout << "Shared future results are : " << res1 << "\t"   << res2 << "\t" << res3 << "\n";

    return 0;    
}