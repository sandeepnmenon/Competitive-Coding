#include <bits/stdc++.h>
#include <condition_variable>
#include <iterator>
#include <mutex>
using namespace std;

class ZeroEvenOdd {
private:
  int n;
  std::mutex mtx;
  std::condition_variable cv;
  bool is_zero;
  bool is_odd;

public:
  ZeroEvenOdd(int n) {
    this->n = n;
    is_zero = true;
    is_odd = false;
  }

  // printNumber(x) outputs "x", where x is an integer.
  void zero(function<void(int)> printNumber) {
    for (int i = 0; i < n; ++i) {
      unique_lock<mutex> lock(mtx);
      cv.wait(lock, [this]() { return is_zero; });
      printNumber(0);
      is_zero = false;
      is_odd = (i % 2 == 0) ? true : false;
      cv.notify_all();
    }
  }

  void even(function<void(int)> printNumber) {
    int numEven = n / 2;
    for (int i = 0; i < numEven; ++i) {
      unique_lock<mutex> lock(mtx);
      cv.wait(lock, [this]() { return !is_zero && !is_odd; });
      printNumber(i * 2 + 2);
      is_zero = true;
      cv.notify_all();
    }
  }

  void odd(function<void(int)> printNumber) {
    int numOdd = (n % 2 == 0) ? n / 2 : n / 2 + 1;

    for (int i = 0; i < numOdd; ++i) {
      unique_lock<mutex> lock(mtx);
      cv.wait(lock, [this]() { return !is_zero && is_odd; });
      printNumber(i * 2 + 1);
      is_zero = true;
      cv.notify_all();
    }
  }
};

// Driver code
int main() {
  int n = 1000;
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
