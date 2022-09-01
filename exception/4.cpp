#include <iostream>
using namespace std;

//注意和3.cpp的区别

void temperature(int t) {

    if (t == 100) throw "it is at boiling point\n";
    else if (t == 0) throw "it is at freezing point\n";
    else cout << "no throw.the temperature is OK\n";

}
int main() {
    try {
        temperature(0);
        temperature(10);
        temperature(100);
    }

    catch (char const* s) {
        cout << s;
    }

    return 0;
}