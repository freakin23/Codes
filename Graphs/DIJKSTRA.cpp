#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);
    cin.exceptions(ios::badbit|ios::failbit);

    auto DIJKSTRA=[&](){
        int node,edges;
        cin>>node>>edges;
        vector<pair<int,int>> D_adj[node+4];
        vector<int> dst(node+4,INT_MAX),visited(node+4,0);
        priority_queue<pair<int,int>> pq;

        for(int i=1;i<=edges;i++){
            int a,b,w;
            cin>>a>>b>>w;
            D_adj[a].push_back({b,w});
            D_adj[b].push_back({a,w});
        }

        int from;
        cin>>from;

        auto Dijkstra=[&](){
            dst[from]=0;
            pq.push({0,from});

            while(!pq.empty()){
                int a=pq.top().second;
                pq.pop();
                
                if(visited[a]){
                    continue;
                }
                visited[a]=true;
                for(auto u:D_adj[a]){
                    int b=u.first;
                    int w=u.second;

                    if(dst[a]+w<dst[b]){
                        dst[b]=dst[a]+w;
                        pq.push({-dst[b],b});
                    }
                }
            }
        };
        Dijkstra();

        for(int i=1;i<=node;i++){
            cout<<dst[i]<<" \n"[i==node];
        }
    };DIJKSTRA();

    return 0;
}