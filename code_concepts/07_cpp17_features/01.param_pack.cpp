#include <iostream>
#include <string>

using namespace std;

template <typename T>
void rec_print(T value){
    std:: cout << value << "  ";
}
template <typename T, typename ... Args>
void rec_print(T value, Args... args){
    std:: cout << value << "  ";
    rec_print(args...);
}

template<typename T>
auto rec_cum_sum(T value){
    return value;
}
template<typename T, typename... Args>
auto rec_cum_sum(T value, Args... args){
    return value + rec_cum_sum(args...);
}

template <typename T, typename ... Args>
auto cum_sum(T value, Args... args)
{
    if constexpr(sizeof...(args) > 0)
        return value + cum_sum(args...);
    else 
        return value;


}

template<typename...Args>
auto cum_sum_int(Args... args) {
    if constexpr(sizeof...(Args) > 0){
        return (args + ...);
    } else {
        return 0;
    }
}
template<typename...Args>
auto cum_sum_str(Args... args) {
    if constexpr(sizeof...(Args) > 0){
        return (args + ...);
    } else {
        return 0;
    }
}

class Square
{
    int sides;
  public:
Square(int value) {
        std::cout << endl << "Square sides :" << value; 
    }

};
class Triangle
{
    int sides;
  public:
    Triangle(int value) {
        std::cout << endl << "Triangle sides :" << value; 
    }

};
template <typename ...Parents>
class ShapesSides : public Parents...
{
    std::string name_;
    public:
    ShapesSides(const std::string& val, Parents... parents):Parents(parents)..., name_(val){
        std::cout << "I am : " << name_;
    }

};

int main()
{
    // std::cout << "Demo : recursive print" << std::endl;
    // rec_print(3,4.5,"myname");
    // std::cout << "\nDemo : recursive print" << std::endl;
    // std:: cout << rec_cum_sum(3,4,5);
    
    std::cout << "\nDemo : param pack and sizeof ...(args)" << std::endl;
    std::string a{"3"}, b{"5"},c{"4"};
    //std:: cout << cum_sum(a,b,c);
    std:: cout << cum_sum_str(a,b,c);
    
    // std::cout << "\nDemo : param pack and sizeof ...(args)" << std::endl;
    // std:: cout << cum_sum_int(3,4,5);9999999999999

    ShapesSides<Square, Triangle> shp("lynus",4,5);
    
    return 0;
}