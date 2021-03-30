#include <iostream>
#include <cstring>
using namespace std;

/*

//static analyzer tool
// spelling grammar , what you wnt to do/say
// static analysis just do that
//static analysisi tool = clang, cppcheck, cppDepend, clang-tidy

list of checks in CPPCheck : https://sourceforge.net/p/cppcheck/wiki/ListOfChecks/

void foo(int x)
{
    int buf[10];
    if (x == 1000)
        buf[x] = 0; // <- ERROR
}

void foo(int x)
{
    int buf[10];
    buf[x] = 0; // <- ERROR
    if (x == 1000) {}
}
copy paste issues, in nested for loop
bufer size is not length + 1 
some variable is always flase/true
*/

namespace ns_common
{
class String
{
    public:
    String() = default;
    String(const char * string)
    {
        m_size = strlen(string);
        m_Data = new char[m_size + 1];
        memcpy(m_Data, string, m_size * sizeof (char));
        cout << "Created " ; 
        print();
   }
   String(const String& rhs)
    {
        m_size = rhs.m_size;
        m_Data = new char[m_size + 1];
        memcpy(m_Data, rhs.m_Data, m_size * sizeof (char));
        cout << "Copied ";
        print();

   }

   // move constructor 
   String(String&& rhs) noexcept
    {
        m_size = rhs.m_size;
        m_Data = rhs.m_Data;
        rhs.m_size = 0;
        rhs.m_Data = nullptr;
        cout << "Moved ";
        print();
   }

   //move assignment operator 
   String& operator = (String&& rhs) noexcept
    {
        if(this == &rhs)
            return *this;
        
        delete[] m_Data;
        m_size = rhs.m_size;
        m_Data = rhs.m_Data;
        
        rhs.m_size = 0;
        rhs.m_Data = nullptr;
        
        cout << "Moved and Assigned";
        print();
        return *this;
   }
   
   void print()
   {
       if(m_Data) {
            for(int i = 0; i < m_size; i++) {
                cout << m_Data[i];
            }
       }
       cout << endl;
   }
   ~String()
   {
       if(m_Data)

        {
        cout << "Destroyed : " ;
        print();
        delete[] m_Data;
       }
   }
   private:
   int m_size;
   char * m_Data;

};
class Entity
{
    public:
    // Entity(const String& name) : m_Name (name)
    // {        
    // }
    Entity(String&& name) : m_Name (std::move(name)) // (String&&)name also works
    {        
    }
    void printName()
    {
        m_Name.print();
    }

    private:
    String m_Name;
};

void demo_move_semanatics()
{
    Entity entity("Robo");
    entity.printName();
}

void demo_move_assignment()
{
    String src = "Source";
    String dest ;
    std::cout << "src : ";  src.print();
    std::cout << "dest : "; dest.print();
    
    dest = std::move(src);

    std::cout << "\nAfter move " << std::endl;
    std::cout << "src : ";
    src.print();
    std::cout << "dest : ";
    dest.print();
}
}
void demo()
{
    ns_common::demo_move_semanatics();
    ns_common::demo_move_assignment();
}
int main()
{    
    demo();
    return 0;
}