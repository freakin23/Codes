#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);
    cin.exceptions(ios::badbit|ios::failbit);

    auto Bellman_Ford=[&](){
        int node,edges;
        cin>>node>>edges;
        vector<tuple<int,int,int>> Graphs;
        for(int i=1;i<=edges;i++){
            int u,v,w;
            cin>>u>>v>>w;
            Graphs.push_back(make_tuple(u,v,w));
        }
        vector<int> dst(node+1,INT_MAX);
        int from;
        cin>>from;
        dst[from]=0;

        for(int i=1;i<node;i++){
            for(auto x:Graphs){
                int a,b,w;
                tie(a,b,w)=x;
                dst[b]=min(dst[b],dst[a]+w);
            }
        }

        for(int i=1;i<=node;i++){
            cout<<dst[i]<<" \n"[i==node];
        }
    };Bellman_Ford();

    return 0;
}