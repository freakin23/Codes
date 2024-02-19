#include <bits/stdc++.h>
using namespace std;

int main(){
    
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);
    cin.exceptions(ios :: badbit | ios :: failbit);

    auto Knapsack = [&] () {
        int n, x;
        cin >> n >> x;
        vector<int> Arr(n), price(n);

        for (auto &x : Arr) {
            cin >> x;
        }

        for (auto &x : price) {
            cin >> x;
        }

        vector<vector<int>> dp(n + 4, vector<int> (x + 4, 0));
        
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= x; j++) {
                dp[i][j] = dp[i - 1][j];
                int left = j - Arr[i - 1];
                if (left >= 0) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][left] + price[i - 1]);
                }
            }
        }

        cout << (int)dp[n][x] << '\n';

    };Knapsack();

    return 0;
}