#pragma once
#include <iostream>
#include "LyClass.h"
#define TAB "\t"

using namespace std;

void log()
{
	cout << endl << "Loggin done!" << endl;
	return;
}

template <typename T, typename... S>
void log(T first, S...args) {
	cout << first << TAB;
	log(args...);
}

int main()
{
	cout << "=== Variadic template Demo ===" << endl;
	LyClass obj(999, "Demo");
	log(2, 4.5, "charString",obj);
	return 0;
}
