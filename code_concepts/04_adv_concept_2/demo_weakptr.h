#pragma once
#include <utility>
#include <memory>
#include "LyUtils.h"
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
			cout << "my friend is expired!" << endl;
	}

};

int main()
{
	{
			shared_ptr<A> spA = make_shared<A>("objA");
			shared_ptr<A> spB = make_shared<A>("objB");
			spA->setFriend(spB);
			spB->setFriend(spA);
		
		//spA.reset(); // that is why weak_ptr is useful
		spB->showFriend(); // 
		int i = 0;
	}
	return 0;
}
