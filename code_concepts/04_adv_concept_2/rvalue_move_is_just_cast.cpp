#ifndef R_VALUE_DEMO_H
#define R_VALUE_DEMO_H
#include <iostream>
#include <utility>
#include <vector>
#include <sstream>
#include <memory>
//#include "LyClass.h"
using namespace std;

//Observation : one should alway overload fun(const T&) and fun(T&&), 
// if you do fun(T) it will ambiguous error
	

class LyClass
{
	public:
	std::string name_;
	LyClass(const char * str) {
		name_ = str;
	}
	void show()
	{
		cout << "\nname : " << name_.c_str();
	}

};

//void show(const LyClass& obj) {
//	obj.show();
//}
void show(LyClass&& obj) {
	obj.show();
}
void show(LyClass obj) {
	obj.show();
}
/*
LyClass&& returnCopy(LyClass lyObj) {
	LyClass cpObj = lyObj;
	LyClass cp = std::move(cpObj);
	return std::move(cp); //as moved object will point to memory that is bound to destroy(cp) 
						  // so will crash
						 // return type should 'LyClass' and shoud 'return cp' which will call move constructor
}
*/// keep in mind std::move does some kind of static casting only

LyClass returnCopy(LyClass lyObj) {
	LyClass cpObj = lyObj;
	LyClass cp = std::move(cpObj);
	return cp; //as moved object will point to memory that is bound to destroy(cp)
						  // so will crash
						 // return type should 'LyClass' and shoud 'return cp' which will call move constructor
}
// keep in mind std::move does some kind of static casting only
// so with similar reasons as lvalue referernce never return rvalue reference and try to access(LyClass&& returnCopy(LyClass lyObj))
// LyClass returnCopy(LyClass lyObj) -> in this case returning std::move(cp) or simply cp will have same effect
// Even if a func does not have rvalue param version, it wont give error if you pass func(std::move(valParam))

void showVecContent(std::vector<unique_ptr<LyClass> >&& lyVec) {
	for (auto& v : lyVec) {  //just auto v will not work as rvalue is being passed
		v->show();  
	}
	//Below code will also work
	// for (int i = 0; i < lyVec.size(); i++) {
	// 	lyVec[i]->show();
	// }
}
//void showVecContent(std::vector<LyClass>&& lyVec) {
//	for (auto v : lyVec) {
//		v.show();
//	}
//}

void showSmartPtrs(const std::shared_ptr<LyClass>& ptr) {
	ptr->show();
}
void showSmartPtrs(std::shared_ptr<LyClass>&& ptr) {
	ptr->show();
}
int main()
{
	{
		ostringstream o_str;
		o_str << "vecTest_";
		o_str << 0;
		ostringstream o_str1;
		o_str1 << "vecTest_";
		o_str1 << 1;

		LyClass * arr[2] = { new LyClass(o_str.str().c_str()) , new LyClass(o_str1.str().c_str()) };

		std::vector<unique_ptr<LyClass>> lyVec;
		lyVec.reserve(10);
		for (int i = 0; i < 2; i++) {
			lyVec.push_back(unique_ptr<LyClass>(arr[i]));
		}
		showVecContent(std::move(lyVec));
		//Below two lines prints strings stored in the vector ,but its not guaranteed
		lyVec[0]->show(); 
		lyVec[1]->show();
		
		//when we pass param as std::vector of pointers / values withs std::move(), after the call even I can acess pointers / values
		//even it works same if we take vector of shared/unique pointer

		cout << endl << "Param through smart pointers Demo" << endl;
		unique_ptr<LyClass> sp(arr[0]);
		showSmartPtrs(std::move(sp));
		
		return 0;
	}
	
	
	LyClass obj("test");
	show(obj);
	//show(std::move(obj));
	LyClass retObj = returnCopy(obj); 
	retObj.show();
	
	return 0;
}
#endif //R_VALUE_DEMO_H