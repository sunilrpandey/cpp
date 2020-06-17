#include <iostream>
#include <tuple>
#include <map>

using namespace std;
std::tuple<int, std::string , double> getDetail(int i) 
{
    return make_tuple(i,"Sunil",100.0);
}
struct  st
{
    int id;
    std::string name;
    double salary;
    st(){
        id = 999;
        name = "struct";
        salary = 888.99;
    } 
};

//single -statement multiple variable declaration form pair/tuple/struct
int main()
{
    // available in cpp 17 only
    auto [id1, name1, sal1] = getDetail(10);
    cout << endl << id1 << "\t" << name1 << "\t" << sal1;

    cout << endl << "Demo : Data from struct";
    st st_inst;
    auto [stid, stname, stsal] = st_inst;
    cout << endl << stid << "\t" << stname << "\t" << stsal << endl;

    cout << endl << "Demo : data from map : " << endl;

    std::map<int,std::string> record;
    record[100] = "Sunil";
    record[200] = "Neetu";
    record[300] = "Charvi";
    for(auto[roll, name] : record) {
        cout << roll << ": " << name << endl;
    }

    auto [pos, success] = record.insert({300,"Parth"});
    cout << endl << pos->first << " : " << pos->second << "\t" << success;


    return 0;
}