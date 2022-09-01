#include <iostream>
using namespace std;

class BasicException
{
public:
    char* where() { return "BasicException\n";}
};

class FileNotFound : public BasicException
{
public:
    char* where() { return "FileNotFound\n";}
};

int main(){
    
    try {
        throw FileNotFound();
    }
    catch (BasicException& p) { cout << p.where();} //注意两条catch内参数的顺序
    catch (FileNotFound& p) { cout << p.where();}

    try {
        throw FileNotFound();
    }
    catch (FileNotFound& p) { cout << p.where();}
    catch (BasicException& p) { cout << p.where();}
    return 0;
}
