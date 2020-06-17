#include <iostream>
#include <memory>
#include <string>
using namespace std;
int counter = 1;
class Dog
{
    public:
    string name_;

    Dog(const string & str = ""):name_(str){
        name_.append(to_string(counter++));
        cout <<  "\nBirth : " << name_.c_str(); 
    }
    ~Dog(){
        cout << "\nDeath : " << name_.c_str(); 
    }

};
shared_ptr<Dog> getSharedPtr(const std::string& str, bool use_make_shared = true)
{
    if(use_make_shared)
        return make_shared<Dog>(str);
    
    shared_ptr<Dog> p(new Dog(str));
    return p;
}

int main()
{
    #define BASIC_FUNC_DEMO_WITH_INT 1
    #if  BASIC_FUNC_DEMO_WITH_INT
    //shared pointer assignments and ref count changes demo
    {
        std::shared_ptr<int> spi1(new int(15));
        cout << endl << spi1.use_count();

        std::shared_ptr<int> spi2 = spi1;
        std::shared_ptr<int> spi3 = spi2;
        cout << "\nmade 2 more instance, use count(should be 3) : " << spi3.use_count(); 

        std::shared_ptr<int> spi5(new int(30));
        std::shared_ptr<int> spi6 = spi5;
        cout << "\nmade 2 instance of int 30, use count(should be 2) : " << spi5.use_count(); 

        spi3 = spi5;
        cout << "\none ref of pre group will be decremented and ref of later group will be incremented, hence spi1(shd be 2) : " << spi1.use_count() \
        << " and spi6(should be 3) : " << spi6.use_count(); 
            
    cout << endl;
    }
    #endif //BASIC_FUNC_DEMO_WITH_INT

#define BASIC_FUNC_DEMO 0
#define CUSTOM_DELETER_DEMO 1
#if BASIC_FUNC_DEMO

    cout << "\n:: Shared ptr Demo ::";
    {
    cout << "\n----- Basic Functions ----------";

    shared_ptr<Dog> spd1(new Dog("Smarty"));
    cout << "\nUse count : " << spd1.use_count();
    
    shared_ptr<Dog> spd2 = spd1;
    cout << "\nUse count should be 2 and is : " << spd1.use_count() << " - " << spd2.use_count();

    auto spd3 = getSharedPtr("SmartyV2");
    Dog * dg = spd3.get();
    if(spd3){
        cout << "\nGet() gives access to raw pointer : " <<  spd3->name_;
    } else {
        cout << "\nGet() give up raw pointer : " <<  dg->name_;
    }

    cout << "\nusage count sp3 before assigning to spd4 : " << spd3.use_count();
    
    auto spd4(spd3);
    cout << "\n spd4 : use count : " << spd4.use_count();
    spd4.reset();
    cout << "\n after reset use count of spd3 :" << spd3.use_count() << " that of spd4 : " << spd4.use_count() ;
    
    cout << "\nname of spd3 before reset to Resetty : " << spd3->name_ << " and use count : " << spd3.use_count();
    spd3.reset(new Dog("Resetty"));
    cout << "\nname of spd3 after reset to Resetty : " << spd3->name_ << " and use count : " << spd3.use_count();
    
    spd4 = spd3;
    cout << "\nspd4, reassigned, use count of spd4 : " << spd4.use_count();
    spd3 = nullptr;
    cout << "\nneed to check if assigning spd3 to null changes use_count(which should be yes) : " << spd4.use_count();      
    
    }
    
#elif CUSTOM_DELETER_DEMO
    cout << endl << "Demo : Custom Deleter";
    //custom deleter for array object other wise it iwll not call [] delete
    {
        cout << "\nDeleting shared ptr for object array : ";
        shared_ptr<Dog> sp_arr(new Dog[3], [](Dog * p){ cout << "\nCustom Deleting..."; delete [] p;});
    }

    // what to do and not to do with shared pointer

    // dont use raw pointer to initialize shared pointer
    // in below code rp will be deleted twice 
        // int * rp = new int;
        // shared_ptr<int> outer_p(rp);{
        //     shared_ptr<int> inner_p(rp);
        // }
    
    // dont create shared_ptr from stack but from heap only.

#endif 

    return 0;
}
