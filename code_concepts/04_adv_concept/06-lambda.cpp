#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
/*
you can not change values inside lambda funciton it is not mutable
also mutable will not change its value outside lambada if you dont pass this value as ref
*/

void fun_display(int num)
{
	cout << num << "\t";
}

class OddCounter
{
  public:
	void update(const std::vector<int>& vec) {
		for_each(vec.begin(),vec.end(),[&](int num) {
			if( num % 2 ){
				counter_++;
			}
		});
	}

	int counter_ = 0;
};
class Storage
{
	std::vector<int> vec{10,20,30,40,50};
	int count;		
	public:
	Storage():count(0){}
	int get4divisibleNumbersCount(){
		for_each(vec.begin(), vec.end(), [&](int n){ 
								if(n%4 == 0) 
									count++; 
								});

		return count;
	}

};

void demoDisplayContentUsingLambda()
{
	int arr[]{10,20,30,40,50};
	//pass function to std algo
	cout << endl ; for_each(arr, arr+5, &fun_display); //pass function to algo

	//Display numbers in the array using lambda
	auto display = [](int num){ cout << num << "\t";};
	cout << endl ; for_each(arr, arr+5, display);	
	cout << endl;
	
	//-------------Count numbers divided by 4 in above array
	int devdBy4Counter = 0;
	for_each(arr, arr+5, [&](int n){ 
								if(n%4 == 0) devdBy4Counter++; 
								});
	cout << "\n total numbers divided by 4 : " << devdBy4Counter << endl; 
	// -----------------------------------------
	Storage storage;
	cout << "\n total numbers divided by 4 (using class storage): " << storage.get4divisibleNumbersCount();

}

void mutableLambdaDemo()
{
	int arr[]{10,20,30,40,50};
	
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
}


int main()
{
	//demoDisplayContentUsingLambda();
	//mutableLambdaDemo();								
	
	cout << endl << "Access/update class memeber demo, by passing 'this'/& in [] in lambda function" << endl;
	std::vector<int> vecOdd{10,13,23,15,18};
	OddCounter oc;
	oc.update(vecOdd);
	cout << "Total odd numbers in vec : " << oc.counter_ << endl;

	return 0;

}



