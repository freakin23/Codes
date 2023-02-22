#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);
    cin.exceptions(ios::badbit|ios::failbit);

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
    };Floyd_Warshall();

    return 0;
}