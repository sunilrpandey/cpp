#pragma once
//#include "LyUtils.h"
#include <iostream>
#include <functional>
using namespace std;
using namespace std::placeholders;


int ly_add(int i, int j, int k) {
	return i - j - k;
}

int main()
{
	//std::function<int(int, int, int)> func = ly_add;
	//cout << func(2,3,100);
	//std::function<int(int,int)> funPow2 = std::bind(ly_add, placeholders::_1,2,100);
	auto funPow2 = std::bind(ly_add, 5);
	
	cout << funPow2(5);

	return 0;
}