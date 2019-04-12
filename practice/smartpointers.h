#pragma once
#include "lyclass.h"
#include <utility>
int main()
{
	cout << " ===== Unique Pointer Demo =======" << endl;
	unique_ptr<LyClass> up(new LyClass("Unique Class Demo"));
	up->show();
	unique_ptr<LyClass> up1 = std::move(up);
	up1->show();
	if (up == nullptr) {
		log("up is null");
	}
	LyClass * pClass = up1.release();
	LyClass * pObj = up1.get();
	if (up1 == nullptr) {
		log("up1 is null after class object is released");
	}
	pClass->show();

	unique_ptr<LyClass> up2 = make_unique<LyClass>("For Make Unique");
	up2->show();
	//up2.reset();
	//pObj = up1.get();
	
	shared_ptr<LyClass> sp = std::move(up2);

	cout << sp.unique() << "count : " << sp.use_count() << endl;
	shared_ptr<LyClass> sp2 = sp;
	cout << sp.unique() << "count : " << sp.use_count() << endl;
	cout << sp2.unique() << "count : " << sp2.use_count();

	return 0;
}
