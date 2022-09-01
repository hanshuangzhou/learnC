#include <iostream>
using namespace std;

void temperature(int t) {
    try {
        if (t == 100) throw "it is at boiling point\n";
        else if (t == 0) throw "it is at freezing point\n";
        else cout << "no throw.the temperature is OK\n";
    }
    catch (int i) {
        cout << "temperature = " << i << endl;
    }
    catch (char const* s) {
        cout << s;
    }
}
int main() {

    temperature(0);
    temperature(10);
    temperature(100);

    return 0;
}