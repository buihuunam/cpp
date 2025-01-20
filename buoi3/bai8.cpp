#include <iostream>
#include <deque>
#include <string>

using namespace std;

class RequestQueue {
private:
    deque<string> queue;

public:
    void add_request(const string& request) {
        queue.push_back(request);
        cout << "Add request " << request << endl;
    }

    void process_request() {
        if (!queue.empty()) {
            string request = queue.front();
            queue.pop_front();
            cout << "Process request " << request << endl;
        } else {
            cout << "Queue is empty" << endl;
        }
    }

    void display_queue() {
        cout << "Queue: ";
        for (const string& request : queue) {
            cout << request << " ";
        }
        cout << endl;
    }
};

// filepath: /d:/bai_tap_ctdl_gt/cpp/buoi3/bai8.cpp
int main() {
    RequestQueue request_queue;
    request_queue.add_request("Request 1");
    request_queue.add_request("Request 2");
    request_queue.add_request("Request 3");
    request_queue.display_queue();

    request_queue.process_request();
    request_queue.display_queue();

    request_queue.process_request();
    request_queue.display_queue();

    request_queue.process_request();
    request_queue.display_queue();

    return 0;
}