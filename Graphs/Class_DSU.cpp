#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);
    cin.exceptions(ios :: badbit | ios :: failbit);

    auto Class_DSU = [&] () -> void {

        class DSU {
            public:
                vector<int> parents,sizes;

                DSU(int n) {
                    parents.resize(n + 4);
                    sizes.resize(n + 4, 1);
                    iota(begin(parents), end(parents), 0);
                }

                int root(int v) {
                    if (v == parents[v]) {
                        return v;
                    }
                    return parents[v] = root(parents[v]);
                }

                bool unite(int a, int b) {
                    a = root(a);
                    b = root(b);

                    if (a == b) {
                        return false;
                    }

                    if (sizes[a] > sizes[b]) {
                        swap(a, b);
                    }
                    parents[a] = b;
                    sizes[b] += sizes[a];
                    return true;
                }

        };

        struct Edge {
            int u, v, weight;
            bool operator < (Edge const &other) {
                return weight < other.weight;
            }
        };

        int nodes, edges, cost = 0;
        cin >> nodes >> edges;
        vector<Edge> tree, MST;

        for (int i = 1; i <= edges; i++) {
            int a, b, w;
            cin >> a >> b >> w;
            tree.push_back({a, b, w});
            tree.push_back({b, a, w});
        }

        sort(begin(tree), end(tree));
        DSU D(nodes);
        
        for (auto e :  tree) {
            if (D.root(e.u) != D.root(e.v)) {
                cost += e.weight;
                MST.push_back(e);
                D.unite(e.u, e.v);
            }
        }

        cout << "Cost: " << cost << '\n';
        cout << "Edges" << setw(8) << "Weight" << '\n';
        for (auto e : MST) {
            cout << e.u << '-' << e.v << setw(6) << e.weight << '\n';
        }

    };Class_DSU();

    return 0;
}