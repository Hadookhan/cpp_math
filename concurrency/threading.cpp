#include <stdio.h>
#include <thread>
#include <mutex>
#include <vector>
#include <chrono>

using namespace std;

int counter = 0;

mutex m;

void race(int N) {
    for (int i = 0; i < N; ++i) {
        lock_guard<mutex> lock(m);
        counter++;
    }
}

int main() {

    const int num_threads = 4;
    const int iterations = 1'000'000;

    vector<thread> threads;

    auto start = chrono::high_resolution_clock::now();
    for (int i = 0; i < num_threads; ++i)
        threads.emplace_back(race, iterations);

    for (auto& t : threads) {
        t.join();
    }
    auto end = chrono::high_resolution_clock::now();

    printf("time: %ld ms\n", chrono::duration_cast<chrono::milliseconds>(end - start).count());
    
    printf("counter: %d", counter);



    return 0;
}