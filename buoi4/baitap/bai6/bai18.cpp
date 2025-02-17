#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>
using namespace std;

struct State {
    vector<int> board;
    int steps;
    
    State(vector<int> b, int s) : board(b), steps(s) {}
};

vector<int> rotateLeft(const vector<int>& state) {
    return {state[3], state[0], state[2], state[4], state[1], state[5]};
}

vector<int> rotateRight(const vector<int>& state) {
    return {state[0], state[4], state[1], state[3], state[5], state[2]};
}

int minMoves(vector<int> start, vector<int> target) {
    if (start == target) return 0;
    
    queue<State> q;
    unordered_set<string> visited;
    
    auto vecToStr = [](const vector<int>& v) {
        string res;
        for (int num : v) res += to_string(num) + ",";
        return res;
    };
    
    q.push(State(start, 0));
    visited.insert(vecToStr(start));
    
    while (!q.empty()) {
        State current = q.front(); q.pop();
        
        vector<int> leftRot = rotateLeft(current.board);
        vector<int> rightRot = rotateRight(current.board);
        
        for (auto& newState : {leftRot, rightRot}) {
            if (newState == target) return current.steps + 1;
            string newStr = vecToStr(newState);
            if (visited.find(newStr) == visited.end()) {
                visited.insert(newStr);
                q.push(State(newState, current.steps + 1));
            }
        }
    }
    
    return -1; // Không thể đạt được trạng thái đích (không xảy ra)
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        vector<int> start(6), target(6);
        for (int i = 0; i < 6; ++i) cin >> start[i];
        for (int i = 0; i < 6; ++i) cin >> target[i];
        
        cout << minMoves(start, target) << endl;
    }
    
    return 0;
}
