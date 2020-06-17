#include <iostream>
#include <mutex>
using namespace std;

class Math
{
    int num_1;
    int num_2;
    //std::mutex mu_; // will not work in case of mix
    std::recursive_mutex mu_rec_; // 
  public:
    Math(int i, int j):num_1(i),num_2(j){}
    int add() {
        //lock_guard<std::mutex> locker(mu_);
        lock_guard<std::recursive_mutex> locker(mu_rec_);
        int res = num_1 + num_2;
        return res;
    }
    int mult() {
        //lock_guard<std::mutex> locker(mu_);
        lock_guard<std::recursive_mutex> locker(mu_rec_);
        int res = num_1 * num_2;
        return res;
    }
    int mix(){
        //lock_guard<std::mutex> locker(mu_);
        lock_guard<std::recursive_mutex> locker(mu_rec_);
        int res1 = add();
        int res2 = mult();

        return res1 + res2;
    }
};

int main()
{
    Math * mathObj = new Math(3,4);
    cout << "\nAddition : " << mathObj->add();
    cout << "\nMultiplication : " << mathObj->mult();
    cout << "\nExpression : " << mathObj->mix();

    return 0;
}