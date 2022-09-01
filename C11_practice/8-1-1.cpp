#include <iostream>
#include <stddef.h>
using namespace std;

//为什么需要数据对齐
struct HowManyBytes {
    char a;
    int b;
};

int main() {
    cout << "sizeof(char): " << sizeof(char) << endl;
    cout << "sizeof(int): " << sizeof(int) << endl;
    cout << "sizeof(HowManyBytes): " << sizeof(HowManyBytes) << endl;

    cout << endl;
    cout << "offset of char a: " << offsetof(HowManyBytes, a) << endl;
    cout << "offset of int b: " << offsetof(HowManyBytes, b) << endl;

    return 0;
}