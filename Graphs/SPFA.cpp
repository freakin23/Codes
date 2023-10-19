#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(0);
	cin.exceptions(ios :: badbit | ios :: failbit);

	int nodes, edges;
	cin >> nodes >> edges;
	vector<pair<int, int>> adj[nodes + 1];
	vector<int> dis(nodes, INT_MAX);

	for (int i = 1; i <= edges; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		u -= 1, v -= 1;
		adj[u].push_back({v, w});
	}

	auto SPFA = [&] (int p ) {
		vector<int> Cnt(nodes, 0);
		vector<bool> inqueue(nodes, false);
		queue<int> Q;

		dis[p] = 0;
		Q.push(p);
		inqueue[p] = true;
		while (!Q.empty()) {
			int v = Q.front();
			Q.pop();
			inqueue[v] = false;

			for (auto node : adj[v]) {
				int to = node.first;
				int len = node.second;

				if (dis[v] + len < dis[to]) {
					dis[to] = dis[v] + len;
					if (!inqueue[to]) {
						Q.push(to);
						inqueue[to] = true;
						Cnt[to] += 1;
						if (Cnt[to] > nodes) {
							return false; // Negative Cycle Detected
						}
					}
				}
			}
		}
		return true;
	};

	if (SPFA(0)) {
		for (int i = 0; i < nodes; i++) {
			cout << dis[i] << " \n"[i == nodes - 1];
		}
	}
	else {
		cout << "Negative Cycle Detected." << '\n';
	}

	return 0;
}