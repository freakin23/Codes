#include <bits/stdc++.h>
using namespace std;

void Multisource_BFS(vector<int> adj[], vector<int> visited, vector<int> &dist, queue<int> Q) {
    while (!Q.empty()) {
        int a = Q.front();
        Q.pop();
        for (auto u : adj[a]) {
            if (!visited[u]) {
                dist[u] = dist[a] + 1;
                visited[u] = 1;
                Q.push(u);
            }
        }
    }
}

int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);
    cin.exceptions(ios :: badbit | ios :: failbit);

    int nodes, edges, source_size;
    cin >> nodes >> edges >> source_size;

    vector<int> adj[nodes + 4];
    vector<int> visited(nodes + 4, 0), dist(nodes + 4);
    for (int i = 1; i <= edges; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> source(source_size);
    for (int i = 0; i < source_size; i++) {
        cin >> source[i];
    }

    queue<int> Q;
    for (int i = 0; i < source_size; i++) {
        Q.push(source[i]);
        visited[source[i]] = 1;
    }

    Multisource_BFS(adj, visited, dist, Q);

    for (int i = 1; i <= nodes; i++) {
        cout << dist[i] << " \n"[i == nodes];
    }

    return 0;
}