#include<bits/stdc++.h>
using namespace std;

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);
    cin.exceptions(ios::badbit|ios::failbit);

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

    return 0;
}