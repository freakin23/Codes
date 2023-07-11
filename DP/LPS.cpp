#include<bits/stdc++.h>
using namespace std;

int main() {
    
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);
    cin.exceptions(ios :: badbit | ios :: failbit);

    auto Longest_Palindromic_Substring = [&] () {
        string st;
        cin >> st;
        int n = (int)st.size();
        vector<vector<bool>> dp(n + 4, vector<bool> (n + 4, false));

        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }

        int maxLen = 1;
        int start = 0;
        for (int i = 0; i + 1 < n; i++) {
            if (st[i] == st[i + 1]) {
                start = i;
                dp[i][i + 1] = true;
                maxLen = 2;
            }
        }

        for (int k = 3; k <= n; k++) {
            for (int i = 0; i < n - k + 1; i++) {
                int j = i + k - 1;

                if (dp[i + 1][j - 1] and st[i] == st[j]) {
                    dp[i][j] = true;

                    if (k > maxLen) {
                        maxLen = k;
                        start = i;
                    }
                }
            }
        }
        cout << "Longest Palindromic Substring is: " << st.substr(start, maxLen) << '\n';
    };Longest_Palindromic_Substring();
    
    return 0;
}