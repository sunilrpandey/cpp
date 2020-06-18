#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void fun_display(int num)
{
	cout << num << "\t";
}

class OddCounter
{
  public:
	void update(const std::vector<int>& vec) {
		for_each(vec.begin(),vec.end(),[this](int num) {
			if( num % 2 ){
				counter_++;
			}
		});
	}

	int counter_ = 0;
};


int main()
{
	int arr[]{10,20,30,40,50};
	auto display = [](int num){ cout << num << "\t";};

	for_each(arr, arr+5, &fun_display);
	int devisor = 5;
	cout << endl << "Array element after dividing by 5 : " << endl;
	int numIter = 0;
	for_each(arr, arr+5, [=,&numIter](int num) mutable{ 
									num/= devisor;
									cout << num << "\t";
									devisor = 6; // you can not change it here as well if dont write you lambda function as mutable
												// even mutable will not change its value outside leambada if you dont pass this value as ref
									numIter++;
									}
									);
	
	cout << endl << "total elem in arr : " << numIter << endl;
	for_each(arr, arr+5, display);	
	cout << endl;

	cout << endl << "Access/update class memeber demo, by passing 'this' in [] in lambda function" << endl;
	std::vector<int> vecOdd{10,13,23,14,18};
	OddCounter oc;
	oc.update(vecOdd);
	cout << "Total odd numbers in vec : " << oc.counter_ << endl;

	return 0;

}



