// Blog: https://cp-algorithms.com/graph/finding-cycle.html

#include <bits/stdc++.h>

int main() {
    int nodes, edges;
    std::cin >> nodes >> edges;
    std::vector<int> adj[nodes];
    for (int i = 1; i <= edges; i++) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
    }

    std::vector<int> parent(nodes, -1), color(nodes, 0);
    int cycle_start = -1, cycle_end = -1;

    std::function<bool(int)> dfs = [&] (int v) -> bool {
        color[v] = 1;
        for (auto u : adj[v]) {
            if (color[u] == 0) {
                parent[u] = v;
                if (dfs(u)) {
                    return true;
                }
            } else if (color[u] == 1) {
                cycle_end = v;
                cycle_start = u;
                return true;
            }
        }
        color[v] = 2;
        return false;
    };

    auto find_cycle = [&] () {
        for (int v = 0; v < nodes; v++) {
            if (color[v] == 0 and dfs(v)) {
                break;
            }
        }
        if (cycle_start == -1) {
            std::cout << "Acyclic Graph" << '\n';
        } else {
            std::vector<int> cycle;
            cycle.push_back(cycle_start);
            for (int v = cycle_end; v != cycle_start; v = parent[v]) {
                cycle.push_back(v);
            }
            cycle.push_back(cycle_start);
            std::reverse(begin(cycle), end(cycle));
            std::cout << "Cycle Found: ";
            for (int i = 0; i < (int)cycle.size(); i++) {
                std::cout << cycle[i] + 1 << " \n"[i == (int)cycle.size() - 1];
            } 
        }
    };

    find_cycle();
    
    return 0;
}