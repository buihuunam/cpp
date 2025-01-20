#include <iostream>
#include <deque>

using namespace std;

class Queue {
private:
    deque<int> elements;

public:
    void enqueue(int element) {
        elements.push_back(element);
        cout << "Enqueue " << element << endl;
    }

    int dequeue() {
        if (!is_empty()) {
            int element = elements.front();
            elements.pop_front();
            cout << "Dequeue " << element << endl;
            return element;
        } else {
            cout << "Queue is empty" << endl;
            return -1; // Return a sentinel value indicating the queue is empty
        }
    }

    bool is_empty() {
        return elements.empty();
    }

    size_t size() {
        return elements.size();
    }

    void display_all() {
        cout << "Queue: ";
        for (int element : elements) {
            cout << element << " ";
        }
        cout << endl;
    }
};

// filepath: /d:/bai_tap_ctdl_gt/cpp/buoi3/bai6.cpp
int main() {
    Queue queue;
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.display_all();

    int front_item = queue.dequeue();
    cout << "Front item: " << front_item << endl; // Use the front_item variable
    cout << "empty queue: " << queue.is_empty() << endl;

    while (!queue.is_empty()) {
        queue.dequeue();
    }

    cout << "empty queue: " << queue.is_empty() << endl;

    return 0;
}