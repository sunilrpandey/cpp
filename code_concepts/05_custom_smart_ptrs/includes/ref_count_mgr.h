#ifndef REF_COUNT_MGR_H
#define REF_COUNT_MGR_H
class RefCountMgr
{
	int ref_count_;

public:
	//constructor/destructor
	RefCountMgr() : ref_count_(0){}
	~RefCountMgr(){ ref_count_ = 0; }

	//copy constructor
	RefCountMgr(const RefCountMgr& rhs) {
		ref_count_ = rhs.ref_count_;
	}

	RefCountMgr& operator = (const RefCountMgr& rhs) {
		if (this == &rhs) {
			return *this;
		}
		ref_count_ = rhs.ref_count_;
	}
	int getRefCount(){ return ref_count_; }
	void increment(){ ref_count_++;}
	void decrement(){ ref_count_--;}
};
#endif //REF_COUNT_MGR_H