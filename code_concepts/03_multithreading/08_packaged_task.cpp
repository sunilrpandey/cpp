#include <iostream>
#include <functional>
#include <future>
#include <thread>
#include <deque>
#include <mutex>
#include <condition_variable>

using namespace std;
int calculateFactorial(int n)
{
    int res = 1;
    while(n > 0){
        res *= n;
        n--;
    }
    return res;
}
std::deque<packaged_task<int()> > task_q;
std::mutex mu;
std::condition_variable cond;
void consumer() {
    packaged_task<int()> task;
    {
        unique_lock<std::mutex> locker(mu);
        cond.wait(locker,[](){return !task_q.empty();});
        task = move(task_q.front());
        task_q.pop_front();
    }
    task();
}
int main()
{
    /*
     std::packaged_task<int(int)> pktask(calculateFactorial);
     pktask(6);
    //or
    std::packaged_task<int()> pktask(std::bind(calculateFactorial,6));
    pktask();
    cout << "\nFactorial collected in Main() : " << pktask.get_future().get() << endl;
    
    */

   std::thread t1(consumer);
   std::packaged_task<int()> pt1(std::bind(calculateFactorial,6));
   // this is beauty, not required here, but to show that we can value here as well
   std::future<int> fu = pt1.get_future();
   {
        std::lock_guard<std::mutex> locker(mu);
        task_q.push_back(move(pt1));        
   }
   cond.notify_one();
    
    t1.join();
    cout << "\nFactorial of 6: " << fu.get();
    
    return 0;
}