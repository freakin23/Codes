#include<bits/stdc++.h>
using namespace std;

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);
    cin.exceptions(ios::badbit|ios::failbit);

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

    return 0;
}