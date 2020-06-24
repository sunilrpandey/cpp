#ifndef CUSTOM_UNIQUE_PTR
#define CUSTOM_UNIQUE_PTR
#include <iostream>
using namespace std;
template<typename T>
class LyUniquePtr
{
private:
	T * ptr_;

public:
	LyUniquePtr(T* p) :ptr_(p){}
	~LyUniquePtr(){
		cout << endl << "deletign unique ptr obj ..";
		if(ptr_){
			cout << ".. with entries" << endl;
			ptr_->print();
			delete ptr_;
			ptr_ = nullptr;
		}
	}

	LyUniquePtr(const LyUniquePtr& rhs) = delete;
	LyUniquePtr& operator = (const LyUniquePtr& rhs) = delete;

	LyUniquePtr(LyUniquePtr&& rhs){
		if(ptr_){
			delete ptr_;
			ptr_ = nullptr;
		}
		ptr_ = rhs.ptr_;
		rhs.ptr_ = nullptr;
	}
	LyUniquePtr& operator = (LyUniquePtr&& rhs){
		if(this == &rhs){
			return *this;
		}

		if(ptr_){
			delete ptr_;
			ptr_ = nullptr;
		}
		ptr_ = rhs.ptr_;
		rhs.ptr_ = nullptr;

		return *this;
	}

	T* operator -> () {
		return ptr_;
	}
	T& operator * () {
		return *ptr_;
	}

};
#endif //CUSTOM_UNIQUE_PTR