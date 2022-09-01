#include <iostream>
using namespace std;


void handler(int n) throw(int, char, double) { //throw(int, char, double)代表可以抛出int char double类型的异常
    if (n == 1) throw n;
    if (n == 2) throw "x";
    if (n == 3) throw 1.1;
}

int main() {
    cout << "before handler\n";
    try {
        handler(2);
    }
    catch (int i) {
        cout<<"catch an integer" << endl;
    }
    catch (char c) { // core dump!! terminate called after throwing an instance of 'char const*' 抛出的类型和捕获的类型不一致
        cout<<"catch an char" << endl;
    }
    catch (double d) {
        cout<<"catch an double" << endl;
    }
    return 0;
}