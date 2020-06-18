#include <iostream>
using namespace std;

// Dont thrw in destructor, btw all destructor are now no_except 
// so handle it in destructor or move exception prone code out of destructor

#define EXCEPTION_HANDLER_IN_DESTRUCTOR 0

struct Robot
{
    string name_;
    Robot(const string& name):name_(name){
        cout << endl << name_ << " is born!"; 
    }
    void fun2throwError()
    {
        cout << "\nException thrown should be handled by called function";
        throw "Dying";
    }
            
    void prepare2Die(){
        try{
            fun2throwError();
            cout << endl << name_ << " : I am done!"; 
            throw 20;
        } catch(int ex){
            cout << "\nException caught while cleanup, Code : " << ex << " Obj : " << name_ << endl;
        } catch (const char * str){
            cout << "\n" << str << " in "<< __FUNCTION__ << " Obj : " << name_ << endl;
        } catch (...){
            cout << "\nException caught while cleanup in "<< __FUNCTION__ << " Obj : " << name_ << endl;
        }
    }
    ~Robot(){
        //Swollow in excpetion
    #if EXCEPTION_HANDLER_IN_DESTRUCTOR
        try{
            cout << endl << name_ << " is dead!"; 
            throw 20;
        } catch(int ex){
            cout << "\nException caught in destructor, Code : " << ex << " Obj : " << name_ << endl;
        }
    #endif
    }
    void speaks(const std::string& str) {
        cout <<endl << name_ << " speaks : " << str;
    }
};

int main()
{
    try{
        Robot robo1("Robo1");
        Robot robo2("Robo2");
        //throw 20;

        robo1.speaks("Hello");
        robo2.speaks("Hi");  

        // move exception prone code fom destructor
        robo1.prepare2Die();
        robo2.prepare2Die();
    } catch(int ex){
        cout << "\nException caught, Code : " << ex << endl;
    }
    return 0;
}