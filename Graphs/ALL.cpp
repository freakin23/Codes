#include <bits/stdc++.h>
using namespace std;

int main(){

    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);
    cin.exceptions(ios :: badbit | ios :: failbit);

    auto Depth_First_Search = [&] () -> void {
        const int N = 4E4 + 4;
        vector<int> adj[N];
        vector<bool> used(N, false);

        int nodes, edges;
        cin >> nodes >> edges;

        for (int i = 1; i <= edges; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        auto Dfs = [&] (auto Dfs, int j) -> void {
            if (used[j]) {
                return;
            }
            used[j] = true;
            for (auto u : adj[j]) {
                if (!used[u]) {
                    Dfs(Dfs ,u);
                }
            }
        };Dfs(Dfs ,1);

        for (int i = 1; i <= nodes; i++) {
            cout << used[i] << " \n"[i == nodes];
        }

    };Depth_First_Search();
    
    auto Breadth_First_Search = [&] () -> void{
        
        const int N = 4E4 + 4;
        vector<int> adj[N];
        vector<bool> used(N, false);
        vector<int> dis(N + 4, 0);
        queue<int> Q;
        int nodes, edges;
        cin >> nodes >> edges;

        for (int i = 1; i <= edges; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        function<void(int)> Bfs = [&] (int j) -> void {
            dis[j] = 0;
            Q.push(j);
            while (!Q.empty()) {
                int a = Q.front();
                Q.pop();
                for (auto u : adj[a]) {
                    if (!used[u]) {
                        used[u] = true;
                        dis[u] = dis[a] + 1;
                        Q.push(u);
                    }
                }
            }
        };Bfs(1);

        for (int i = 1; i <= nodes; i++) {
            cout << dis[i] << " \n"[i == nodes];
        }

    };Breadth_First_Search();

    auto Connected_Componets = [&] () -> void {

        const int N = 4E4 + 4;
        vector<int> adj[N];
        vector<bool> used(N, false);
        vector<vector<int>> comps;

        int nodes, edges;
        cin >> nodes >> edges;
        for (int i = 1; i <= edges; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        function<void(vector<int> &, int)> Dfs = [&] (vector<int> &c, int j) -> void {
            used[j] = true;
            c.push_back(j);
            for (auto u : adj[j]) {
                if (!used[u]) {
                    Dfs(c, u);
                }
            }
        };

        for (int i = 1; i <= nodes; i++) {
            if (!used[i]) {
                vector<int> c;
                Dfs(c, i);
                comps.push_back(c);
                c.clear();
            }
        }

        cout << (int)comps.size() << '\n';
        for (auto x : comps) {
            for (auto y : x) {
                cout << y << " ";
            }
            cout << '\n';
        }
    };Connected_Componets();


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


    
    auto Bellman_Ford = [&] () -> void {

        int nodes, edges;
        cin >> nodes >> edges;
        vector<tuple<int, int, int>> G;
        vector<int> dis(nodes + 4, INT_MAX);
        for (int i = 1; i <= edges; i++) {
            int a, b, w;
            cin >> a >> b >> w;
            G.push_back(make_tuple(a, b, w));
        }

        int from;
        cin >> from;
        dis[from] = 0;

        for (int i = 1; i + 1 < nodes; i++) {
            for (auto u : G) {
                int a, b, w;
                tie(a, b, w) = u;
                if (dis[a] + w < dis[b]) {
                    dis[b] = dis[a] + w;
                }
            }
        }

        for (int i = 1; i <= nodes; i++) {
            cout << dis[i] << " \n"[i == nodes];
        }

    };Bellman_Ford();

    auto Dijkstra = [&] () -> void {

        const int N = 4E4 + 4;
        vector<pair<int, int>> adj[N];
        vector<bool> used(N, false);
        vector<int> dis(N, INT_MAX);
        priority_queue<pair<int, int>> PQ;

        int nodes, edges;
        cin >> nodes >> edges;
        for (int i = 1; i <= edges; i++) {
            int a, b, w;
            cin >> a >> b >> w;
            adj[a].push_back({b, w});
            adj[b].push_back({a, w});
        }

        int from;
        cin >> from;

        dis[from] = 0; 
        PQ.push({0, from});
        while (!PQ.empty()) {
            int a = PQ.top().second;
            PQ.pop();
            if (used[a]) {
                continue;
            }
            used[a] = true;
            for (auto u : adj[a]) {
                int b = u.first;
                int w = u.second;
                if (dis[a] + w < dis[b]) {
                    dis[b] = dis[a] + w;
                    PQ.push({-dis[b], b});
                }
            }
        }

        for (int i = 1; i <= nodes; i++) {
            cout << dis[i] << " \n"[i == nodes];
        }

    };Dijkstra();

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

    auto Kruskal_min = [&] () -> void {
        
        struct Edge {
            int u, v, weight;
            bool operator < (Edge const &other) {
                return weight < other.weight;
            }
        };

        vector<Edge> tree, MST;
        int nodes, edges, cost = 0;
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

    };Kruskal_min();

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