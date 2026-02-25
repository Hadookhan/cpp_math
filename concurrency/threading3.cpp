#include "constants.hpp"
#include <stdio.h>
#include <thread>
#include <mutex>
#include <chrono>
#include <vector>
#include <atomic>

using namespace std;

int count=0;
mutex m;

void race_condition(int iters) {
    for (int i=0; i<iters;++i) {
        lock_guard<mutex> lock(m);
        count++;
    }
}

int main() {

    vector<thread> threads;

    auto start = chrono::high_resolution_clock::now();

    for (int i=0; i<THREADS;++i) {
        threads.emplace_back(race_condition, ITERATIONS);
    }

    for (auto& t : threads) {
        t.join();
    }

    auto end = chrono::high_resolution_clock::now();

    printf("time: %ld ms\n", chrono::duration_cast<chrono::milliseconds>(end - start).count());
    printf("count: %d\n", count);

    return 0;
}