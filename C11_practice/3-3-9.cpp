#include <iostream>
using namespace std;

//转发函数模板 ---> 目标函数
void RunCode(int&& m) { cout << "rvalue ref\n";}
void RunCode(int& m) { cout << "lvalue ref\n";}
void RunCode(const int&& m) { cout << "const rvalue ref\n";}
void RunCode(const int& m) { cout << "const lvalue ref\n";}

template <typename T>
void PerfectForward(T&& t) { RunCode(forward<T>(t));}

int main() {
    int a;
    int b;
    const int c = 1;
    const int d = 0;

    PerfectForward(a);
    PerfectForward(move(b));
    PerfectForward(c);
    PerfectForward(move(d));

    return 0;
}