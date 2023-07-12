#include<bits/stdc++.h>
using namespace std;

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);
    cin.exceptions(ios :: badbit | ios :: failbit);

    auto Top_Sort_and_Cycle_Detection = [&] () -> void {

        const int N = 4E4 + 4;
        vector<int> adj[N];
        vector<int> used1(N, false), used2(N, false);
        vector<int> top_sort;

        int nodes, edges;
        cin >> nodes >> edges;
        for (int i = 1; i <= edges; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        auto Dfs = [&] (auto Dfs, int j) -> void {

            if (used1[j]) {
                return;
            }

            used1[j] = used2[j] = true;
            for (auto u : adj[j]) {
                if (!used1[u] and !used2[u]) {
                    Dfs(Dfs, u);
                }
                else if (used2[u]) {
                    cout << "Found the Cycle" << '\n';
                    exit(0);
                }
            }

            used2[j] = false;
            top_sort.push_back(j);
        };

        for (int i = 1; i <= nodes; i++) {
            if (!used1[i]) {
                Dfs(Dfs, i);
            }
        }

        reverse(begin(top_sort), end(top_sort));
        for (int i = 0; i < (int)top_sort.size(); i++) {
            cout << top_sort[i] << " \n"[i == (int)top_sort.size() - 1];
        }

    };Top_Sort_and_Cycle_Detection();

    return 0;
}