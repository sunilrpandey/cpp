#pragma once
#include "LyUtils.h"
#include <string>

using namespace std;
class LyClass
{
	static int objCounter_; //just to name each object differently
	char * name_ = nullptr; // from c++11 only 
	std::string regNo_;		// registeration number 
public:
	//constructor/destructor
	LyClass(char * str = nullptr){
		if (str) {
			LyUtil::strCpy(name_, str);
			objCounter_++;
			regNo_ = "temp";
		}
	}
	explicit LyClass(const char * name){
		objCounter_++;
		int len = LyUtil::strLen(name);
		name_ = new char[len+1];
		LyUtil::strCpy(name_, name);
		regNo_ = std::string("reg_") + to_string(objCounter_);
		
		string msg("constructor : ");
		msg.append("name : ").append(name_).append("regID : ").append(regNo_);
		log(msg.c_str());
	}
	~LyClass() {
		string msg("desstructor : ");
		msg.append("name : ").append(name_).append("regID : ").append(regNo_);
		log(msg.c_str());
		if (name_) { delete[] name_; name_ = nullptr; }
	}

	// copyconstructor
	LyClass(const LyClass& rhs) {
		objCounter_++;
		int len = LyUtil::strLen(rhs.name_);
		name_ = new char[len+1];
		LyUtil::strCpy(name_, rhs.name_);
		regNo_ = std::string("reg_") + to_string(objCounter_);
		string msg("copy constructor : ");
		msg.append("name : ").append(name_).append("regID : ").append(regNo_);
		log(msg.c_str());
	}
	// assignment operator
	LyClass& operator = (const LyClass& rhs) {
		if (&rhs == this) {
			return *this;
		}
		objCounter_++;
		int len = LyUtil::strLen(rhs.name_);
		delete[] name_;
		name_ = new char[len+1];
		LyUtil::strCpy(name_, rhs.name_);
		regNo_ = std::string("reg_") + to_string(objCounter_); 

		string msg("copy assignment : ");
		msg.append("name : ").append(name_).append("regID : ").append(regNo_);
		log(msg.c_str());
	}
	// moveconstructor
	LyClass(LyClass&& rhs) {
		//objCounter_ = rhs.objCounter_;
		name_ = rhs.name_;
		regNo_ = rhs.regNo_;
		rhs.name_ = nullptr;
		//rhs.regNo_ = "";
		string msg("move constructor : ");
		msg.append("name : ").append(name_).append("regID : ").append(regNo_);
		log(msg.c_str());
	}
	// move assignment operator
	LyClass& operator = (LyClass&& rhs) {
		if (&rhs == this) {
			return *this;
		}
		//objCounter_ = rhs.objCounter_;
		name_ = rhs.name_;
		regNo_ = rhs.regNo_;
		rhs.name_ = nullptr;
		//rhs.regNo_ = "";
		string msg("move assignment : ");
		msg.append("name : ").append(name_).append("regID : ").append(regNo_);
		log(msg.c_str());
	}
	//override steamout operator
	friend ostream& operator << (ostream& os, const LyClass& obj) {
		os << endl << "I am : name : " << obj.name_ << " regID : " << obj.regNo_;
		return os;
	}
	
public: 
	void show() const{
		cout << *this;
		return;
	}

};
int LyClass::objCounter_ = 1000;

