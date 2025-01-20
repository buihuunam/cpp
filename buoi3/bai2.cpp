#include <iostream>
#include <deque>
using namespace std;

class Stack {
private:
    deque<int> elements;

public:
    void push(int item) {
        elements.push_back(item);
        cout << "Pushed '" << item << "' to the stack" << endl;
    }

    void pop() {
        if (!elements.empty()) {
            int item = elements.back();
            elements.pop_back();
            cout << "Popped '" << item << "' from the stack" << endl;
        } else {
            cout << "Stack is empty" << endl;
        }
    }

    int peek() {
        if (!elements.empty()) {
            return elements.back();
        } else {
            cout << "Stack is empty" << endl;
            return -1; // Return a sentinel value indicating the stack is empty
        }
    }

    bool is_empty() {
        return elements.empty();
    }

    void display() {
        cout << "Stack: ";
        for (int item : elements) {
            cout << item << " ";
        }
        cout << endl;
    }
};

int main() {
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.display();

    int top_item = s.peek();
    cout << "Top item: " << top_item << endl;
    s.pop();
    s.display();

    while (!s.is_empty()) {
        s.pop();
    }
    s.display();

    return 0;
}