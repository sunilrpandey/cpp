#include <set>
#include <iostream>
using namespace std;
int main()
{
    std::set<int> setInt;
    setInt.insert(22);
    setInt.insert(132);
    setInt.insert(21);
    setInt.insert(2);

    for(const auto& i:setInt )
        cout << "\t" << i;

    auto[iter,result] = setInt.insert(12);

    if(result)
        cout << endl << "iter : " << *iter;
    else
        cout << endl << "12 already exist";
    
    std::pair<set<int>::iterator,bool> res = setInt.insert(12);

    if(res.second)
        cout << endl << "iter : " << *res.first;
    else
        cout << endl << "12 already inserted";
    
    return 0;
}
    