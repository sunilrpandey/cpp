#pragma once
#include <iostream>
#define log(msg) cout << endl << msg << endl
using namespace std;
namespace LyUtil
{
	int strLen(const char * str) {
		int len = 0;
		while (*str) {
			len++;
			str++;
		}
		return len;
	}
	void strCpy(char * dest, const char * src) {
		while (*src) {
			*dest = *src;
			dest++;
			src++;
		}
		*dest = '\0';
	}
}
