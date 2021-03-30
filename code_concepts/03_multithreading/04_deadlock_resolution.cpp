#include <iostream>
#include <thread>
#include <mutex>
#include <fstream>

using namespace std;
std::mutex mu;
#define ITERATION 10


// 1. lock mutexes in same order
// 2. avoid locking mutex and calling user function 
// 3. use std::lock(mu1,mu2) and lock with adopt_lock, it manages order
// 4. 

using namespace std;
class LogFile
{
	std::mutex mu;
	std::mutex mu2;
	std::fstream f;

public:
	LogFile() {
		f.open("04_log.txt", std::ofstream::out | std::ofstream::app);
	}
	void shared_print(std::string msg, int id) {
		/* deadlock case 
		std::lock_guard<std::mutex> lock(mu);
		std::lock_guard<std::mutex> lock2(mu2);
		cout << "\n" << msg.c_str() << ",  iter : " << id;
		*/
		std::lock(mu,mu2);
		std::lock_guard<std::mutex> lock(mu,std::adopt_lock);
		std::lock_guard<std::mutex> lock2(mu2,std::adopt_lock);
		cout << "\n" << msg.c_str() << ",  iter : " << id;
		
	}
	void shared_print2(std::string msg, int id) { 
		/* deadlock case 
		std::lock_guard<std::mutex> lock2(mu2);
		std::lock_guard<std::mutex> lock(mu);
		cout << "\n" << msg.c_str() << ",  iter : " << id;
		*/
		std::lock_guard<std::mutex> lock2(mu2,std::adopt_lock);
		std::lock_guard<std::mutex> lock(mu,std::adopt_lock);
		cout << "\n" << msg.c_str() << ",  iter : " << id;
		
	}
	
	~LogFile() {
		f.close();
	}
};

void thread_fun(std::string msg, LogFile& lf) {
	for (int i = 0; i < ITERATION; i++) {
		lf.shared_print2(msg, i);
		this_thread::sleep_for(std::chrono::milliseconds(50));
	}
}

int main()
{
	std::string msg2thread = "Hello Thread";
	{
		LogFile lf;
		std::thread t1(thread_fun, move(msg2thread), std::ref(lf));
		for (int i = 0; i > -ITERATION; i--) {
			lf.shared_print("Main Here", i);
			this_thread::sleep_for(std::chrono::milliseconds(50));
		}
		if (t1.joinable()) {
			t1.join();
		}
	}
	return 0;
}