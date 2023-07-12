#include<bits/stdc++.h>
using namespace std;

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);
    cin.exceptions(ios :: badbit | ios :: failbit);

    auto Breadth_First_Search = [&] () {
        
        const int N = 4E4 + 4;
        vector<int> adj[N];
        vector<bool> used(N, false);
        vector<int> dis(N + 4, 0);
        queue<int> Q;
        int nodes, edges;
        cin >> nodes >> edges;

        for (int i = 1; i <= edges; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        function<void(int)> Bfs = [&] (int j) -> void {
            dis[j] = 0;
            Q.push(j);
            while (!Q.empty()) {
                int a = Q.front();
                Q.pop();
                for (auto u : adj[a]) {
                    if (!used[u]) {
                        used[u] = true;
                        dis[u] = dis[a] + 1;
                        Q.push(u);
                    }
                }
            }
        };Bfs(1);

        for (int i = 1; i <= nodes; i++) {
            cout << dis[i] << " \n"[i == nodes];
        }

    };Breadth_First_Search();

    return 0;
}