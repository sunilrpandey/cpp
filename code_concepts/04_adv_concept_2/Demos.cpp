//#include "VariadicTemplate.h"
//#include "smartpointers.h"
#include "demo_weakptr.h"
//#include "misc_funcs.h"
//#include "std_move_gotch.h"

// when you pass a shared pointer by value it gets copied and get removed in the function
// if by ref then as expected no copy would be created
// if func has only && version and passing  by shared ptr it will treat as ref
// you can not pass unique ptr by value as it does not have copy constructor


namespace ns_common{
void print(){}

template<typename T, typename... Params>
void print(T val, Params... args) {
    std::cout << val << "  ";
    print(args...);
    return;
}
};

void demo_print_using_variadic_argument(){
    ns_common:: print(2,3,5,7,4.6);
}

int demo_weakptrs()
{
    {
        shared_ptr<ns_common::A> spA = make_shared<ns_common::A>("objA");
        shared_ptr<ns_common::A> spB = make_shared<ns_common::A>("objB");
        
        spA->setFriend(spB);
        spB->setFriend(spA);

    
		//spA.reset(); // that is why weak_ptr is useful
		spB->showFriend(); // 
		int i = 0;
	}
	return 0;
}

template<typename T>
void pass_smartptr_to_func(T& val)
{
    cout << val->name();

}
template<>
void pass_smartptr_to_func<std::shared_ptr<ns_common::A>>(std::shared_ptr<ns_common::A>& val)
{
    cout << val.use_count() << endl;
    cout << val->name();

}
void demo_pass_smartptrs_to_func(){
    shared_ptr<ns_common::A> spA = make_shared<ns_common::A>("objA");
    cout << spA.use_count();
    pass_smartptr_to_func(spA);
    cout << spA.use_count();

    unique_ptr<ns_common::A> upA = make_unique<ns_common::A>("unqA");
    pass_smartptr_to_func(upA);

}


int main()
{
    demo_print_using_variadic_argument();
    demo_weakptrs();
    demo_pass_smartptrs_to_func();
    return 0;
}