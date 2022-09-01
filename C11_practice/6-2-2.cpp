#if 1
#include <iostream>

template<typename... Values> class tuple;
template<> class tuple<> {};

template<typename Head, typename... Tail>
class tuple<Head, Tail...> : private tuple<Tail...>
{
    typedef tuple<Tail...> inherited;

public:
    tuple() {}
    tuple(Head v, Tail... vtail) : m_head(v), inherited(vtail...) {
        std::cout << "construct: " << v << std::endl;
    }

    Head& head() { return m_head;}

    // 这个this指针很关键，不清楚的朋友可以自己查一下
    // 继承类的this其实是指向它的基类。
    inherited& tail() { return *this;}

protected:
    Head m_head;    
};

int main() {
    tuple<int, float, std::string>  t(1, 6.6, "hello");

    std::cout << t.head() << " "
              << t.tail().head() << " "
              << t.tail().tail().head() << std::endl; 
    return 0;
    //参考网址：https://juejin.cn/post/7108354496320765960#heading-1
}

#else

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <typeinfo>

// 在C++11之前，类模板和函数模板只能含有固定数量的模板参数。C++11增强了模板功能，允许模板定义中包含0到任意个模板参数，这就是可变参数模板。

// 可变参数模板类 继承方式展开参数包
// 可变参数模板类的展开一般需要定义2 ~ 3个类，包含类声明和特化的模板类
template<typename... A> class BMW;  // 变长模板的声明

template<typename Head, typename... Tail>  // 递归的偏特化定义
class BMW<Head, Tail...> : public BMW<Tail...>
{//当实例化对象时，则会引起基类的递归构造
public:
    BMW()
    {
        printf("type: %s\n", typeid(Head).name());
    }

    Head head;
};

template<> class BMW<>{};  // 边界条件

// 模板递归和特化方式展开参数包 此时参数包中每个参数的类型是明确的
template <long... nums> struct Multiply;// 变长模板的声明

template <long first, long... last>
struct Multiply<first, last...> // 变长模板类
{
    static const long val = first * Multiply<last...>::val;
};

template<>
struct Multiply<> // 边界条件
{
    static const long val = 1;
};


void MyTest()
{
    BMW<int, char, float> car;
    /*
    运行结果：
        type: f
        type: c
        type: i
    */

    std::cout << Multiply<2, 3, 4, 5>::val << std::endl; // 120


    return;
}


int main()
{
    MyTest();

    return 0;
}

#endif