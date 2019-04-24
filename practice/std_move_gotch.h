#pragma once
#include <iostream>
#include <vector>
#include "LyClass.h"
using namespace std;
using vecInt = std::vector<int>;
namespace Demo_rValuePassingBasicType{
	void printAgain(int & val) {
		cout << " agian lvalue : " << val;
	}
	void printAgain(int && val) {
		cout << " again rvalue : " << val;
	}

	void print(int & val) {
		cout << endl << " lvalue : " << val;
		//printAgain(val); // will call lvalue versoni
	}
	void print(int && val) {
		cout << endl << " rvalue : " << val;
		printAgain(std::move(val)); // will call r value verison of printAgain
		//printAgain(val); // will call lvalue version of printAgain
		cout << endl << "after move: rvalue : " << val; // will print coming value of 'val'

	}
	void runDemo()
	{
		int i = 10;
		int& j = i;
		print(i); // will call lvalue version of print
		print(j);// will call lvalue version of print
		print(i + 0); // to call rvalue version of print function
		print(i * 1); // to call rvalue version of print function
	}
}
namespace Demo_moveInStd
{
	void movVector() {
		vecInt vec{ 2,3,4,5,6,7 };
		auto mov_vec = std::move(vec); // it has moved 'vec' data to move

		cout << endl << "size of vec : " << vec.size(); // hence vec size would be zero
		cout << endl << "size of mov_vec : " << mov_vec.size();
	}
}

namespace Demo_rValueInGen
{
	void print(LyClass obj) {
		cout << obj;
	}

	void passObjInFunc()
	{
		LyClass lyObj("Sunil");
		print(lyObj);
	}
}



int main()
{
	//Demo_moveInStd::movVector();
	//Demo_rValuePassingBasicType::runDemo();
	Demo_rValueInGen::passObjInFunc();

	return 0;
}
