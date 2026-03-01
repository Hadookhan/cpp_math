#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <atomic>

static std::atomic<int> shared_value=0;

void shared_value_increment() {
    // Critical section (atomic section of code)
        try {
            shared_value++; // atomic overload increment operator
        } catch(...) {
            std::cout << "handle exception";
            throw "dangerous...abort";
        }
}

int main() {

    std::vector<std::thread> threads;

    for (int i = 0; i < 1000; ++i) {
        threads.push_back(std::thread(shared_value_increment));
    }

    for (auto& t : threads) {
        t.join();
    }

    std::cout << "Shared value: " << shared_value << std::endl;

    return 0;
}