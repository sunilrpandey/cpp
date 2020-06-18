#include <iostream>
#include <thread>
#include <mutex>
#include <fstream>

using namespace std;
std::mutex mu;
#define ITERATION 10

class LogFile
{
	std::mutex mu;
	std::fstream f;

public:
	LogFile() {
		f.open("03_log.txt", std::ofstream::out | std::ofstream::app);
	}
	void shared_print(std::string msg, int id) {
		std::lock_guard<std::mutex> lock(mu);
		f << "\n" << msg.c_str() << ",  iter : " << id;
	}
	~LogFile() {
		f.close();
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