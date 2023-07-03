#include <iostream>
#include "custom_shared_ptr.h"
#include "test_class.h"
#include "custom_unique_ptr.h"

using namespace std;


#define LY_COPY_TEST 0
#define LY_ASSIGNMENT_TEST 0
#define LY_MOVEASSIGNMENT_TEST 1

LyUniquePtr<LyTestClass> createTest()
{
	return LyUniquePtr<LyTestClass>(new LyTestClass(4));
}

int main()
{
	LyUniquePtr<LyTestClass> upTest(new LyTestClass(2));
	upTest->print();
	

#if LY_COPY_TEST
	//copy from other object will not work(copy constructor will not work)
	LyUniquePtr<LyTestClass> upTestCopy = upTest;
#endif 


#if LY_ASSIGNMENT_TEST
	
	//Assignment operator will not work
	LyUniquePtr<LyTestClass> upTestAnother(new LyTestClass(3));
	upTest = upTestAnother;
#endif
	//Assignment operator will not work
	LyUniquePtr<LyTestClass> upTestAnother(new LyTestClass(3));
	upTest = std::move(upTestAnother);
	upTest->print();


	return 0;
}
