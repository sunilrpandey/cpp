#include<iostream>
#include <assert.h>
using namespace std;

// class definition
// members with basic data types
// copy constructor // shallow copy/deep copy
// assignment operator // self assignment , return by ref or value

// overload basic arithmetic operators + - ==

// move constructor
// move assignment operator

class Rectangle {
    int width = 2;
    int height = 3;

    int area_ = -1; // invalid number
public:

    Rectangle(int w, int h) {
        cout <<  "parametrized constructor";
        width = w; height = h;
    }

    Rectangle(std::initializer_list<int> list) {
        assert(list.size() >=2);
        cout <<  "constructor with initializer list";
        auto elm = list.begin();
        width = *elm; 
        elm++;
        height = *elm;
    }


    int area() {
        return width * height;
    }

    void showInfo(){
        std::cout << "widht = " << width << "ht = " << height << "area = " << area_;
    }
};

int main(){

Rectangle obj1{1, 2}; // calls constructor with initializer list
cout << obj1.area() << endl;
obj1.showInfo();
//Rectangle obj2{4}; // calls parametrized constructor
//cout << obj2.area() << endl;

}
