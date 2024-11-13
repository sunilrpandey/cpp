#include <iostream>
#include <vector>
using namespace std;

class LyClass
{
  public:
    static int class_obj_counter;
    static vector<int> nums; 
    
    LyClass() {
        cout << class_obj_counter << "\t";
        nums.push_back(class_obj_counter);
        class_obj_counter++;
    }

};
int LyClass::class_obj_counter = 0;
vector<int> LyClass::nums;

int main()
{
    cout << endl << "Print sequence of number generated withoug for loop\n ";
    cout << endl << "Idea is to print counter when an object is created for array objects\n ";
    LyClass obj_array[10];
    #if 0
    for(auto n : LyClass::nums){
        cout << n << "\t";
    }
    cout << endl;
    #endif 

    return 0;
}