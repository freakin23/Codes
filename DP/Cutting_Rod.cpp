#include<bits/stdc++.h>
using namespace std;

int main(){
    
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);
    cin.exceptions(ios :: badbit | ios :: failbit);

    auto Cutting_Rod = [&] () {
        int n;
        cin >> n;
        vector<int> price(n), dp(n + 4, 0);
        for (auto &x : price) {
            cin >> x;
        }

        for (int i = 1; i <= n; i++) {
            int max_val = INT_MIN;
            for (int j = 0; j < i; j++) {
                max_val = max(max_val, price[j] + dp[i - j - 1]);
            }
            dp[i] = max_val;
        }

        cout << (int)dp[n] << '\n';

    };Cutting_Rod();

    return 0;
}