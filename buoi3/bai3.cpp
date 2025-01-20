#include <iostream>
#include <stack>
#include <unordered_set>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

void dfs(unordered_map<char, vector<char>>& graph, char start) {
    stack<char> s;
    unordered_set<char> visited;

    s.push(start);

    while (!s.empty()) {
        char vertex = s.top();
        s.pop();

        if (visited.find(vertex) == visited.end()) {
            cout << vertex << " ";
            visited.insert(vertex);

            // Add all neighbors of vertex to stack
            vector<char> neighbors = graph[vertex];
            reverse(neighbors.begin(), neighbors.end());
            for (char neighbor : neighbors) {
                s.push(neighbor);
            }
            cout << "push neighbor node '" << vertex << "' into stack: ";
            for (char neighbor : neighbors) {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }
}

int main() {
    unordered_map<char, vector<char>> graph = {
        {'A', {'B', 'C'}},
        {'B', {'D', 'E'}},
        {'C', {'F'}},
        {'D', {}},
        {'E', {'F'}},
        {'F', {}}
    };

    cout << "DFS traversal starting from vertex 'A':" << endl;
    dfs(graph, 'A');

    return 0;
}