#include <iostream>
#include <vector>
#include <string>
#include <cstdarg>
#include <memory>
#include <array>
#include <list>
#include <iterator>
#include <algorithm>

void draw_banner(const std::string& demo_name){
    std::cout << "\n============================================" << std::endl;
    std::cout << "=====         Demo: " << demo_name << "       ======" << std::endl;
    std::cout << "============================================\n" << std::endl;    
}

namespace ns_loop
{

auto call_for_loop(auto col) {  // auto can be passed in c++14 only

    for(auto str:col){
        std::cout << str << "  ";
    }
    std::cout << std::endl;

    return;    
}
    
void demo()
{
    ::draw_banner("loop");

    using String = std::string;
    using VecString = std::vector<String>;
    VecString msg {"Hello", "C++", "World", "from", "VS Code", "and the C++ extension!"};

    call_for_loop(msg);

}
}
namespace ns_constexpr
{
constexpr int get_array_size()
{
    return 5 * 3;
}

void demo() 
{
    ::draw_banner("constexpr");

    constexpr int arr_size = get_array_size();
    int int_arr[arr_size];

    std::cout << "constexpr arr size works" << std::endl;
    
}
}
namespace ns_outofmemory
{
void out_of_memory()
{
    return;
    std::cout << "!!!Out of memory!!!";
    std::exit(1);
}

void demo(){
    return;

    ::draw_banner("outofmemory");
    std::set_new_handler(out_of_memory);
    while(1){
        int * p = new int[10000];     
    }

}

}
namespace ns_vararg
{
    int var_arg_sum(int num_count, ...){
        int sum = 0;
        va_list lst;
        va_start(lst, num_count);
        for(int i = 0; i < num_count; i++) {
            sum += va_arg(lst, int);
        }
        va_end(lst);
        return sum;
    }

    void demo(){
        ::draw_banner("variable arguments");
        int sum = var_arg_sum(4,20,30,40,50);
        std::cout << sum;
    }
}
namespace ns_ptrs
{
class Base
{
    int x, y, z;
public:
    Base():x(0),y(0),z(0){
        std::cout << "\nBase Constructor";
    }
    Base(int i , int j, int k):x(i),y(j),z(k){}

    virtual void print() {        
        std::cout << "\nx = " << x << "y = " << y << "z = " << z;
    }
    virtual void show() {        
        std::cout << "\nI am Base";
    }
    virtual ~Base() {
        std::cout << "\nbase destructor";
    } 
};

class Derived : public Base
{
    public:
    Derived():Base(){
        std::cout << "\nDerived Constructor";
    }
    Derived(int i , int j, int k){} // this will call base class default not the 3 arg constructor , should call : Base(i,j,k)

    virtual ~Derived() {
        std::cout << "\nDerived destructor";
    }
    virtual void show() {        
        std::cout << "\nI am Derived";
    }
};

void demo_uniqueptrs(){

    draw_banner("unique pointers");
    std::unique_ptr<Base> p(new Base);
    p->print();

    std::unique_ptr<Base> p1( new Derived());
    p1->show();

    std::cout << " I am here";
}
}
namespace ns_stream
{
    std::vector<int> vec{10,20,30,40};        
    std::ostream& operator << (std::ostream& rhs, std::vector<int> col){

        for(const auto& i:col) {
            rhs << i << "  " ;
        }
        return rhs;
    }
    
    void demo_copy_vec_to_console(){
        std::copy(vec.begin(), vec.end()
        , std::ostream_iterator<int>(std::cout,"x"));  //x is separator     
    }

    void demo_put_to_override(){
        std::cout << "values : " << vec << std::endl;
    }
    void demo() {
        ::draw_banner("demo: stream op with container ");                
        demo_put_to_override();   
        
        //it actually moves vector data to console not just copy.
        demo_copy_vec_to_console();

        //after this vector size becomes zero
        if(vec.size()){
            //shoud not come here
            std::for_each(vec.begin(), vec.end(),[](int num){
                std::cout << num/10;
            });
        }
        std::cout << "demo ends" << std::endl;
    }
    
    
}
int main()
{
    //ns_loop::demo();
    //ns_constexpr::demo();   
    //ns_outofmemory::demo(); 
    //ns_vararg::demo();
    //ns_ptrs::demo_uniqueptrs();
    ns_stream::demo();
}
