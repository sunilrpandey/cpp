#include <iostream>
#include <thread>
using namespace std;

namespace ns_common
{
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
        return 0;
    }

};

struct FunctObject_withMsg
{
    int operator()(std::string& msg){
            cout << "\nThread Says : " << msg << "thread id : " << this_thread::get_id();
            msg = "Hi";

            return 0;
    }

};

class ThreaadLauncher
{
    public:
    void launch(const std::string& msg){
        cout << msg.c_str() << "Launched from Thread Launcher class.. ";
    }
};
}

void demo_launch_thread_using_class_func(){

    using namespace ns_common;
    ThreaadLauncher launcher;
    std::thread tl(&ThreaadLauncher::launch, &launcher, "\nMyThread : ");
    std::this_thread::sleep_for(1000ms);
    tl.join();
    return;    

}
void demo_lanuch_thread_using_funcobject(){

    using namespace ns_common;
    std::thread t1(thread_fun);
    std::thread thread_funObj((FunctObject()));
    t1.join();
    thread_funObj.join();

    return;    
}

void demo_lanuch_thread_using_fun(){
    using namespace ns_common;
    std::thread t1(thread_fun);
    t1.join();
}

void demo_lanuchThread()
{
    using namespace ns_common;
    demo_lanuch_thread_using_fun();
    demo_launch_thread_using_class_func();
    demo_lanuch_thread_using_funcobject();
    
    return;
}

void demo_basic_threads()
{
    using namespace ns_common;    

    std::thread t1(thread_fun);
    std::thread thread_funObj((FunctObject()));
    std::this_thread::sleep_for(1000ms);
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
}

void demo_pass_str_to_thread()
{
    using namespace ns_common;    

    std::string msg2thread("Hello");
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


}


int main() {
    //demo_lanuchThread();
    //demo_basic_threads();
    demo_pass_str_to_thread();
    
    cout << endl;
    return 0;
}

