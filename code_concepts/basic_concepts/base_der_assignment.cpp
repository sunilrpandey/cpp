#include <iostream>
#include <vector>
#include <deque>
using namespace std;

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
	B b1, b2;
	b2.j = 15;
	b1 = b2; //derived assignment

	cout << b1.i << endl << b1.j;

	A a1;
	a1 = b1; // base assigment

	cout << a1.i;

	// b1 = a1; error

	return 0;
}