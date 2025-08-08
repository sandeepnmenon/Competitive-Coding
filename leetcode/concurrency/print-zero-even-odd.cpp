#include <bits/stdc++.h>

#include <semaphore>

using namespace std;

class ZeroEvenOdd {
private:
    int n;
    binary_semaphore zero_sem{1};
    binary_semaphore odd_sem{0};
    binary_semaphore even_sem{0};

public:
    ZeroEvenOdd(int n) { this->n = n; }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        for (int i = 0; i < n; ++i) {
            zero_sem.acquire();
            printNumber(0);
            if (i % 2 == 0)
                odd_sem.release();
            else
                even_sem.release();
        }
    }

    void even(function<void(int)> printNumber) {
        for (int i = 2; i <= n; i += 2) {
            even_sem.acquire();
            printNumber(i);
            zero_sem.release();
        }
    }

    void odd(function<void(int)> printNumber) {
        for (int i = 1; i <= n; i += 2) {
            odd_sem.acquire();
            printNumber(i);
            zero_sem.release();
        }
    }
};

// Driver code
int main() {
    int n = 2;
    ZeroEvenOdd zeroEvenOdd(n);

    auto printNumber = [](int num) { std::cout << num; };

    // Test case: threads might be created in different order
    std::vector<std::thread> threads;

    threads.emplace_back(&ZeroEvenOdd::zero, &zeroEvenOdd, printNumber);
    threads.emplace_back(&ZeroEvenOdd::even, &zeroEvenOdd, printNumber);
    threads.emplace_back(&ZeroEvenOdd::odd, &zeroEvenOdd, printNumber);

    // Wait for all threads to complete
    for (auto &t : threads) {
        t.join();
    }

    std::cout << std::endl;
    return 0;
}
