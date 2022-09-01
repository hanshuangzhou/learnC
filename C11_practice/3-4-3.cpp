#include <iostream>
class ConvertTO {
public:
    ConvertTO() { std::cout << "construct\n";}
    ConvertTO(const ConvertTO& ct) {
        std::cout << "copy construct\n";
    }
};
class Convertable {
public:
    explicit operator ConvertTO () const { return ConvertTO();}
    // explicit用于类型转换操作符上，以为着只有在直接构造目标类型或者显示类型转换的时候可以使用该类型
};

void Func(ConvertTO ct) {}
void test() {
    Convertable c;
    ConvertTO ct(c);    //直接构造目标类型ConvertTo
    //ConvertTO ct2 = c;
    ConvertTO ct3 = static_cast<ConvertTO>(c); //显示类型转换
    //Func(c);
}

int main() {
    test();
    return 0;
}