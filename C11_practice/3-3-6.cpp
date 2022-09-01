#include <iostream>
using namespace std;

//std::move 会把一个左值强制转化为右值引用，但是，必须注意，被转化的左值，其生命期并没有随左右值的改变而改变
class Moveable {
public:
    Moveable() : i(new int(3)) {}
    ~Moveable() {
        delete i;
        i = nullptr;
    }
    Moveable(const Moveable& m) : i(new int(*m.i)) {}
    Moveable(Moveable&& m) : i(m.i) {
        m.i = nullptr;
    }
    int* i;
};

int main() {
    Moveable a;
    Moveable c(std::move(a));
    cout << *a.i << endl;

    return 0;
}

//编译指令g++ -std=c++11 3-3-6.cpp -fno-elide-constructors