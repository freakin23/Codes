#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);
    cin.exceptions(ios :: badbit | ios :: failbit);

    auto Dijkstra = [&] () -> void {

        const int N = 4E4 + 4;
        vector<pair<int, int>> adj[N];
        vector<bool> used(N, false);
        vector<int> dis(N, INT_MAX);
        priority_queue<pair<int, int>> PQ;

        int nodes, edges;
        cin >> nodes >> edges;
        for (int i = 1; i <= edges; i++) {
            int a, b, w;
            cin >> a >> b >> w;
            adj[a].push_back({b, w});
            adj[b].push_back({a, w});
        }

        int from;
        cin >> from;

        dis[from] = 0; 
        PQ.push({0, from});
        while (!PQ.empty()) {
            int a = PQ.top().second;
            PQ.pop();
            if (used[a]) {
                continue;
            }
            used[a] = true;
            for (auto u : adj[a]) {
                int b = u.first;
                int w = u.second;
                if (dis[a] + w < dis[b]) {
                    dis[b] = dis[a] + w;
                    PQ.push({-dis[b], b});
                }
            }
        }

        for (int i = 1; i <= nodes; i++) {
            cout << dis[i] << " \n"[i == nodes];
        }

    };Dijkstra();

    return 0;
}