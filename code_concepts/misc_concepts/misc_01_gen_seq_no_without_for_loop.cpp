#include <iostream>
#include <vector>
using namespace std;

class LyClass
{
  public:
    static int class_obj_counter;
    static vector<int> nums; 
    
    LyClass() {
        nums.push_back(class_obj_counter);
        class_obj_counter++;
    }

};
int LyClass::class_obj_counter = 0;
vector<int> LyClass::nums;

int main()
{
    LyClass obj_array[10];
    cout << endl << "Print sequence of number generated withoug for loop\n ";
    for(auto n : LyClass::nums){
        cout << n << "\t";
    }
    cout << endl;

    return 0;
}