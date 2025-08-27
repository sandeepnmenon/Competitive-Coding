#include <bits/stdc++.h>

#include <semaphore>
#include <vector>
using namespace std;

class H2O {
public:
    counting_semaphore<2> hydrogen_count_sem{2};
    binary_semaphore oxygen_sem{0};

    H2O() {}

    void hydrogen(function<void()> releaseHydrogen) {
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        hydrogen_count_sem.acquire();
        releaseHydrogen();
        if (hydrogen_count_sem.try_acquire()) {
            hydrogen_count_sem.release();
        } else {
            oxygen_sem.release();
        }
    }

    void oxygen(function<void()> releaseOxygen) {
        // releaseOxygen() outputs "O". Do not change or remove this line.
        oxygen_sem.acquire();
        releaseOxygen();
        hydrogen_count_sem.release(2);
    }
};

int main() {
    string water = "OOHHHH";
    H2O h2o;
    auto releaseHydrogen = []() { cout << "H"; };
    auto releaseOxygen = []() { cout << "O"; };

    vector<thread> threads;
    for (auto element : water) {
        if (element == 'H') {
            threads.emplace_back(&H2O::hydrogen, &h2o, releaseHydrogen);
        } else if (element == 'O') {
            threads.emplace_back(&H2O::oxygen, &h2o, releaseOxygen);
        }
    }

    for (auto &t : threads) {
        t.join();
    }

    cout << endl;
    return 0;
}