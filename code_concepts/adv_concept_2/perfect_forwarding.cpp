#include <iostream>
using namespace std;

#pragma region "r/l value demo"
//void show(int i) {
//	cout << "int - " << i;
//}
void show(const int& i) {
	cout << endl << "const int ref - " << i;
}
void show(int && i) {
	cout << endl << "r value ref - " << i;
}
#pragma endregion


template <typename T>
void relayWithoutPerfectForwarding(T&& val) {
	show(val);
}
template <typename T>
void relayWithPerfectForwarding(T&& val) {
	show(std::forward<T>(val));
}
#pragma endregion

int main()
{
    auto i = 10;
	cout << ": Perfect Forwarding Demo : ";
	
    cout << "\n\nshowing value based on passed type, value or rvalue" ;
    show(i);
	show(std::move(i));
	
	//std::forward use
    cout << "\n\nForwarding now without using std::forward";
	relayWithoutPerfectForwarding(std::move(i));
	cout << "\n\nForwarding now with std::forward";
	relayWithPerfectForwarding(std::move(i));
	relayWithoutPerfectForwarding(i);

    cout << endl;
    return 0;
}