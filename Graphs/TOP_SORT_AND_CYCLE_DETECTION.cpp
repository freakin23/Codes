#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);
    cin.exceptions(ios::badbit|ios::failbit);

    auto TOP_SORT_AND_CYCLE_DETECTION=[&](){
        int node,edges;
        cin>>node>>edges;
        vector<int> adj[node+4],top_sort;
        vector<bool> used1(node+4),used2(node+4);

        for(int i=1;i<=edges;i++){
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        function<void(int)> Dfs=[&](int j){
            used1[j]=true;
            used2[j]=true;

            for(auto u:adj[j]){
                if(!used1[u] and !used2[u]){
                    Dfs(u);
                }
                else if(used2[u]){
                    cout<<"Found the cycle"<<'\n';
                    exit(0);
                }
            }
            used2[j]=false;
            top_sort.push_back(j);
        };
        for(int i=1;i<=node;i++){
            if(!used1[i]){
                Dfs(i);
            }
        }

        for(int i=1;i<(int)top_sort.size();i++){
            cout<<top_sort[i]<<" \n"[i==(int)top_sort.size()-1];
        }

    };TOP_SORT_AND_CYCLE_DETECTION();

    return 0;
}