#include <iostream>
using namespace std;

//内部再次throw异常的时候，函数不要带throw()
void Errhandler(int n) {
    try {
        if (n == 1) throw n;
        cout << "all is OK\n";
    }
    catch(int n) {
        cout << "catch an int exception inside " << n << endl;
        throw n;
    }
}

int main() {
    
    try {
        Errhandler(1);
    }
    catch (int n) {
        cout << "catch an int exception in main() " << n << endl;
    }
    return 0;
}