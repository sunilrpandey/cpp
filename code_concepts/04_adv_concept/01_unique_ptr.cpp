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
        cout <<  "\nBirth : " << name_.c_str() << std::endl;
    }
    Dog(const initializer_list<string>& vec_str){
        name_ = *(vec_str.begin());
        Dog(name_);
        //name_.append(to_string(counter++));
        //cout << "init_list Birth : " << name_.c_str() << endl;
    }
    ~Dog(){
        cout << "\nDeath : " << name_.c_str() << std::endl;
    }
    void bark(){
        cout << "I am " << name_.c_str() << endl;
    }
};
unique_ptr<Dog> getPtr(const std::string& dname, bool make_unique_flag = true)
{
    if(make_unique_flag){
        return make_unique<Dog>(dname);
    }

    unique_ptr<Dog> p(new Dog(dname));
    //p->bark();
    return p;
}
int main()
{
    auto uip = std::unique_ptr<int> (new int);
    *uip = 12;
    std::cout << "instantiated using basic method :" << *uip << std::endl;

    auto uip1 = std::make_unique<int>(15);
    std::cout << "instantiated using make_unique method :" << std::endl;

    std::unique_ptr<Dog> uidg = std::unique_ptr<Dog>(new Dog("Tommy"));
    uidg->bark();

    auto uidg1 = std::unique_ptr<Dog>(new Dog("Tommy_unique"));
    uidg1->bark();

    uidg1.get()->bark();

    //assign new pointer using = or reset
    uidg.reset(uidg1.get());




    return 0;




    // you can use new operator or make_unique to initialize
    bool use_make_unique = false;
    unique_ptr<Dog> p = getPtr("Smoky", use_make_unique);
    cout << endl << "p : " << p->name_;

    // assignments or copying transfers ownership
    unique_ptr<Dog> p2 = move(p);
    cout << endl << "p2  : " << p2->name_;
    if(!p){
        cout  << endl << "no more p" << endl;
    }

    unique_ptr<Dog> emptyPtr = nullptr;
    emptyPtr = move(p2);
    cout << "\nEmptyPtr got something : " << emptyPtr->name_;

    //reset deletes the resource underneath
    cout << endl << "See how NewDog replaces old one";
    emptyPtr.reset(new Dog("NewDog"));


    cout << "\n->->Demo : make unique <-<- ";
    auto dgPtr = make_unique<Dog>("Madebymakeunique");
    cout << "\n Name of this dog: " << dgPtr->name_ << endl;

    auto releasedFromDgPtr = dgPtr.release();
    cout << endl << "releasedFromDgPtr : " << releasedFromDgPtr->name_;

    delete releasedFromDgPtr;
    return 0;
}
