#include <iostream>
#include <thread>
#include <mutex>

using namespace std;
std::mutex mu;
    
void shared_print(std::string msg, int id) {
    //mu.lock();
    //cout << "\n" << msg << ",  iter : " << id;
    //mu.unlock();

    // this one is better
    std::lock_guard<std::mutex> lock(mu);
    cout << "\n" << msg << ",  iter : " << id;
}
void thread_fun(std::string msg) {
    for(int i = 0; i < 100; i++) {
        shared_print(msg, i);
        this_thread::sleep_for(std::chrono::milliseconds(50));
    }    
}

int main()
{
    std::string msg2thread = "Hello Thread";
    std::thread t1(thread_fun, move(msg2thread));
    for(int i = 0; i > -100; i--) {
        shared_print("Main Here", i);
        this_thread::sleep_for(std::chrono::milliseconds(50));
    }
    t1.join();
    
    return 0;
}