#include <condition_variable>
#include <functional>
#include <iostream>
#include <mutex>
#include <semaphore>
#include <thread>
#include <vector>

class Foo {
private:
    std::binary_semaphore first_sem{1};
    std::binary_semaphore second_sem{0};
    std::binary_semaphore third_sem{0};

public:
    Foo() {}

    void first(std::function<void()> printFirst) {
        first_sem.acquire();
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        second_sem.release();
    }

    void second(std::function<void()> printSecond) {
        second_sem.acquire();
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        third_sem.release();
    }

    void third(std::function<void()> printThird) {
        third_sem.acquire();
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};

// Driver code
int main() {
    Foo foo;

    auto printFirst = []() { std::cout << "first"; };
    auto printSecond = []() { std::cout << "second"; };
    auto printThird = []() { std::cout << "third"; };

    // Test case: threads might be created in different order
    std::vector<std::thread> threads;

    // Create threads in reverse order to test synchronization
    threads.emplace_back(&Foo::third, &foo, printThird);
    threads.emplace_back(&Foo::first, &foo, printFirst);
    threads.emplace_back(&Foo::second, &foo, printSecond);

    // Wait for all threads to complete
    for (auto &t : threads) {
        t.join();
    }

    std::cout << std::endl;
    return 0;
}
