//Topological sort
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int V, E;

    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    vector<vector<int>> adj(V);
    vector<int> indegree(V, 0);

    cout << "Enter edges (u v) meaning u -> v:\n";

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        indegree[v]++;   // calculate indegree
    }

    queue<int> q;

    // Push vertices with indegree 0
    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0)
            q.push(i);
    }

    cout << "Topological Order: ";

    int count = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        cout << u << " ";
        count++;

        for (int v : adj[u]) {
            indegree[v]--;

            if (indegree[v] == 0)
                q.push(v);
        }
    }

    // Cycle detection
    if (count != V)
        cout << "\nGraph contains a cycle. Topological sort not possible.";

    return 0;
}
