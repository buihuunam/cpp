#include <iostream>
#include <queue>
#include <string>
#include <thread>
#include <chrono>
#include <mutex>

using namespace std;

class CommandQueue {
private:
    queue<string> commands;
    mutex mtx;

public:
    void enqueue(const string& command) {
        lock_guard<mutex> lock(mtx);
        commands.push(command);
        cout << "Enqueued command: " << command << endl;
    }

    string dequeue() {
        lock_guard<mutex> lock(mtx);
        if (commands.empty()) {
            return "";
        }
        string command = commands.front();
        commands.pop();
        return command;
    }

    bool is_empty() {
        lock_guard<mutex> lock(mtx);
        return commands.empty();
    }
};

class RobotController {
private:
    CommandQueue& command_queue;

public:
    RobotController(CommandQueue& queue) : command_queue(queue) {}

    void process_commands() {
        while (true) {
            if (!command_queue.is_empty()) {
                string command = command_queue.dequeue();
                if (command == "stop") {
                    cout << "Stopping robot" << endl;
                    break;
                }
                cout << "Processing command: " << command << endl;
            }
            this_thread::sleep_for(chrono::milliseconds(100));
        }
    }
};

void main_simulation() {
    CommandQueue command_queue;
    RobotController controller(command_queue);

    // Add some commands to the queue
    vector<string> commands = {"forward", "backward", "left", "right", "stop"};
    for (const auto& command : commands) {
        command_queue.enqueue(command);
        this_thread::sleep_for(chrono::milliseconds(500)); // wait for half a second
    }

    // Start processing commands in a separate thread
    thread controller_thread(&RobotController::process_commands, &controller);

    // Keep the main thread alive
    this_thread::sleep_for(chrono::seconds(15));

    controller_thread.join();
}

int main() {
    main_simulation();
    return 0;
}