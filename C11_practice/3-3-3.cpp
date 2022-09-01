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
    
    ~HasPtrMem() {
        cout << "Destruct: " << ++n_dstr << endl;
    }

    int* d;
    static int n_cstr;
    static int n_dstr;
    static int n_cptr;
};

int HasPtrMem::n_cstr = 0;
int HasPtrMem::n_dstr = 0;
int HasPtrMem::n_cptr = 0;

HasPtrMem GetTmp() {
    return HasPtrMem();
}

int main() {

    HasPtrMem a = GetTmp();
    cout << "----before a destruct----\n";
    return 0;
}

//编译命令    g++ 3-3-3.cpp -fno-elide-constructors
//          g++ 3-3-3.cpp 
//          有时候结果和你想的不一样，可能是编译器优化了

//-fno-elide-constructors
//The C++ standard allows an implementation to omit creating a temporary 
//that is only used to initialize another object of the same type. 
//Specifying this option disables that optimization, and forces G++ to call the copy constructor in all cases.
