#include <iostream>
using namespace std;
void Throw() { throw 1; }
void NoBlockThrow() { Throw(); }
void BlockThrow() noexcept { Throw(); } 
//在C++11中如果noexcept修饰的函数抛出了异常，编译器可以选择直接调用std::terminate()函数来终止程序的运行

int main() 
{            
    try {
        Throw();
    }            
    catch(...) {
        cout << "Found throw." << endl;      // Found throw.
    }

    try {
        NoBlockThrow();
    }
    catch(...) {
        cout << "Throw is not blocked." << endl;     // Throw is not blocked.            
    }

    try {
        BlockThrow();    // terminate called after throwing an instance of 'int'            
    }
    catch(...) {
        cout << "Found throw 1." << endl;
    }

    }