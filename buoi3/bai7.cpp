#include <iostream>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <vector>

using namespace std;

void bfs(const unordered_map<char, vector<char>>& graph, char start) {
    queue<char> q;
    unordered_set<char> visited;

    q.push(start);

    while (!q.empty()) {
        char vertex = q.front();
        q.pop();

        if (visited.find(vertex) == visited.end()) {
            cout << "Visit " << vertex << endl;
            visited.insert(vertex);

            for (char neighbor : graph.at(vertex)) {
                if (visited.find(neighbor) == visited.end()) {
                    q.push(neighbor);
                }
            }
            cout << "Add '" << vertex << "' to visited set: ";
            for (char neighbor : graph.at(vertex)) {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }
}

int main() {
    unordered_map<char, vector<char>> graph = {
        {'A', {'B', 'C'}},
        {'B', {'A', 'D', 'E'}},
        {'C', {'A', 'F'}},
        {'D', {'B'}},
        {'E', {'B', 'F'}},
        {'F', {'C', 'E'}}
    };

    cout << "BFS traversal starting from vertex 'A':" << endl;
    bfs(graph, 'A');

    return 0;
}