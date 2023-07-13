#include<bits/stdc++.h>
using namespace std;

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);
    cin.exceptions(ios :: badbit | ios :: failbit);

    auto Kruskal_max = [&] () -> void {

        struct Edge {
            int u, v, weight;
            bool operator < (Edge const &other) {
                return weight > other.weight;
            }
        };

        vector<Edge> tree, MST;
        int cost = 0, nodes, edges;
        cin >> nodes >> edges;
        for (int i = 1; i <= edges; i++) {
            int a, b, w;
            cin >> a >> b >> w;
            tree.push_back({a, b, w});
            tree.push_back({b, a, w});
        }

        sort(begin(tree), end(tree));
        vector<int> tree_id(nodes + 4, 0);
        iota(begin(tree_id), end(tree_id), 0);

        for (auto e : tree) {
            if (tree_id[e.u] != tree_id[e.v]) {
                cost += e.weight;
                MST.push_back(e);

                int old_id = tree_id[e.u], new_id = tree_id[e.v];
                for (int i = 1; i <= nodes; i++) {
                    if (tree_id[i] == old_id) {
                        tree_id[i] = new_id;
                    }
                }
            }
        }

        cout << "Cost: " << cost << '\n';
        cout << "Edge" << setw(8) << "Weight" << '\n';
        for (auto e : MST) {
            cout << e.u << '-' << e.v << setw(6) << e.weight << '\n';
        }
        
    };Kruskal_max();

    return 0;
}