#include<bits/stdc++.h>
using namespace std;

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);
    cin.exceptions(ios::badbit|ios::failbit);

    auto LCS=[&](){
        string a,b;
        cin>>a>>b;
        vector<vector<int>> dp((int)a.size()+4,vector<int>((int)b.size()+4));

        for(int i=0;i<=(int)a.size();i++){
            for(int j=0;j<(int)b.size();j++){
                if(i==0 or j==0){
                    dp[i][j]=0;
                }
                else if(a[i-1]==b[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }

        cout<<(int)dp[(int)a.size()][(int)b.size()]<<'\n';
    };LCS();

    return 0;
}