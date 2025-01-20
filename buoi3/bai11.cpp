#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

class Robot {
private:
    vector<int> position;
    char direction;
    stack<string> history;

public:
    Robot() : position({0, 0}), direction('N') {}

    void move_forward() {
        if (direction == 'N') {
            position[1] += 1;
        } else if (direction == 'E') {
            position[0] += 1;
        } else if (direction == 'S') {
            position[1] -= 1;
        } else if (direction == 'W') {
            position[0] -= 1;
        }
        history.push("forward");
        cout << "Moved forward to [" << position[0] << ", " << position[1] << "], facing " << direction << endl;
    }

    void move_backward() {
        if (direction == 'N') {
            position[1] -= 1;
        } else if (direction == 'E') {
            position[0] -= 1;
        } else if (direction == 'S') {
            position[1] += 1;
        } else if (direction == 'W') {
            position[0] += 1;
        }
        history.push("backward");
        cout << "Moved backward to [" << position[0] << ", " << position[1] << "], facing " << direction << endl;
    }

    void turn_left() {
        string dirs = "NESW";
        size_t idx = dirs.find(direction);
        direction = dirs[(idx + 1) % 4];
        history.push("left");
        cout << "Turned left to face " << direction << ", at [" << position[0] << ", " << position[1] << "]" << endl;
    }

    void turn_right() {
        string dirs = "NESW";
        size_t idx = dirs.find(direction);
        direction = dirs[(idx + 1) % 4];
        history.push("right");
        cout << "Turned right to face " << direction << ", at [" << position[0] << ", " << position[1] << "]" << endl;
    }

    void undo() {
        if (history.empty()) {
            cout << "No command to undo" << endl;
            return;
        }
        string last_command = history.top();
        history.pop();
        cout << "Undoing " << last_command << endl;
        if (last_command == "forward") {
            move_backward();
        } else if (last_command == "backward") {
            move_forward();
        } else if (last_command == "left") {
            turn_right();
        } else if (last_command == "right") {
            turn_left();
        }
    }

    void display_status() {
        cout << "Robot is at [" << position[0] << ", " << position[1] << "], facing " << direction << endl;
    }
};

int main() {
    Robot robot;
    robot.move_forward();
    robot.turn_right();
    robot.move_forward();
    robot.turn_left();
    robot.move_backward();
    robot.display_status();

    cout << "\nUndoing last command" << endl;
    robot.undo();
    robot.undo();
    robot.display_status();

    return 0;
}