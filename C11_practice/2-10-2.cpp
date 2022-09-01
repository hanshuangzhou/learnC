#include <iostream>
using namespace std;

class Base {
public:
    virtual void Print() final { cout << "i am Base Print\n";} // final修饰符的作用
};

class Derived : public Base {
public:
    virtual void Print() { cout << "i am Derived Print\n";}
};

int main() {

    return 0;
}