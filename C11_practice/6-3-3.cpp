#include <iostream>
#include <thread>
#include <atomic>
#include <unistd.h>
using namespace std;

atomic_flag lock = ATOMIC_FLAG_INIT;
void f(int n) {
    while (lock.test_and_set(std::memory_order_acquire))
        cout << "waiting from thread " << n << endl;
    cout << "thread " << n << " starts working\n";
}

void g(int n) {
    cout << "thread " << n << " is going to start\n";
    lock.clear();
    cout << "thread " << n << " starts working\n";
}

int main() {
    lock.test_and_set();
    thread t1(f, 1);
    thread t2(g, 2);

    t1.join();
    usleep(100);
    t2.join();

    return 0;
}
#if 0

//6-21 code list
int ValueSet(int) {
    int t = 1;
    a = t;
    b = 2;
}
#endif