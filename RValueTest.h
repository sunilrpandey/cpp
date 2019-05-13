#pragma once
#include <iostream>
#include <utility>
#include <vector>
#include <sstream>
#include "LyClass.h"
using namespace std;
#pragma region "r/l value demo"
//void show(int i) {
//	cout << "int - " << i;
//}
void show(const int& i) {
	cout << endl << "const int ref - " << i;
}
#pragma endregion
void show(int && i) {
	cout << endl << "r value ref - " << i;
}

template <typename T>
void relay1(T&& val) {
	show(val);
}
template <typename T>
void relay2(T&& val) {
	show(std::forward<T>(val));
}

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

void showVecContent(std::vector<unique_ptr<LyClass>>&& lyVec) {
	//for (auto v : lyVec) {
	//	v->show();
	//}

	for (int i = 0; i < lyVec.size(); i++) {
		lyVec[i]->show();
	}
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
		lyVec[0]->show();
		lyVec[1]->show();

		//when we pass param as std::vector of pointers / values withs std::move(), after the call even I can acess pointers / values
		//even it works same if we take vector of shared/unique pointer

		cout << endl << "Param through smart pointers Demo" << endl;
		unique_ptr<LyClass> sp(arr[0]);
		showSmartPtrs(std::move(sp));
			   
		int i = 0;
	}
	int i = 0;

	/*
	auto i = 10;
	cout << "output : " << endl;
	//show(i);
	show(std::move(i));

	//std::forward use
	relay1(std::move(i));
	relay2(std::move(i));
	relay2(i);
	//cout << i;
	*/
	//Observation : one should alway overload fun(const T&) and fun(T&&), 
	// if you do fun(T) it will ambiguous error
	/*
	LyClass obj("test");
	show(obj);
	//show(std::move(obj));
	LyClass retObj = returnCopy(obj); 
	retObj.show();
	*/
	return 0;
}
