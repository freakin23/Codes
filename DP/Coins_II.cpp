#include<bits/stdc++.h>
using namespace std;

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);
    cin.exceptions(ios::badbit|ios::failbit);

    auto Coins_II=[&](){
        int n,target;
        cin>>n>>target;
        vector<int> coins(n),dp(target+4,0),first(target+4);

        for(auto &x:coins){
            cin>>x;
        }

        for(int x=1;x<=target;x++){
            dp[x]=INT_MAX;
            for(auto c:coins){
                if(x-c>=0 and dp[x-c]+1<dp[x]){
                    dp[x]=dp[x-c]+1;
                    first[x]=c;
                }
            }
        }

        cout<<"Total Coins Required: "<<dp[target]<<'\n';
        cout<<"They are: ";
        while(target>0){
            cout<<first[target]<<" ";
            target-=first[target];
        }
        cout<<'\n';
    };Coins_II();

    return 0;
}