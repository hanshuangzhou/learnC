#include <iostream>
using namespace std;

//异常类含有虚函数且存在继承关系
class BasicException
{
public:
    virtual char* where() { return "BasicException\n";}
};

class FileNotFound : public BasicException
{
public:
    virtual char* where() { return "FileNotFound\n";}
};

int main(){
    
    try {
        FileNotFound err;
        throw &err;
    }
    catch (BasicException* p) { cout << p->where();} //注意两条catch内参数的顺序
    return 0;
}
