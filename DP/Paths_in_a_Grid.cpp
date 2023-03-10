#include<bits/stdc++.h>
using namespace std;

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);
    cin.exceptions(ios::badbit|ios::failbit);

    auto Paths_in_a_Grid=[&](){
        int n;
        cin>>n;
        vector<vector<int>> matrix(n+1,vector<int>(n+1,0)),dp(n+1,vector<int>(n+1,0));
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cin>>matrix[i][j];
            }
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dp[i][j]=max(dp[i-1][j],dp[i][j-1])+matrix[i][j];
            }
        }

        cout<<(int)dp[n][n]<<'\n';
    };Paths_in_a_Grid();

    return 0;
}