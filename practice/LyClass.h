#pragma once
#include "LyUtils.h"
#include <string>

using namespace std;
class LyClass
{
	static int id_;
	char * name_ = nullptr;
	std::string title_;
public:
	//constructor/destructor
	LyClass() :name_(nullptr) {
		id_++; title_ = "temp";
	}
	explicit LyClass(const char * name){
		log("calling constructor!!");
		id_++;
		int len = LyUtil::strLen(name);
		name_ = new char[len+1];
		LyUtil::strCpy(name_, name);
		title_ = std::string("cls_") + to_string(id_);
	}
	~LyClass() {
		string msg("calling desstructor for : ");
		msg.append(title_);
		
		log(msg.c_str());
		id_--;
		if (name_) { delete[] name_; name_ = nullptr; }
	}

	// copyconstructor
	LyClass(const LyClass& rhs) {
		log("calling copy constructor!!");
		id_++;
		int len = LyUtil::strLen(rhs.name_);
		name_ = new char[len+1];
		LyUtil::strCpy(name_, rhs.name_);
		title_ = rhs.title_;

	}
	// assignment operator
	LyClass& operator = (const LyClass& rhs) {
		log("calling copy assignment!!");
		if (&rhs == this) {
			return *this;
		}
		id_++;
		int len = LyUtil::strLen(rhs.name_);
		delete[] name_;
		name_ = new char[len+1];
		LyUtil::strCpy(name_, rhs.name_);
		title_ = rhs.title_;
	}
	// moveconstructor
	LyClass(LyClass&& rhs) {
		log("calling move constructor!!");
		//id_ = rhs.id_;
		name_ = rhs.name_;
		title_ = rhs.title_;
		rhs.name_ = nullptr;
		//rhs.title_ = "";
	}
	// move assignment operator
	LyClass& operator = (LyClass&& rhs) {
		log("calling move assignment!!");
		if (&rhs == this) {
			return *this;
		}
		//id_ = rhs.id_;
		name_ = rhs.name_;
		title_ = rhs.title_;
		rhs.name_ = nullptr;
		//rhs.title_ = "";
	}
	//override steamout operator
	friend ostream& operator << (ostream& os, const LyClass& obj) {
		os << obj.id_ << "-" << obj.name_;
		return os;
	}
	
public: 
	void show() {
		cout << "obj_id : " << id_ <<"  name : " << name_ << " title : " << title_ << endl;
		return;
	}

};
int LyClass::id_ = 1001;

