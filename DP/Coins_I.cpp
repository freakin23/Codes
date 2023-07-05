#include<bits/stdc++.h>
using namespace std;

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);
    cin.exceptions(ios::badbit|ios::failbit);

    auto Coins_I = [&] () {
        int n, target;
        cin >> n >> target;
        vector<int> coins(n), dp(target + 4, 0);
        for (auto &x : coins) {
            cin >> x;
        }

        for (int x = 1; x <= target; x++) {
            dp[x] = INT_MAX;
            for (auto c : coins) {
                if (x - c >= 0) {
                    dp[x] = min(dp[x], dp[x - c] + 1);
                }
            }
        }

        cout << "Total Coins required: " << dp[target] << '\n';
    };Coins_I();

    return 0;
}