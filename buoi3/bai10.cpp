#include <iostream>
#include <deque>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <random>
#include <chrono>

using namespace std;

class PrintQueue {
private:
    deque<string> queue;
    mutex mtx;
    condition_variable cv;

public:
    void add_data(const string& data) {
        unique_lock<mutex> lock(mtx);
        queue.push_back(data);
        cv.notify_one();
    }

    void print_data() {
        while (true) {
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [this] { return !queue.empty(); });
            string data = queue.front();
            queue.pop_front();
            lock.unlock();
            cout << data << endl;
            this_thread::sleep_for(chrono::milliseconds(100));  // check the queue every 0.1 seconds
        }
    }
};

class Sensor {
private:
    int id;
    PrintQueue& print_queue;
    random_device rd;
    mt19937 gen;
    uniform_int_distribution<> dis;
    uniform_real_distribution<> sleep_dis;

public:
    Sensor(int id, PrintQueue& print_queue)
        : id(id), print_queue(print_queue), gen(rd()), dis(1, 100), sleep_dis(0.5, 2.0) {}

    void send_data() {
        while (true) {
            string data = "Data from sensor " + to_string(id) + ": " + to_string(dis(gen));
            print_queue.add_data(data);
            this_thread::sleep_for(chrono::milliseconds(static_cast<int>(sleep_dis(gen) * 1000)));  // send a random data every 0.5 to 2 seconds
        }
    }
};

int main() {
    PrintQueue print_queue;

    vector<thread> sensor_threads;
    for (int i = 0; i < 5; ++i) {
        sensor_threads.emplace_back(&Sensor::send_data, Sensor(i, print_queue));
    }

    thread print_thread(&PrintQueue::print_data, &print_queue);

    for (auto& thread : sensor_threads) {
        thread.join();
    }

    print_thread.join();

    return 0;
}