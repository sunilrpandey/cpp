#include <iostream>
using namespace std;

// Dont thrw in destructor, btw all destructor are now no_except 
// so handle it in destructor or move exception prone code out of destructor

#define EXCEPTION_HANDLER_IN_DESTRUCTOR 0

struct Robot
{
    string name_;
    Robot(const string& name) :name_(name) {
        cout << endl << name_ << " is born!";
    }
    void fun2throwError()
    {
        cout << "\nException thrown should be handled by called function";
        throw "Dying";
    }

    void prepare2Die() {
        try {
            fun2throwError();
            cout << endl << name_ << " : I am done!";
            throw 20;
        }
        catch (int ex) {
            cout << "\nException caught while cleanup, Code : " << ex << " Obj : " << name_ << endl;
        }
        catch (const char* str) {
            cout << "\n" << str << " in " << __FUNCTION__ << " Obj : " << name_ << endl;
        }
        catch (...) {
            cout << "\nException caught while cleanup in " << __FUNCTION__ << " Obj : " << name_ << endl;
        }        
    }
    ~Robot() {
        //Swollow in excpetion
#if EXCEPTION_HANDLER_IN_DESTRUCTOR
        try {
            cout << endl << name_ << " is dead!";
            throw 20;
        }
        catch (int ex) {
            cout << "\nException caught in destructor, Code : " << ex << " Obj : " << name_ << endl;
        }
#endif
    }
    void speaks(const std::string& str) {
        cout << endl << name_ << " speaks : " << str;
    }
};

void demoHandleExceptionInDestructor()
{
    try {
        Robot robo1("Robo1");
        Robot robo2("Robo2");
        //throw 20;

        robo1.speaks("Hello");
        robo2.speaks("Hi");

        // move exception prone code fom destructor
        robo1.prepare2Die();
        robo2.prepare2Die();
    }
    catch (int ex) {
        cout << "\nException caught, Code : " << ex << endl;
    }
}
std::tuple<int, int> getNumDevisor() 
{
    return make_tuple(15, 0);
}
void BasicExceptionHandling()
{
    try {
        //auto [num, devisor] = getNumDevisor();
        auto [num, devisor] = []() {return make_tuple(15, 0); }();
        if (devisor == 0) {
            // throw std::runtime_error("Devison by zero error");
            // throw 101;
            throw "Division by Zero!!";
        }
        auto answer = num / devisor;

        cout << "\nanswer : " << answer;
    }
    catch (int exceptionCode) {
        cout << "Exception Code : " << exceptionCode;
    }
    catch (const std::exception& e) {
        std::cout << "caught divided by zero!! error : " << e.what();
    }
    catch (...) {
        std::cout << "home to any kind of exceptions!!";
    }

}

class FileException : public std::exception
{
public:
    explicit FileException(const std::string& message)
        : std::exception(), error_msg(message) {

    }
    const char* what() const noexcept override {
        return error_msg.c_str();
    }
protected:
    std::string error_msg;

};

class FileNotFoundException : public FileException {
public:
    explicit FileNotFoundException(const std::string& filename)
        : FileException("File not found: " + filename) {}
};

void openFile(const std::string& filename) {
    //Supposing file is not available
    throw FileNotFoundException(filename);
}

int demoExceptionHierarchy() {
    std::string filename = "myfile.txt";

    try {
        openFile(filename);
    }
    catch (const FileException& ex) {
        std::cout << "Caught File Exception: " << ex.what() << std::endl;
    }
    catch (const std::exception& ex) {
        std::cout << "Caught Standard Exception: " << ex.what() << std::endl;
    }

    return 0;
}

void demoExceptionHandling()
{
    /*    
    BasicExceptionHandling();   
    demoExceptionHierarchy();
    */
    demoHandleExceptionInDestructor();

}
