#include<bits/stdc++.h>
using namespace std;


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);
    cin.exceptions(ios::badbit|ios::failbit);

    auto Coins_I=[&](){
        int n,target;
        cin>>n>>target;
        vector<int> coins(n),dp(target+4,0);
        for(auto &x:coins){
            cin>>x;
        }

        for(int x=1;x<=target;x++){
            dp[x]=INT_MAX;
            for(auto c:coins){
                if(x-c>=0){
                    dp[x]=min(dp[x],dp[x-c]+1);
                }
            }
        }

        cout<<"Total Coins required: "<<dp[target]<<'\n';
    };Coins_I();

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

    auto Coins_III=[&](){
        const int md=1'000'000'007;
        int n,target;
        cin>>n>>target;
        vector<int> coins(n),count(target+4,0);
        count[0]=1;

        for(auto &x:coins){
            cin>>x;
        }

        for(int x=1;x<=target;x++){
            for(auto c:coins){
                if(x-c>=0){
                    (count[x]+=count[x-c])%=md;
                }
            }
        }

        cout<<"Number of solutions to form target "<<target<<" with permutation: "<<count[target]<<'\n';
    };Coins_III();

    auto Coins_IV=[&](){
        const int md=1'000'000'007;
        int n,target;
        cin>>n>>target;
        vector<int> coins(n);
        vector<vector<int>> dp(n+4,vector<int>(target+4,0));

        for(auto &x:coins){
            cin>>x;
        }

        dp[0][0]=1;
        for(int i=1;i<=n;i++){
            for(int j=0;j<=target;j++){
                dp[i][j]=dp[i-1][j];
                int left=j-coins[i-1];
                if(left>=0){
                    (dp[i][j]+=dp[i][left])%=md;
                }
            }
        }

        cout<<"Number of solutions to form target "<<target<<" without permutation: "<<dp[n][target]<<'\n';        
    };Coins_IV();

    
    auto LIS=[&](){
        int n;
        cin>>n;
        vector<int> dp;

        for(int i=1;i<=n;i++){
            int x;
            cin>>x;
            auto it=lower_bound(dp.begin(),dp.end(),x);
            if(it==dp.end()){
                dp.push_back(x);
            }
            else{
                *it=x;
            }
        }
        cout<<(int)dp.size();
    };LIS();

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

    auto Knapsack=[&](){
        int n,x;
        cin>>n>>x;
        vector<int> arr(n),price(n);
        vector<vector<int>> dp(n+4,vector<int>(x+4,0));

        for(auto &x:arr){
            cin>>x;
        }
        for(auto &x:price){
            cin>>x;
        }

        for(int i=1;i<=n;i++){
            for(int j=0;j<=x;j++){
                dp[i][j]=dp[i-1][j];
                int left=j-arr[i-1];
                if(left>=0){
                    dp[i][j]=max(dp[i][j],dp[i-1][left]+price[i-1]);
                }
            }
        }

        cout<<(int)dp[n][x]<<'\n';
    };Knapsack(); 

    auto Cutting_Rod=[&](){
        int n;
        cin>>n;
        vector<int> price(n),dp(n+4,0);
        for(auto &x:price){
            cin>>x;
        }

        for(int i=1;i<=n;i++){
            int max_val=INT_MIN;
            for(int j=0;j<i;j++){
                max_val=max(max_val,price[j]+dp[i-j-1]);
            }
            dp[i]=max_val;
        }

        cout<<(int)dp[n]<<'\n';
    };Cutting_Rod();

    auto Edit_Distance=[&](){
        string a,b;
        cin>>a>>b;
        vector<vector<int>> dp((int)a.size()+4,vector<int>((int)b.size()+4));

        for(int i=0;i<=(int)a.size();i++){
            for(int j=0;j<(int)b.size();j++){
                if(i==0){
                    dp[i][j]=j;
                }
                else if(j==0){
                    dp[i][j]=i;
                }
                else if(a[i-1]==b[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                }
                else{
                    dp[i][j]=1+min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]});
                }
            }
        }

        cout<<(int)dp[(int)a.size()][(int)b.size()]<<'\n';
    };Edit_Distance();

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

    auto LBS=[&](){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(auto &x:arr){
            cin>>x;
        }

        vector<int> LIS(n+4,1),LDS(n+4,1);

        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(arr[j]<arr[i] and LIS[i]<LIS[j]+1){
                    LIS[i]=LIS[j]+1;
                }
            }
        }

        for(int i=n-2;i>=0;i--){
            for(int j=n-1;j>i;j--){
                if(arr[i]>arr[j] and LDS[i]<LDS[j]+1){
                    LDS[i]=LDS[j]+1;
                }
            }
        }

        int res=LIS[0]+LDS[0]-1;
        for(int i=1;i<n;i++){
            res=max(res,LIS[i]+LDS[i]-1);
        }

        cout<<res<<'\n';
    };LBS();

    auto LPS=[&](){
        string st;
        cin>>st;
        vector<vector<bool>> dp((int)st.size()+4,vector<bool>((int)st.size()+4,false));
        int res=1;

        for(int i=0;i<(int)st.size();i++){
            dp[i][i]=true;
        }

        int start=0;
        for(int i=0;i<(int)st.size()-1;i++){
            if(st[i]==st[i+1]){
                dp[i][i+1]=true;
                start=i;
                res=2;
            }
        }

        for(int k=3;k<=(int)st.size();k++){
            for(int i=0;i<(int)st.size()-k+1;i++){
                int j=i+k-1;

                if(dp[i+1][j-1] and st[i]==st[j]){
                    dp[i][j]=true;

                    if(k>res){
                        start=i;
                        res=k;
                    }
                }
            }
        }

        cout<<"Longest Palindrome Substring is: "<<st.substr(start,res)<<'\n';
    };LPS();

    auto Tiling=[&](){  //3xn board with 2x1 Dominoes
        int n;
        cin>>n;

        vector<int> a(n+1),b(n+1);
        a[0]=1,a[1]=0,b[0]=0,b[1]=1;

        for(int i=2;i<=n;i++){
            a[i]=a[i-2]+2*b[i-1];
            b[i]=a[i-1]+b[i-2];
        }

        cout<<(int)a[n]<<'\n';
    };Tiling();

    return 0;

}