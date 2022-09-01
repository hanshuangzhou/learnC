#include <atomic>
#include <string>
#include <thread>
#include <assert.h>

using namespace std;
atomic<string*> ptr;
atomic<int> data;

void Producer() {
    string* p = new string("hello");
    data.store(42, memory_order_relaxed); // data = 42
    ptr.store(p, memory_order_relaxed); // ptr = p;
}

void Consumer() {
    string* p2;
    while ( !(p2 = ptr.load(memory_order_consume)))
        ;
    assert(*p2 == "hello");
    assert(data.load(memory_order_relaxed) == 42);
}

int main() {
    thread t1(Producer);
    thread t2(Consumer);

    t1.join();
    t2.join();
    
    return 0;
}