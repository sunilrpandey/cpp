#ifndef TEST_CLASS_H
#define TEST_CLASS_H

#include <iostream>
using namespace std;
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
#endif //TEST_CLASS_H