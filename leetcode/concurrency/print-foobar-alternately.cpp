#include <condition_variable>
#include <functional>
#include <iostream>
#include <mutex>
#include <semaphore>
#include <thread>
#include <vector>

using namespace std;

class FooBar {
private:
    int n;
    binary_semaphore foo_now_sem{1};
    binary_semaphore bar_now_sem{0};

public:
    FooBar(int n) { this->n = n; }

    void foo(function<void()> printFoo) {
        for (int i = 0; i < n; i++) {
            foo_now_sem.acquire();
            // printFoo() outputs "foo". Do not change or remove this line.
            printFoo();
            bar_now_sem.release();
        }
    }

    void bar(function<void()> printBar) {
        for (int i = 0; i < n; i++) {
            bar_now_sem.acquire();
            // printBar() outputs "bar". Do not change or remove this line.
            printBar();
            foo_now_sem.release();
        }
    }
};

// Driver code
int main() {
    int n = 3;
    FooBar foobar(n);

    auto printFoo = []() { std::cout << "foo"; };
    auto printBar = []() { std::cout << "bar"; };

    // Test case: threads might be created in different order
    std::vector<std::thread> threads;

    threads.emplace_back(&FooBar::foo, &foobar, printFoo);
    threads.emplace_back(&FooBar::bar, &foobar, printBar);

    // Wait for all threads to complete
    for (auto &t : threads) {
        t.join();
    }

    std::cout << std::endl;
    return 0;
}
