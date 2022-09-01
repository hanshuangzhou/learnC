#include <iostream>
using namespace std;

int main() {
    cout << "1--before try block\n";

    try {
        cout << "2--inside try block\n";
        throw 10;
        cout << "3--after throw\n";
    }

    catch(double i) { //catch 捕获异常时，不会进行数据类型的隐式转换！！
                      //因此在这个例子中程序会terminate,因为抛出的异常没有对应的catch处理
        cout << "4--in catch block1 error code is " << i << endl;
    }
    
    cout << "5--after catch\n";
    return 0;
}