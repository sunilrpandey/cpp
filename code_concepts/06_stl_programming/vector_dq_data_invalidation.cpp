#include <iostream>
#include <vector>
#include <deque>
using namespace std;

void vectorDataInvalidationDemo()
{
	vector<int> vecCol = { 2,3,4,1,9,6 };
	auto f = [&]() {for (auto& i : vecCol) { cout << i << "\t"; }};
	f();
	cout << endl;
	int * p  = &vecCol[3];
	cout << p[0] << p[1] << p[2];
	
    cout << "\nInsert data at the begining and check values again, Unpredictable but generally pointer may not change" << endl;
	vecCol.insert(vecCol.begin(), 5);
	cout << p[0] << p[1] << p[2];

return;
}

void dequeDataInvalidationDemo()
{
    cout << endl << ": Deque Demo for data invalidation : " << endl;
	deque<int> vecCol = { 2,3,4,1,9,6 };
	auto f = [&]() {for (auto i : vecCol) { cout << i << "\t"; }};
	f();
	cout << endl;
	int * p = &vecCol[3];
	cout << p[0] << p[1] << p[2];

    cout << "\nInsert data at the begining and check values again, Unpredictable but generally pointer may not change" << endl;
	vecCol.insert(vecCol.begin(), 5);
	cout << p[0] << p[1] << p[2];

    return;
}

int main()
{
    vectorDataInvalidationDemo();
    dequeDataInvalidationDemo();
    return 0;
}