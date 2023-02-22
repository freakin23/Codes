#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);
    cin.exceptions(ios::badbit|ios::failbit);

    auto BFS=[&](){
        int node,edges;
        cin>>node>>edges;
        vector<int> adj[node+4],dst(node+4);
        vector<bool> used(node+4);
        queue<int> q;

        for(int i=1;i<=edges;i++){
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int from;
        cin>>from;

        auto Bfs=[&](int j){
            dst[j]=0;
            q.push(j);

            while(!q.empty()){
                int s=q.front();
                q.pop();
                for(auto u:adj[s]){
                    if(!used[u]){
                        used[u]=true;
                        dst[u]=dst[s]+1;
                        q.push(u);
                    }
                }
            }

            for(int i=1;i<=node;i++){
                cout<<dst[i]<<" \n"[i==node];
            }
        };Bfs(from);

    };BFS();

    return 0;
}