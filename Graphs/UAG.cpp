// Problem Link: https://cses.fi/problemset/task/1669
// Blog: https://cp-algorithms.com/graph/finding-cycle.html

#include <bits/stdc++.h>
#define i64 long long

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> adj[n];
    for (int i = 0; i < m; i++) {
        int a, b;
        std::cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    std::vector<int> used(n, 0), parent(n, -1);
    int cycle_start = -1, cycle_end = -1;
    
    std::function<bool(int, int)> dfs = [&] (int v, int par) -> bool {
        used[v] = true;
        for (auto u : adj[v]) {
            if (u == par) {
                continue;
            }
            if (used[u]) {
                cycle_end = v;
                cycle_start = u;
                return true;
            }
            parent[u] = v;
            if (dfs(u, parent[u])) {
                return true;
            }
        }
        return false;
    };

    std::function<void()> find_cycle = [&] () {
        for (int i = 0; i < n; i++) {
            if (!used[i] and dfs(i, parent[i])) {
                break;
            }
        }
        if (cycle_start == -1) {
            std::cout << "IMPOSSIBLE" << '\n'; // Acyclic
        } else {
            std::vector<int> cycle;
            cycle.push_back(cycle_start);
            for (int v = cycle_end; v != cycle_start; v = parent[v]) {
                cycle.push_back(v);
            }
            cycle.push_back(cycle_start);
            std::cout << (int)cycle.size() << '\n';
            for (int i = 0; i < (int)cycle.size(); i++) {
                std::cout << cycle[i] + 1 << " \n"[i == (int)cycle.size() - 1];
            }
        }
    };

    find_cycle();
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    std::cin.exceptions(std::ios::badbit|std::ios::failbit);
    int test = 1;
    // std::cin >> test;
    while (test-- > 0) {
        solve();
    }
    return 0;
}
