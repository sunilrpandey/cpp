#pragma once
#include "LyUtils.h"
#include <string>

using namespace std;
class LyClass
{
	static int objCounter_;
	char * name_ = nullptr;
	std::string regNo_;
public:
	//constructor/destructor
	LyClass() :name_(nullptr) {
		objCounter_++; 
		regNo_ = "temp";
	}
	explicit LyClass(const char * name){
		log("calling constructor!!");
		objCounter_++;
		int len = LyUtil::strLen(name);
		name_ = new char[len+1];
		LyUtil::strCpy(name_, name);
		regNo_ = std::string("reg_") + to_string(objCounter_);
	}
	~LyClass() {
		string msg("calling desstructor for : ");
		msg.append(regNo_);
		
		log(msg.c_str());
		objCounter_--;
		if (name_) { delete[] name_; name_ = nullptr; }
	}

	// copyconstructor
	LyClass(const LyClass& rhs) {
		log("calling copy constructor!!");
		objCounter_++;
		int len = LyUtil::strLen(rhs.name_);
		name_ = new char[len+1];
		LyUtil::strCpy(name_, rhs.name_);
		regNo_ = rhs.regNo_;

	}
	// assignment operator
	LyClass& operator = (const LyClass& rhs) {
		log("calling copy assignment!!");
		if (&rhs == this) {
			return *this;
		}
		objCounter_++;
		int len = LyUtil::strLen(rhs.name_);
		delete[] name_;
		name_ = new char[len+1];
		LyUtil::strCpy(name_, rhs.name_);
		regNo_ = rhs.regNo_;
	}
	// moveconstructor
	LyClass(LyClass&& rhs) {
		log("calling move constructor!!");
		//objCounter_ = rhs.objCounter_;
		name_ = rhs.name_;
		regNo_ = rhs.regNo_;
		rhs.name_ = nullptr;
		//rhs.regNo_ = "";
	}
	// move assignment operator
	LyClass& operator = (LyClass&& rhs) {
		log("calling move assignment!!");
		if (&rhs == this) {
			return *this;
		}
		//objCounter_ = rhs.objCounter_;
		name_ = rhs.name_;
		regNo_ = rhs.regNo_;
		rhs.name_ = nullptr;
		//rhs.regNo_ = "";
	}
	//override steamout operator
	friend ostream& operator << (ostream& os, const LyClass& obj) {
		os << endl << "I am : name : " << obj.name_ << " regID : " << obj.regNo_;
		return os;
	}
	
public: 
	void show() {
		cout << *this;
		return;
	}

};
int LyClass::objCounter_ = 1000;

