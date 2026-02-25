#include <stdio.h>
#include <thread>
#include <chrono>
#include <mutex>
#include <vector>


int counter = 0;
std::mutex m;

void race_counter(int N) {
    for (int i = 0; i < N; ++i) {
        std::lock_guard<std::mutex> lock(m);
        counter++;
    }
}

int main() {

    const int thread_num = 2;
    const int N = 1'000'000;

    std::vector<std::thread> threads;

    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < thread_num; ++i) {
        threads.emplace_back(race_counter, N);
    }

    for (auto& t : threads) {
        t.join();
    }

    auto end = std::chrono::high_resolution_clock::now();

    printf("time: %ld ms\n", std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count());
    printf("counter: %d\n", counter);

    return 0;
}