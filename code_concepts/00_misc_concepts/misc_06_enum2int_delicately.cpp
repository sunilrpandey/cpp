#include <iostream>
#include <vector>
#include <type_traits>
using namespace std;

//Note : Obtains the underlying type of enum type T.

enum class Color : short
{
    While,
    Black, 
    Red,
    Green,
    Yello,
    Blue
};

// typename keyword before  std::underlying_type<E>::type specified that return type is a type rather than a value.
template <typename E>
constexpr typename std::underlying_type<E>::type to_underlyingtype(E value) noexcept{
    return static_cast<typename std::underlying_type<E>::type>(value);
}

int main()
{
    using enmType = std::underlying_type<Color>::type;
    enmType green = to_underlyingtype(Color::Green);
    cout << "Color index is :" << green; 
    cout << std::boolalpha << "\n.. data type is short : " << std::is_same<short,enmType>::value; 
    cout << std::boolalpha << "\n.. data type is int : " << std::is_same<int,enmType>::value; 

    cout << endl;
    return 0;

};
