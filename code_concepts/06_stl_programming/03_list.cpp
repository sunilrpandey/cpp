#include <list>
#include <iostream>

int main()
{
    //splice demo
    std::list<int> list1;
    for(int i = 0; i < 4; i++){
        list1.push_back(i+1);
    }
    
    std::list<int> list2;
    for(int i = 0; i < 4; i++){
        list2.push_back(i*10);
    }
    
    //splice moves content from one list to other.
    //list1.splice(list1.begin(),list2); //move whole list2 content at list1.begin

 //   auto first = std::advance(list2.begin(),1);
 //   auto last = list2.end() - 2;

    for(auto i:list1)
        std::cout << "\t" << i;
    std::cout << std::endl;
    return 0;
}