#include <iostream>
#include <deque>
#include <mutex>
#include <thread>
#include <condition_variable>
using namespace std;

std::deque<int> q;
std::mutex mu;
std::condition_variable cond; 
void producer()
{
    int count = 0;
    while(count < 10) {
        std::unique_lock<std::mutex> locker(mu);        
        q.push_back(count);
        locker.unlock();
        cond.notify_one();
        std::this_thread::sleep_for(std::chrono::seconds(1));
        count++;
    }
    return;
}
void consumer()
{
    int count = 0;
    while(count < 9) {
        std::unique_lock<std::mutex> locker(mu);
        cond.wait(locker,[](){return !q.empty();}); // may get spurious call to get up, here thread go to sleep if mu is locked and wait 
                            // for producer to notify once mutex is unlocked
        count = q.back();
        q.pop_back();
        locker.unlock();
        cout << "Got it from Producer... : " <<  count << endl;        
    }
}


int main()
{
    std::thread prod(producer);
    std::thread cons(consumer);
    prod.join();
    cons.join();

    cout << endl << "Consumer-Producer Done" << endl;
    return 0;
}