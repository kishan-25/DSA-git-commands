#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <vector>
#include <chrono>

using namespace std;

class Semaphore {
private:
    mutex mtx;
    condition_variable cv;
    int count;

public:
    Semaphore(int init_count) : count(init_count) {}

    void acquire() {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, [this]() { return count > 0; });
        count--;
    }

    void release() {
        unique_lock<mutex> lock(mtx);
        count++;
        cv.notify_one();
    }
};

Semaphore sem(5); // Max 5 threads at once

void task(const string& name) {
    sem.acquire();

    for (int i = 0; i < 5; i++) {
        cout << name << " working" << endl;
        this_thread::sleep_for(chrono::seconds(1));
    }

    sem.release();
}

int main() {
    vector<thread> threads;

    threads.emplace_back(task, "Thread-1");
    threads.emplace_back(task, "Thread-2");
    threads.emplace_back(task, "Thread-3");
    threads.emplace_back(task, "Thread-4");
    threads.emplace_back(task, "Thread-5");

    for (auto& t : threads) {
        t.join();
    }

    return 0;
}


Output : 
Thread-1 working
Thread-2 working
Thread-3 working
Thread-1 working
Thread-2 working
Thread-3 working
Thread-1 working
Thread-2 working
Thread-3 working
Thread-1 working
Thread-2 working
Thread-3 working
Thread-4 working
Thread-5 working
Thread-4 working
Thread-5 working
Thread-4 working
Thread-5 working
Thread-4 working
Thread-5 working
