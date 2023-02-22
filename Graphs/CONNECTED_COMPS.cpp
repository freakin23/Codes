#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);
    cin.exceptions(ios::badbit|ios::failbit);

    auto CONNECTED_COMPS=[&](){
        int node,edges;
        cin>>node>>edges;
        vector<int> adj[node+4];
        vector<bool> used(node+4);
        vector<vector<int>> connect_comps;
        for(int i=1;i<=edges;i++){
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        function<void(int,vector<int>&)> Dfs=[&](int j,vector<int> &connect){
            used[j]=true;
            connect.push_back(j);
            for(auto u:adj[j]){
                if(!used[u]){
                    Dfs(u,connect);
                }
            }
        };

        for(int i=1;i<=node;i++){
            if(!used[i]){
                vector<int> connect;
                Dfs(i,connect);
                connect_comps.push_back(connect);
            }
        }
        for(int i=0;i<(int)connect_comps.size();i++){
            for(int j=0;j<(int)connect_comps[i].size();j++){
                cout<<connect_comps[i][j]<<" \n"[j==(int)connect_comps[i].size()-1];
            }
        }
    };CONNECTED_COMPS();

    return 0;
}