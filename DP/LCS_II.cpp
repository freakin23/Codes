// Problem Link: https://atcoder.jp/contests/dp/tasks/dp_f
#include <bits/stdc++.h>
using namespace std;

#define i23 long long

int main() {
    string a, b;
    cin >> a >> b;

    int n = (int)a.size(), m = (int)b.size();
    vector<vector<int>> dp(n + 1, vector<int> (m + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    int i = n, j = m;
    string res = "";
    while (i and j) {
        if (a[i - 1] == b[j - 1]) {
            res = a[i - 1] + res;
            i--;
            j--;
        } else {
            if (dp[i - 1][j] > dp[i][j - 1]) {
                i--;
            } else {
                j--;
            }
        }
    }
    cout << res << '\n';
    return 0;
}