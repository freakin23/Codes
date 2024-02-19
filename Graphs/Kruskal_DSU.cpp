#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);
    cin.exceptions(ios :: badbit | ios :: failbit);

    auto Kruskal_DSU = [&] () -> void {

        struct Edge {
            int u, v, weight;
            bool operator < (Edge const &other) {
                return weight < other.weight;
            }
        };

        int nodes, edges, cost = 0;
        cin >> nodes >> edges;
        vector<int> parent(nodes + 4, 0), rnk(nodes + 4, 0);

        auto make_set = [&] (int v) -> void {
            parent[v] = v;
            rnk[v] = 0;
        };

        auto find_set = [&] (auto find_set, int v) -> int {
            if (v == parent[v]) {
                return v;
            }
            return parent[v] = find_set(find_set, parent[v]);
        };

        auto union_set = [&] (int a, int b) -> void {
            a = find_set(find_set, a);
            b = find_set(find_set, b);

            if (a != b) {
                if (rnk[a] < rnk[b]) {
                    swap(a, b);
                }
                parent[b] = a;
                if (rnk[a] == rnk[b]) {
                    rnk[a]++;
                }
            }
        };

        vector<Edge> tree, MST;
        for (int i = 1; i <= edges; i++) {
            int a, b, w;
            cin >> a >> b >> w;
            tree.push_back({a, b, w});
            tree.push_back({b, a, w});
        }        

        sort(begin(tree), end(tree));

        for (int i = 0; i <= nodes; i++) {
            make_set(i);
        }

        for (auto e : tree) {
            if (find_set(find_set, e.u) != find_set(find_set, e.v)) {
                cost += e.weight;
                MST.push_back(e);
                union_set(e.u, e.v);
            }
        }

        cout << "Cost: " << cost << '\n';
        cout << "Edge" << setw(8) << "Weight" << '\n';
        for (auto e : MST) {
            cout << e.u << '-' << e.v << setw(6) << e.weight << '\n';
        }

    };Kruskal_DSU();

    return 0;
}