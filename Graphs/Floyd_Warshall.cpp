#include<bits/stdc++.h>
using namespace std;

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);
    cin.exceptions(ios :: badbit | ios :: failbit);

    auto Floyd_Warshall = [&] () -> void {

        int nodes, edges;
        cin >> nodes >> edges;
        vector<vector<long>> adj(nodes + 1, vector<long> (nodes + 1, INT_MAX));

        for (int i = 1; i <= nodes; i++) {
            adj[i][i] = 0;
        }
        for (int i = 1; i <= edges; i++) {
            long a, b, w;
            cin >> a >> b >> w;
            adj[a][b] = min(adj[a][b], w);
            adj[b][a] = min(adj[b][a], w);
        }

        for (int k = 1; k <= nodes; k++) {
            for (int i = 1; i <= nodes; i++) {
                for (int j = 1; j <= nodes; j++) {
                    adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
                }
            }
        }

        for (int i = 1; i <= nodes; i++) {
            for (int j = 1; j <= nodes; j++) {
                cout << adj[i][j] << " \n"[j == nodes];
            }
        }

    };Floyd_Warshall();

    return 0;
}