#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);
    cin.exceptions(ios::badbit|ios::failbit);

    auto DFS=[&](){
        int node,edges;
        cin>>node>>edges;
        vector<int> adj[node+4];
        vector<bool> vis(node+4);

        for(int i=1;i<=edges;i++){
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        function<void(int)> Dfs=[&](int j){
            vis[j]=true;
            for(auto u:adj[j]){
                if(!vis[u]){
                    Dfs(u);
                }
            }
        };

        for(int i=1;i<=node;i++){
            if(!vis[i]){
                Dfs(i);
            }
        }

        for(int i=1;i<=node;i++){
            cout<<vis[i]<<" \n"[i==node];
        }

    };DFS();

    return 0;
}