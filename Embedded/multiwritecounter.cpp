#include <iostream>
#include <thread>
#include <vector>
#include <shared_mutex>
#include <condition_variable>

class Counter {
private:
    int value;
    mutable std::shared_mutex mtx;
    std::condition_variable_any cv;

public:
    Counter() : value(0) {}

    // Multiple readers allowed
    int get() const {
        std::shared_lock lock(mtx);
        return value;
    }

    // Only one writer at a time, blocks readers
    void put(int newValue) {
        std::unique_lock lock(mtx);
        value = newValue;
        cv.notify_all();
    }

    // Wait until counter reaches target
    void waitFor(int target) {
        std::shared_lock lock(mtx);
        cv.wait(lock, [this, target] { return value == target; });
    }
};

// Example usage
int main() {
    Counter counter;

    // Writer thread
    std::thread writer([&counter]() {
        for (int i = 1; i <= 5; ++i) {
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            counter.put(i);
            std::cout << "Writer set value to: " << i << std::endl;
        }
    });

    // Reader threads
    std::vector<std::thread> readers;
    for (int i = 0; i < 3; ++i) {
        readers.emplace_back([&counter, i]() {
            for (int j = 0; j < 5; ++j) {
                std::this_thread::sleep_for(std::chrono::milliseconds(120));
                int val = counter.get();
                std::cout << "Reader " << i << " read value: " << val << std::endl;
            }
        });
    }

    // Wait for threads to finish
    for (auto& t : readers) t.join();
    writer.join();

    return 0;
}
