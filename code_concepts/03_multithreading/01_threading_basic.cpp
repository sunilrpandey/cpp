#include <iostream>
#include <thread>
using namespace std;

struct ThreadWrapper
{
    std::thread thread;
    ThreadWrapper(std::thread t):thread(move(t)){}
    ~ThreadWrapper() {
        if(thread.joinable())
            thread.join();
    }
};

int thread_fun() {
    cout << "\nPrinting from the thread_fun";
    return 0;
}
struct FunctObject
{
    int operator()(){
        for(int i =0; i< 100; i++){
            cout << "\n From FunctionObject :" << i;
        }
    }

};

struct FunctObject_withMsg
{
    int operator()(std::string& msg){
            cout << "\nThread Says : " << msg << "thread id : " << this_thread::get_id();
            msg = "Hi";
    }

};

class ThreaadLauncher
{
    public:
    void launch(){
        cout << "\nFrom Thread Launcher.. ";
    }
};

int main() {
    ThreaadLauncher launcher;
    std::thread tl(&ThreaadLauncher::launch, &launcher);
    std::this_thread::sleep_for(1000ms);
    tl.join();
    return 0;
    //std::thread t1(thread_fun);
    //std::thread thread_funObj((FunctObject()));
    std::string msg2thread("Hello");
#if 0 // very basic    
    try{
        for(int i =0; i< 100; i++){
            cout << "\n From Main :" << i;
        }
    } catch(...) {
        if(t1.joinable())
            t1.join();
        throw;
    }
    if(t1.joinable())
        t1.join();
    if(thread_funObj.joinable()){
        thread_funObj.join();
    }
    //t1.detach();

#endif
    std::thread thread_funObj_passStr((FunctObject_withMsg()),std::ref(msg2thread));
    // if you want to pass string to thread but dont want it back
    //std::thread thread_funObj_passStr((FunctObject_withMsg()),std::move(msg2thread));
    
    if(thread_funObj_passStr.joinable()){
        thread_funObj_passStr.join();
    }
    
try{
        cout << "\n From Main :" << msg2thread << "thread id : " << this_thread::get_id();
    } catch(...) {
        if(thread_funObj_passStr.joinable())
            thread_funObj_passStr.join();
        throw;
    }

    cout << endl;
    return 0;
}

