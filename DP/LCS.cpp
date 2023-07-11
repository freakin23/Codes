#include<bits/stdc++.h>
using namespace std;

int main() {
    
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);
    cin.exceptions(ios :: badbit | ios :: failbit);

    auto Longest_Common_Subsequence = [&] () {
        string s, t;
        cin >> s >> t;
        int a = (int)s.size();
        int b = (int)t.size();
        vector<vector<int>> dp(a + 4, vector<int> (b + 4, 0));

        for (int i = 0; i <= a; i++) {
            for (int j = 0; j <= b; j++) {
                if (i == 0 or j == 0) {
                    dp[i][j] = 0;
                }
                else if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else {
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][ j]);
                }
            }
        }
        cout << dp[a][b] << '\n';
    };Longest_Common_Subsequence();
    
    return 0;
}