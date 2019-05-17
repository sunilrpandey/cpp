#pragma once

template<typename T>
class SumUtil
{
	T num1, num2;
public:
	SumUtil()
	{
		num1 = 0;
		num2 = 0;
	}
	SumUtil(T n1, T n2) {
		num1 = n1;
		num2 = n2;
	}
	T operator ()(T n1, T n2);
};
#include "TmpIt_Impl.inl"
