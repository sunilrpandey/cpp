#pragma once
#include <utility>
#include <memory>
#include "LyUtils.h"

namespace ns_common
{
 class A
{
	std::string name_;
public:
	A(const std::string& val) {
		name_ = val;
		std::string msg = name_ + " created.\n";
		log(msg.c_str());
	}
	~A() {
		std::string msg = name_ + " destroyed.\n";
		log(msg.c_str());
	}
	weak_ptr<A> friend_; // instead of 
	//shared_ptr<A> friend_; // instead of 
public:

	std::string name() { return name_; }
	void show() {
		cout << "my name : " << name().c_str();
	}
	void setFriend(shared_ptr<A> pA) {
		friend_ = pA;
	}
	void showFriend() {
		if (!friend_.expired())  // check if obj is still alive
			friend_.lock()->show(); // use lock to invoke shared_ptr
		else
			cout << name_.c_str() << " : my friend is expired!" << endl;
	}

};
};


