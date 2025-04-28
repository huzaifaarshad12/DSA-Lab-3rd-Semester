#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_set>
#include <algorithm>

using namespace std;

class ForestRescue {
public:
    ForestRescue(int n) : n(n), adjList(n + 1) {}

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    vector<int> bfs(int start, int person) {
        vector<int> dist(n + 1, -1);
        vector<int> parent(n + 1, -1);
        queue<int> q;
        q.push(start);
        dist[start] = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int neighbor : adjList[node]) {
                if (dist[neighbor] == -1) {
                    dist[neighbor] = dist[node] + 1;
                    parent[neighbor] = node;
                    q.push(neighbor);
                }
            }
        }

        vector<int> path;
        if (dist[person] != -1) {
            for (int at = person; at != -1; at = parent[at]) {
                path.push_back(at);
            }
            reverse(path.begin(), path.end());
        }
        return path;
    }

    bool dfs(int person, int hq) {
        stack<int> s;
        unordered_set<int> visited;
        s.push(person);

        while (!s.empty()) {
            int node = s.top();
            s.pop();

            if (node == hq) return true;

            if (visited.find(node) == visited.end()) {
                visited.insert(node);
                for (int neighbor : adjList[node]) {
                    if (visited.find(neighbor) == visited.end()) {
                        s.push(neighbor);
                    }
                }
            }
        }
        return false;
    }

    int totalClearings() {
        return n;
    }

private:
    int n;
    vector<vector<int>> adjList;
};

int main() {
    int N;
    cin >> N;

    ForestRescue forest(N);

    for (int i = 0; i < N - 1; ++i) {
        int u, v;
        cin >> u >> v;
        forest.addEdge(u, v);
    }

    int start, person, hq;
    cin >> start >> person >> hq;

    vector<int> path = forest.bfs(start, person);
    if (!path.empty()) {
        for (int node : path) {
            cout << node << " ";
        }
        cout << endl;
    } else {
        cout << "No path found" << endl;
    }

    if (forest.dfs(person, hq)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    cout << forest.totalClearings() << endl;

    return 0;
}