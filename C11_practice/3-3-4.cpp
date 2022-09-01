#include <iostream>
using namespace std;

class HasPtrMem {
public:
    HasPtrMem() : d(new int(0)) {
        cout << "Constrct: " << ++n_cstr << endl;
    }

    HasPtrMem(const HasPtrMem& h) : d(new int(*h.d)) {
        cout << "Copy Constrct: " << ++n_cptr << endl;
    }

    HasPtrMem(HasPtrMem&& h) : d(h.d) {
        h.d = nullptr;
        cout << "Move constrct: " << ++n_mvtr << endl;
    }
    
    ~HasPtrMem() {
        cout << "Destruct: " << ++n_dstr << endl;
    }

    int* d;
    static int n_cstr;
    static int n_dstr;
    static int n_cptr;
    static int n_mvtr;
};

int HasPtrMem::n_cstr = 0;
int HasPtrMem::n_dstr = 0;
int HasPtrMem::n_cptr = 0;
int HasPtrMem::n_mvtr = 0;

HasPtrMem GetTmp() {
    HasPtrMem h;
    cout << "resource from " << __func__ << ":" << hex << h.d << endl;
    return h;
}

int main() {

    HasPtrMem a = GetTmp();
    cout << "resource from " << __func__ << ":" << hex << a.d << endl;
    cout << "----before a destruct----\n";
    return 0;
}
//编译指令g++ -std=c++11 3-3-4.cpp -fno-elide-constructors