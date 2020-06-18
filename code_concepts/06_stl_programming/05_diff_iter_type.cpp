#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
using namespace std;
int main()
{
    std::vector<int> vec1{1,2,3,4,5};
    std::vector<int> vec2{10,20,30,40,50};
    auto iter_2 = find(vec1.begin(), vec1.end(),2);
    if(iter_2 != vec1.end()){
        cout << "\nFound : " << *iter_2;
    }
    cout << "\nCreating insertion point in vec1(at before num: 2)";
    insert_iterator<vector<int> > insIter(vec1,iter_2);
    copy(vec2.begin(),vec2.end(),insIter);

    cout << "\nListing vec1 after inserting vec2" << endl;
    for(auto i : vec1)
        cout << i << "\t" ;

    cout << "\nData copied not moved, here are vec2 content" << endl;
    for(auto i : vec2)
        cout << i << "\t" ;

    cout << "\n back_inserter demo : from vec1 (20) to end" << endl;
    list<int> addToList;
    auto iter_20 = find(vec1.begin(), vec1.end(),20);
    copy(iter_20,vec1.end(),back_inserter(addToList));
    for(auto i : addToList)
        cout << i << "\t" ;

    cout << "\n front_inserter demo : from vec1 (4) to end" << endl;
    auto iter_4 = find(vec1.begin(), vec1.end(),4);
    copy(iter_4,vec1.end(),front_inserter(addToList));
    for(auto i : addToList)
        cout << i << "\t" ;


    

    

    cout << endl;
    return 0;
}