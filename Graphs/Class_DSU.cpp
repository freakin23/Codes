#include<bits/stdc++.h>
using namespace std;

class Disjoint_Set_Union{
    public:
    vector<int> parents,sizes;
    Disjoint_Set_Union(int n){
        parents.resize(n+4);
        sizes.resize(n+4,1);
        iota(parents.begin(),parents.end(),0);
    }

    int root(int v){
        return (parents[v]==v?v:parents[v]=root(parents[v]));
    }

    bool join(int u,int v){
        int a=root(u);
        int b=root(v);
        if(a==b){
            return false;
        }
        if(sizes[a]<sizes[b]){
            swap(a,b);
        }
        parents[a]=b;
        sizes[b]+=sizes[a];
        return true;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);
    cin.exceptions(ios::badbit|ios::failbit);

    auto Class_DSU=[&]{
        struct Edge{
            int u,v,weight;
            bool operator<(Edge const &other){
                return weight<other.weight;
            }
        };

        int node,edges;
        cin>>node>>edges;
        vector<Edge> tree,MST;
        int cost=0;
        for(int i=1;i<=edges;i++){
            int a,b,c;
            cin>>a>>b>>c;
            tree.push_back({a,b,c});
            tree.push_back({b,a,c});
        }
        sort(tree.begin(),tree.end());
        Disjoint_Set_Union DSU(node+4);
        for(auto e:tree){
            if(DSU.root(e.u)!=DSU.root(e.v)){
                cost+=e.weight;
                MST.push_back(e);
                DSU.join(e.u,e.v);
            }
        }

        cout<<"Cost is: "<<cost<<'\n';
        cout<<"Edges"<<setw(8)<<"Weight"<<'\n';
        for(auto x:MST){
            cout<<x.u<<'-'<<x.v<<setw(6)<<x.weight<<'\n';
        }

    };Class_DSU();

    return 0;
}