#include <iostream>
#include <string>
using namespace std;

//Doubt : NOT SURE ABOUT PARAMS AND RETURN TYPE .. NEED TO CHECK

// for buildin literals only
// std::string operator"" _male(const std::string& str) {
//     return std::string("Mr " + str);
// }
long double operator"" _cm(long double x){
    return x * 10;
}
unsigned long operator"" _kg(unsigned long long  x){
    return x * 1000;
}


int main()
{
    //std::string name = "Sunil"_male;
    long double height = 3.4_cm;
    cout << "\n height in mms : " << height;
    unsigned long wt = 12_kg;
    cout << "\n weight in GMs : " << wt;
    
    cout << endl;
    return 0;
}