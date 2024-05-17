#include <bits/stdc++.h>
using namespace std;

int main() {
    int nodes, edges;
    cin >> nodes >> edges;
    vector<int> Adj[nodes];
    vector<int> deg(nodes, 0);
    for (int i = 1; i <= edges; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        Adj[a].push_back(b);
        deg[b]++;
    }

    queue<int> Q;
    for (int i = 0; i < nodes; i++) {
        if (!deg[i]) {
            Q.push(i);
        }
    }
    vector<int> res;
    while (!Q.empty()) {
        int a = Q.front();
        Q.pop();
        res.push_back(a);
        for (auto u : Adj[a]) {
            deg[u]--;
            if (deg[u] == 0) {
                Q.push(u);
            }
        }
    }

    if ((int)res.size() != nodes) {
        cout << "CYCLE" << '\n';
    } else {
        for (int i = 0; i < nodes; i++) {
            cout << res[i] + 1 << " \n"[i == nodes - 1];
        }
    }
}

/*
Test Case 1
Input
6 7
1 2
2 3
3 6
4 1
4 5
5 2
5 3

Output
4 1 5 2 3 6
*/