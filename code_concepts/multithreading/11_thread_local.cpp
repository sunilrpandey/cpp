#include <iostream>
#include <mutex>
#include <string>
#include <thread>
using namespace std;

thread_local int th_lc_variable = 1;
std::mutex mut;

void print(const string& str) {
    th_lc_variable++;
    std::lock_guard<std::mutex> locker(mut);
    cout << endl << str.c_str()  << "  : "  << th_lc_variable;
}

int main()
{
    std::thread a(print, "Thread A"),b(print, "Thread B");
    {
        std::lock_guard<std::mutex> locker(mut);
        cout << endl << "main thread : " << "  : "  << th_lc_variable;
        th_lc_variable++;

    }
    a.join();
    b.join();
    cout << endl;
    return 0;
}