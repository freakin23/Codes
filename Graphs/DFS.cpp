#include<bits/stdc++.h>
using namespace std;

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);
    cin.exceptions(ios :: badbit | ios :: failbit);

    auto Depth_First_Search = [&] () {
        const int N = 4E4 + 4;
        vector<int> adj[N];
        vector<bool> used(N, false);

        int nodes, edges;
        cin >> nodes >> edges;
        for (int i = 1; i <= edges; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        auto Dfs = [&] (auto Dfs, int j) {
            if (used[j]) {
                return;
            }
            used[j] = true;
            for (auto u : adj[j]) {
                if (!used[u]) {
                    Dfs(Dfs, u);
                }
            }
        };Dfs(Dfs, 1);

        for (int i = 1; i <= nodes; i++) {
            cout << used[i] << " \n"[i == nodes];
        }

    };Depth_First_Search();
    
    return 0;
}