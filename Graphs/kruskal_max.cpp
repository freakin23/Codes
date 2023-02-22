#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);
    cin.exceptions(ios::badbit|ios::failbit);

    auto kruskal_max=[&](){
        int node,edges;
        cin>>node>>edges;
        struct Edge{
            int u,v,weight;
            bool operator<(Edge const &other){
                return weight>other.weight;
            }
        };

        vector<Edge> tree,MST;
        int cost=0;
        for(int i=1;i<=edges;i++){
            int a,b,c;
            cin>>a>>b>>c;
            tree.push_back({a,b,c});
            tree.push_back({b,a,c});
        }

        vector<int> tree_id(node+4);
        iota(tree_id.begin(),tree_id.end(),0);
        sort(tree.begin(),tree.end());
        
        for(auto e:tree){
            if(tree_id[e.u]!=tree_id[e.v]){
                cost+=e.weight;
                MST.push_back(e);

                int old_id=tree_id[e.u],new_id=tree_id[e.v];
                for(int i=1;i<=node;i++){
                    if(tree_id[i]==old_id){
                        tree_id[i]=new_id;
                    }
                }
            }
        }
        cout<<"Cost is: "<<cost<<'\n';
        cout<<"Edge"<<setw(8)<<"Weight"<<'\n';
        for(auto x:MST){
            cout<<x.u<<'-'<<x.v<<setw(6)<<x.weight<<'\n';
        }

    };kruskal_max();

    return 0;
}