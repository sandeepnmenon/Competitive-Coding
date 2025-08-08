#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <functional>
#include <vector>

using namespace std;

class FooBar {
private:
    int n;
    std::mutex mtx;
    std::condition_variable cv;
    bool foo_now;
public:
    FooBar(int n) {
        this->n = n;
        foo_now=true;
    }

    void foo(function<void()> printFoo) {

        for (int i = 0; i < n; i++) {
            std::unique_lock<std::mutex> lock(mtx);
            cv.wait(lock, [this] { return foo_now; });
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            foo_now=false;
            cv.notify_one();
        }
    }

    void bar(function<void()> printBar) {

        for (int i = 0; i < n; i++) {
            std::unique_lock<std::mutex> lock(mtx);
            cv.wait(lock, [this] { return !foo_now; });

        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            foo_now=true;
            cv.notify_one();
        }
    }
};

// Driver code
int main(int argc, char *argv[]) {
    if (argc < 2){
        std::cerr<<"Input an integer as command line argument"<<std::endl;
    }
    int n=std::stoi(argv[1]);
    FooBar foobar(n);

    auto printFoo = []() { std::cout << "foo"; };
    auto printBar = []() { std::cout << "bar"; };

    // Test case: threads might be created in different order
    std::vector<std::thread> threads;

    threads.emplace_back(&FooBar::foo, &foobar, printFoo);
    threads.emplace_back(&FooBar::bar, &foobar, printBar);

    // Wait for all threads to complete
    for (auto& t : threads) {
        t.join();
    }

    std::cout << std::endl;
    return 0;
}
