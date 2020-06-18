#include <iostream>
#include <thread>
#include <mutex>
#include <fstream>

using namespace std;
std::mutex mu;
#define ITERATION 10
// 1. heavy
// 2. unique lock can be moved 
// 3. for one time file opening lock/unlock to check file open will be expensive so use call_once
// 4. avoid locking mutex and calling user function 

#define OPEN_FILE_USING_MUTEX 0
#define OPEN_FILE_USING_MUTEX 0
class LogFile
{
	std::mutex mu_;
	std::fstream f_;
	#if OPEN_FILE_USING_MUTEX
		std::mutex mu_open_;
	#else 
	std::once_flag flag_;	
	#endif

public:
	LogFile() {
	}
	void shared_print(std::string msg, int id) {
		{
			#if OPEN_FILE_USING_MUTEX	
			std::unique_lock<std::mutex> locker(mu_open_);			
			if(!f_.is_open()){
				//std::unique_lock<std::mutex> locker(mu_open_); // its not thread safe here
				f_.open("03_log.txt", std::ofstream::out | std::ofstream::app);
			}
			#else 
			std::call_once(flag_,[&](){f_.open("03_log.txt");});
			#endif 

		}
		std::unique_lock<std::mutex> u_locker(mu_,std::defer_lock);
		//do somethin
		//...
		u_locker.lock();
		f_ << "\n" << msg.c_str() << ",  iter : " << id;
		u_locker.unlock();
		//do somethin
		//...
		//std::unique_lock<std::mutex> lock2(move(lock));
		

		
	}
	
	~LogFile() {
		f_.close();
	}
};

void thread_fun(std::string msg, LogFile& lf) {
	for (int i = 0; i < ITERATION; i++) {
		lf.shared_print(msg, i);
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