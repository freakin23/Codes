#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);
    cin.exceptions(ios :: badbit | ios :: failbit);

    auto Bellman_Ford = [&] () -> void {

        int nodes, edges;
        cin >> nodes >> edges;
        vector<tuple<int, int, int>> G;
        vector<int> dis(nodes + 4, INT_MAX);
        for (int i = 1; i <= edges; i++) {
            int a, b, w;
            cin >> a >> b >> w;
            G.push_back(make_tuple(a, b, w));
        }

        int from;
        cin >> from;
        dis[from] = 0;

        for (int i = 1; i + 1 < nodes; i++) {
            for (auto u : G) {
                int a, b, w;
                tie(a, b, w) = u;
                if (dis[a] + w < dis[b]) {
                    dis[b] = dis[a] + w;
                }
            }
        }

        for (int i = 1; i <= nodes; i++) {
            cout << dis[i] << " \n"[i == nodes];
        }

    };Bellman_Ford();
    
    return 0;
}