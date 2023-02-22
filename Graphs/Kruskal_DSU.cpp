#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);
    cin.exceptions(ios::badbit|ios::failbit);

    auto Kruskal_DSU=[&](){
        int node,edges;
        cin>>node>>edges;
        struct Edge{
            int u,v,weight;
            bool operator<(Edge const &other){
                return weight<other.weight;
            }
        };

        vector<int> parent(node+4),rnk(node+4);

        auto make_set=[&](int v){
            parent[v]=v;
            rnk[v]=0;
        };

        auto find_set=[&](auto find_set,int v){
            if(v==parent[v]){
                return v;
            }
            return parent[v]=find_set(find_set,parent[v]);
        };

        auto union_set=[&](int a,int b){
            a=find_set(find_set,a);
            b=find_set(find_set,b);
            if(a!=b){
                if(rnk[a]<rnk[b]){
                    swap(a,b);
                }
                parent[a]=b;
                if(rnk[a]==rnk[b]){
                    rnk[a]++;
                }
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
        sort(tree.begin(),tree.end());
        for(int i=0;i<node;i++){
            make_set(i);
        }

        for(auto e:tree){
            if(find_set(find_set,e.u)!=find_set(find_set,e.v)){
                cost+=e.weight;
                MST.push_back(e);
                union_set(e.u,e.v);
            }
        }

        cout<<"Cost is: "<<cost<<'\n';
        cout<<"Edges"<<setw(8)<<"Weight"<<'\n';
        for(auto x:MST){
            cout<<x.u<<'-'<<x.v<<setw(6)<<x.weight<<'\n';
        }

    };Kruskal_DSU();

    return 0;
}