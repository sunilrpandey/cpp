#include <iostream>
#include <vector>
#include <deque>
using namespace std;

void VectorTest()
{
#if 0
	vector<int> vecCol = { 2,3,4,1,9,6 };
	auto f = [&]() {for (auto i : vecCol) { cout << i << "\t"; }};
	f();
	cout << endl;
	int * p  = &vecCol[3];
	cout << p[0] << p[1] << p[2];
	
	vecCol.insert(vecCol.begin(), 5);
	cout << p[0] << p[1] << p[2];

#endif 

#if 0
	deque<int> vecCol = { 2,3,4,1,9,6 };
	auto f = [&]() {for (auto i : vecCol) { cout << i << "\t"; }};
	f();
	cout << endl;
	int * p = &vecCol[3];
	cout << p[0] << p[1] << p[2];

#endif 
return;
}
# if 0
class FinalClass;
class MakeFinal
{
private:
	MakeFinal() {
		cout << "MakeFinal constructor";
	}
	friend FinalClass;
};
class FinalClass : public virtual MakeFinal
{
public:
	FinalClass() {
		cout << endl << "Final class";
	}
};

class TestClass : public FinalClass
{
public:
	TestClass() { // Compile error as MakeFinal class is inaccessible
		cout << endl << "testclass ";

	}
};

void finalclassTest()
{

}


#endif

class A
{
public:
	int i;
	A() :i(5) {}
	A& operator = (const A& rhs) {

		cout << " overloading base assignment";
		if (this == &rhs)
			return *this;
		i = rhs.i * 2;

		return *this;
	}
};

class B : public A
{
public:
	int j;
	B():j(10) {}

	B& operator = (const B& rhs) {

		cout << " overloading Der assignment";
		if (this == &rhs)
			return *this;
		j = rhs.j * 3;

		return *this;
	}
};




int main()
{
	//VectorTest();


	int arr[] = { 12, 7, 9, 3, 18, 24 };
	cout << sizeof arr;

	B b1, b2;
	b2.j = 15;
	b1 = b2;

	cout << b1.i << endl << b1.j;

	return 0;
}