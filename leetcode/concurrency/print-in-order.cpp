#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <functional>
#include <vector>

class Foo {
private:
    std::mutex mtx;
    std::condition_variable cv;
    int step;

public:
    Foo() : step(1) {
        
    }

    void first(std::function<void()> printFirst) {
        std::unique_lock<std::mutex> lock(mtx);
        
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        step = 2;
        cv.notify_all();
    }

    void second(std::function<void()> printSecond) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [this] { return step >= 2; });
        
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        step = 3;
        cv.notify_all();
    }

    void third(std::function<void()> printThird) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [this] { return step >= 3; });
        
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
    for (auto& t : threads) {
        t.join();
    }
    
    std::cout << std::endl;
    return 0;
}
