// Maximum Sum Increasing Subsequence

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);
    cin.exceptions(ios :: failbit | ios :: badbit);

    int n;
    cin >> n;
    vector<int> Arr(n);
    for (auto &x : Arr) {
        cin >> x;
    }
    vector<int> Dp(n);
    Dp = Arr;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (Arr[i] > Arr[j] and Dp[i] < Dp[j] + Arr[i]) {
                Dp[i] = Dp[j] + Arr[i];
            }
        }
    }

    int res = *max_element(begin(Dp), end(Dp));
    cout << res << '\n';
    return 0;
}