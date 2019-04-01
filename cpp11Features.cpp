#include <iostream>

using namespace std;

class RefCountMgr
{
	int refCount_;

public:
	//constructor/destructor
	RefCountMgr() :refCount_(0){}
	~RefCountMgr(){ refCount_ = 0; }

	//copy constructor
	RefCountMgr(const RefCountMgr& rhs) {
		refCount_ = rhs.refCount_;
	}

	RefCountMgr& operator = (const RefCountMgr& rhs) {
		if (this == &rhs) {
			return *this;
		}
		refCount_ = rhs.refCount_;
	}
	int getRefCount(){ return refCount_; }
	void increment(){ refCount_++;}
	void decrement(){ refCount_--;}
};

class LyTestClass
{
	int mult_;
	int * p_;
public:
	LyTestClass(int value) :mult_(value){
		p_ = new int[5];
		for(int i = 1; i <= 5; i++){
			p_[i - 1] = i * mult_;
		}
	}

	~LyTestClass(){
		if(p_){
			delete[] p_;
		}
	}
	void print(){
		for(int i = 0; i < 5; i++)
			cout << p_[i] << "\t";
		cout << std::endl;
		return;
	}

};

template<typename T>
class LySharedPtr
{
	RefCountMgr * refCountMgr_;
	T* ptr_;
public:
	//constructur/desctructyor
	LySharedPtr() :refCountMgr_(nullptr), ptr_(nullptr) {}
	LySharedPtr(T* ptr) :ptr_(ptr) {
		refCountMgr_ = new RefCountMgr();
		refCountMgr_->increment();
	}
	void cleanup()
	{
		refCountMgr_->decrement();
		if (refCountMgr_->getRefCount() == 0) {
			delete refCountMgr_;
			refCountMgr_ = nullptr;
			delete ptr_;
			ptr_ = nullptr;
		}
	}
	~LySharedPtr() {
		cleanup();
	}

	//copy constructor
	LySharedPtr(const LySharedPtr& rhs) {
		refCountMgr_ = rhs.refCountMgr_;
		refCountMgr_->increment();
		ptr_ = rhs.ptr_;
	}
	
	//assignment operator
	LySharedPtr& operator = (const LySharedPtr& rhs) {
		if (this == &rhs)
			return *this;

		if (refCountMgr_->getRefCount())
			cleanup();
		
		refCountMgr_ = rhs.refCountMgr_;
		refCountMgr_->increment();
		ptr_ = rhs.ptr_;

		return *this;
	}

	//move construtor
	LySharedPtr(LySharedPtr&& rhs) {
		if (this == &rhs)
			return *this;
		
		refCountMgr_ = rhs.refCountMgr_;
		ptr_ = rhs.ptr_;
		rhs.ptr_ = nullptr;
	}
	//move construtor
	LySharedPtr& operator = (LySharedPtr&& rhs) {
		if (this == &rhs)
			return *this;

		cleanup();
		refCountMgr_ = rhs.refCountMgr_;
		ptr_ = rhs.ptr_;
		rhs.ptr_ = nullptr;
	}
};



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

#define LY_COPY_TEST 0
#define LY_ASSIGNMENT_TEST 0

#define LY_MOVEASSIGNMENT_TEST 1



LyUniquePtr<LyTestClass> createTest()
{
	return LyUniquePtr<LyTestClass>(new LyTestClass(4));
}

int main()
{
	LyUniquePtr<LyTestClass> upTest(new LyTestClass(2));
	upTest->print();
	

#if LY_COPYTEST
	//copy from other object will not work(copy constructor will not work)
	LyUniquePtr<LyTestClass> upTestCopy = upTest;
#endif 


#if LY_ASSIGNMENT_TEST
	
	//Assignment operator will not work
	LyUniquePtr<LyTestClass> upTestAnother(new LyTestClass(3));
	upTest = upTestAnother;
#endif
	//Assignment operator will not work
	LyUniquePtr<LyTestClass> upTestAnother(new LyTestClass(3));
	upTest = std::move(upTestAnother);
	//LyUniquePtr<LyTestClass> p = createTest();
	upTest->print();


	return 0;
}
