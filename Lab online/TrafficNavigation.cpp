#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    const int maxNode = 100;
    int adj[maxNode][maxNode] = {0};

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    int visited[maxNode] = {0};
    int parent[maxNode];
    for (int i = 0; i < maxNode; i++) {
        parent[i] = -1;
    }

    int source, destination;
    cin >> source >> destination;
    if (source == destination) {
        cout << "Shortest path length: 0" << endl;
        cout << "Path: " << source << endl;
        return 0;
    }

    queue<int> q;
    q.push(source);
    visited[source] = 1;

    bool flag = false;
    while (!q.empty()) {
        int current = q.front();
        q.pop();

        if (current == destination) {
            flag = true;
            break;
        }

        for (int i = 1; i <= n; i++) {
            if (adj[current][i] == 1 && !visited[i]) {
                visited[i] = 1;
                parent[i] = current;
                q.push(i);
            }
        }
    }

    if (!flag) {
        cout << "Path does not exist" << endl;
        return 0;
    }
    int path[maxNode];
    int k = 0;
    int current = destination;

    while (current != -1) {
        path[k++] = current;
        current = parent[current];
    }

    cout << "Shortest path length: " << k - 1 << endl;
    cout << "Path: ";
    for (int i = k - 1; i >= 0; i--) {
        cout << path[i] << " ";
    }
    cout << endl;

    return 0;
}

// Input
// 6 7
// 1 2
// 1 3
// 2 4
// 3 4
// 4 5
// 5 6
// 6 3
// 1 6
// Output
// Shortest path length: 2
//Path: 1 3 6






