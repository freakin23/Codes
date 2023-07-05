#include<bits/stdc++.h>
using namespace std;

int main() {
    
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);
    cin.exceptions(ios :: badbit | ios :: failbit);

    auto Coins_IV = [&] () {
        const int md = 1'000'000'007;
        int n, target;
        cin >> n >> target;
        vector<int> coins(n);
        vector<vector<int>> dp(n + 4, vector<int> (target + 4, 0));

        for (auto &x : coins) {
            cin >> x;
        }

        dp[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= target; j++) {
                dp[i][j] = dp[i - 1][j];
                int left = j - coins[i - 1];
                if (left >= 0) {
                    ((dp[i][j] += dp[i][left]) %= md);
                }
            }
        }
        
        cout << "Number of solutions to form target " << target << " without permutation: " << dp[n][target] << '\n';        
    };Coins_IV();

    return 0;
}