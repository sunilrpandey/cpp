#include <iostream>
#include <mutex>
#include <thread>
using namespace std;

std::timed_mutex mu_tim_;

void work()
{
    while(1){

        std::chrono::milliseconds mills(100);
        if(mu_tim_.try_lock_for(mills)) {
            cout <<"\nThread id (locked with mutex): " << std::this_thread::get_id();
            std::this_thread::sleep_for(std::chrono::milliseconds(250));
            mu_tim_.unlock();
            std::this_thread::sleep_for(std::chrono::milliseconds(250));
        } else {
            cout <<"\nThread id (without mutex) : " << std::this_thread::get_id();
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    }
} 

int main()
{
    std::thread t1(work);
    std::thread t2(work);

    t1.join();
    t2.join();

    return 0;
}