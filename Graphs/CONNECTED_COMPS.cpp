#include<bits/stdc++.h>
using namespace std;

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);
    cin.exceptions(ios :: badbit | ios :: failbit);

    auto Connected_Componets = [&] () {

        const int N = 4E4 + 4;
        vector<int> adj[N];
        vector<bool> used(N, false);
        vector<vector<int>> comps;

        int nodes, edges;
        cin >> nodes >> edges;
        for (int i = 1; i <= edges; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        function<void(vector<int> &, int)> Dfs = [&] (vector<int> &c, int j) {
            used[j] = true;
            c.push_back(j);
            for (auto u : adj[j]) {
                if (!used[u]) {
                    Dfs(c, u);
                }
            }
        };

        for (int i = 1; i <= nodes; i++) {
            if (!used[i]) {
                vector<int> c;
                Dfs(c, i);
                comps.push_back(c);
                c.clear();
            }
        }

        cout << (int)comps.size() << '\n';
        for (auto x : comps) {
            for (auto y : x) {
                cout << y << " ";
            }
            cout << '\n';
        }
    };Connected_Componets();

    return 0;
}