#include <iostream>
using namespace std;

//捕获自定义的异常类型
const int MAX = 3;
class Full {};
class Empty {};

class Stack
{
public:
    Stack() {
        top = -1;
    }

    void push(int a);
    int pop();

private:
    int s[MAX];
    int top;
};

void Stack::push(int a) {
    if (top >= MAX - 1)
        throw Full();
    s[++top] = a;
}

int Stack::pop() {
    if (top < 0)
        throw Empty();
    return s[top--];
}

int main(){
    Stack s;

    try {
        s.push(1);
        s.push(2);
        s.push(3);
        s.push(4);

        s.pop();
        s.pop();
        s.pop();
        //s.pop();
    }
    catch (Full) { cout << "stack is full\n";}
    catch (Empty) { cout << "stack is empty\n";}
    return 0;
}
