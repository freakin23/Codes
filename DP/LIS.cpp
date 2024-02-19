#include <bits/stdc++.h>
using namespace std;

int main() {
    
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);
    cin.exceptions(ios :: badbit | ios :: failbit);

    auto Longest_Increasing_Subsequence = [&] () {
        int n;
        cin >> n;
        vector<int> dp;
        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            auto it = lower_bound(begin(dp), end(dp), x);
            if (it == dp.end()) {
                dp.push_back(x);
            }
            else {
                *it = x;
            }
        }
        cout << (int)dp.size() << '\n';
    };Longest_Increasing_Subsequence();
    
    return 0;
}