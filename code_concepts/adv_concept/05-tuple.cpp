#include <iostream>
#include <tuple>
using namespace std;

std::tuple<int, std::string , double> getDetail(int i) 
{
    return make_tuple(i,"Sunil",100.0);
}

int main()
{
    auto dtl = getDetail(3);
    cout << endl << "tuple demo" << endl;
    cout << get<2>(dtl) << "\t" << get<0>(dtl) << "\t" << get<1>(dtl);
    
    // get<> can take only const int value, no variable etc
    // for example get<x>(tuple_instance) will give error, except when x is const int x = 1
    // get<x> will also give compile error if x is out of range  

    int id;
    double sal;
    std::string name;
    tie(id,name,sal) = getDetail(5);
    cout << endl << id << "\t" << name << "\t" << sal;

    // available in cpp 17 only
    auto [id1, name1, sal1] = getDetail(10);
    cout << endl << id1 << "\t" << name1 << "\t" << sal1;

    return 0;
}