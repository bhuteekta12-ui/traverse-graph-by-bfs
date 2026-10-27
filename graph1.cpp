#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void BFS(int start, vector<int> adj[], vector<bool>& visited) {
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        cout << node << " ";

        for (int neighbour : adj[node]) {
            if (!visited[neighbour]) {
                visited[neighbour] = true;
                q.push(neighbour);
            }
        }
    }
}

int main() {
    int vertices, edges;

    cout << "Enter number of vertices: ";
    cin >> vertices;

    cout << "Enter number of edges: ";
    cin >> edges;

    vector<int> adj[vertices];

    cout << "Enter edges (u v):" << endl;
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> visited(vertices, false);

    int start;
    cout << "Enter starting vertex: ";
    cin >> start;

    cout << "BFS Traversal: ";
    BFS(start, adj, visited);

    return 0;
}