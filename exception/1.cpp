#include <iostream>
using namespace std;

int main() {
    cout << "1--before try block\n";

    try {
        cout << "2--inside try block\n";
        throw 10;
        cout << "3--after throw\n";
    }

    catch(int i) {
        cout << "4--in catch block1 error code is " << i << endl;
    }

    catch(char* s) {
        cout << "5--in catch block1 error code is " << s << endl;
    }
    
    cout << "6--after catch\n";
    return 0;
}