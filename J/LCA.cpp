#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 4, LOG = 25;
vector<vector<int>> up(N, vector<int>(LOG));
vector<int> depth(N);
vector<int> adj[N];

void dfs(int u, int par) {
    for (auto v : adj[u]) {
        if (v == par) {
            continue;
        }
        depth[v] = depth[u] + 1;
        up[v][0] = u;
        dfs(v, u);
    }
}
bool ancestor(int u, int v) {
    if (depth[v] > depth[u]) {
        return false;
    }
    int k = depth[u] - depth[v];
    for (int j = LOG - 1; j >= 0; --j) {
        if (k & (1 << j)) {
            u = up[u][j];
        }
    }
    return (u == v);
}

int LCA(int u, int v) {
    if (depth[u] < depth[v]) {
        swap(u, v);
    }
    int k = depth[u] - depth[v];
    for (int j = LOG - 1; j >= 0; --j) {
        if (k & (1 << j)) {
            u = up[u][j];
        }
    }
    if (u == v) {
        return u;
    }
    for (int j = LOG - 1; j >= 0; --j) {
        if (up[u][j] != up[v][j]) {
            u = up[u][j];
            v = up[v][j];
        }
    }
    return up[u][0];
}

int dist(int u, int v) {
    int lca = LCA(u, v);
    return depth[u] + depth[v] - 2 * depth[lca];
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(0, 0);
    for (int j = 1; j < LOG; j++) {
        for (int i = 0; i < n; i++) {
            up[i][j] = up[up[i][j - 1]][j - 1];
        }
    }

    int q;
    cin >> q;
    while (q--) {
        int root, u, v;
        cin >> root >> u >> v;
        root--, u--, v--;
        int lca = LCA(u, v);

        if (depth[u] < depth[v]) {
            swap(u, v);
        }
        if (lca == v) {
            if (ancestor(root, u)) {
                cout << u + 1 << '\n';
            } else if (ancestor(u, root) and ancestor(root, v)) {
                cout << root + 1 << '\n';
            } else if (!ancestor(root, v)) {
                cout << v + 1 << '\n';
                continue;
            } else {
                if (dist(LCA(u, root), root) < dist(LCA(v, root), root)) {
                    cout << LCA(u, root) + 1 << '\n';
                } else {
                    cout << LCA(v, root) + 1 << '\n';
                }
            }
            continue;
        }

        if (!ancestor(root, lca)) {
            cout << lca + 1 << '\n';
            continue;
        }
        if (ancestor(root, v)) {
            cout << v + 1 << '\n';
            continue;
        }
        if (ancestor(root, u)) {
            cout << u + 1 << '\n';
            continue;
        }
        if (ancestor(v, root) or ancestor(u, root)) {
            cout << root + 1 << '\n';
            continue;
        }
        if (dist(LCA(u, root), root) < dist(LCA(v, root), root)) {
            cout << LCA(u, root) + 1 << '\n';
        } else {
            cout << LCA(v, root) + 1 << '\n';
        }
    }
}

/*
Test Case:
9
4 6
6 7
4 2
6 3
3 8
3 5
2 1
2 9
2
4 6 2
4 6 5

Output:
4
6
*/
