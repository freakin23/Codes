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
    };
    Bellman_Ford();

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
    };
    DIJKSTRA();

    auto Floyd_Warshall=[&](){
        int F_node,F_edges;
        cin>>F_node>>F_edges;

        vector<vector<int>> Floyd(F_node+4,vector<int>(F_node+4,INT_MAX));
        for(int i=1;i<=F_node;i++){
            Floyd[i][i]=0;
        }

        for(int i=1;i<=F_edges;i++){
            int a,b,c;
            cin>>a>>b>>c;
            Floyd[a][b]=min(Floyd[a][b],c);
            Floyd[b][a]=min(Floyd[b][a],c);
        }

        for(int k=1;k<=F_node;k++){
            for(int i=1;i<=F_node;i++){
                for(int j=1;j<=F_node;j++){
                    Floyd[i][j]=min(Floyd[i][j],Floyd[i][k]+Floyd[k][j]);
                }
            }
        }

        for(int i=1;i<=F_node;i++){
            for(int j=1;j<=F_node;j++){
                cout<<Floyd[i][j]<<" ";
            }
            cout<<'\n';
        }
    };
    Floyd_Warshall();

    auto KRUSKAL=[&](){

        int node,edges;
        cin>>node>>edges;

        auto kruskal_min=[&](){
            struct Edge{
                int u,v,weight;
                bool operator<(Edge const &other){
                    return weight<other.weight;
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

        };kruskal_min();


        auto kruskal_max=[&](){
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

        auto Kruskal_DSU=[&](){
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

        auto Class_DSU=[&]{
            struct Edge{
                int u,v,weight;
                bool operator<(Edge const &other){
                    return weight<other.weight;
                }
            };

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

    };KRUSKAL();

    return 0;
    
}