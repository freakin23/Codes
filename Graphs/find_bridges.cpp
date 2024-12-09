// Blog: https://cp-algorithms.com/graph/bridge-searching.html

#include <bits/stdc++.h>

void is_bridge(int from, int to) {
    std::cout << "Bridge: " << from << " " << to << '\n';
}

int main() {
    int nodes, edges;
    std::cin >> nodes >> edges;
    std::vector<int> adj[nodes];
    for (int i = 0; i < edges; i++) {
        int a, b;
        std::cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int timer = 0;
    std::vector<int> used(nodes, 0), tin(nodes, -1), low(nodes, -1);

    std::function <void(int, int)> Dfs = [&] (int x, int p) {
        used[x] = 1;
        tin[x] = low[x] = timer++;
        bool parent_skipped = false;
        for (int to : adj[x]) {
            if (to == p and !parent_skipped) {
                parent_skipped = true;
                continue;
            }
            if (used[to]) {
                low[x] = std::min(low[x], tin[to]);
            } else {
                Dfs(to, x);
                low[x] = std::min(low[x], low[to]);
                if (low[to] > tin[x]) {
                    is_bridge(x, to);
                }
            }
        }
    };

    for (int i = 0; i < nodes; i++) {
        if (!used[i]) {
            Dfs(i, -1);
        }
    }
    return 0;
}