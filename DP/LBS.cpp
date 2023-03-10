#include<bits/stdc++.h>
using namespace std;

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);
    cin.exceptions(ios::badbit|ios::failbit);

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

    return 0;
}