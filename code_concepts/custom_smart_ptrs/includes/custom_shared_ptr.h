#ifndef CUSTOM_SHARED_PTR
#define CUSTOM_SHARED_PTR

#include "ref_count_mgr.h"

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
		
		refCountMgr_ = rhs.refCountMgr_;
		ptr_ = rhs.ptr_;
		rhs.ptr_ = nullptr;
		rhs.refCountMgr_ = nullptr;
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

#endif //CUSTOM_SHARED_PTR