#include <bits/stdc++.h>
using namespace std;

int main(){
    
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);
    cin.exceptions(ios :: badbit | ios :: failbit);

    auto Edit_Distance = [&] () {
        string s, t;
        cin >> s >> t;
        int a = (int)s.size();
        int b = (int)t.size();
        vector<vector<int>> dp(a + 4, vector<int> (b + 4, 0));

        for (int i = 0; i <= a; i++) {
            for (int j = 0; j <= b; j++) {
                if (i == 0) {
                    dp[i][j] = j;
                }
                else if (j == 0) {
                    dp[i][j] = i;
                }
                else if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else {
                    dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j -1]});
                }
            }
        }
        cout << (int)dp[a][b] << '\n';
    };Edit_Distance();

    return 0;
}