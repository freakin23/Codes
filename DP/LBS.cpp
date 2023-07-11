#include<bits/stdc++.h>
using namespace std;

int main() {
    
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);
    cin.exceptions(ios :: badbit | ios :: failbit);

    auto Longest_Bitonic_Subsequence = [&] () {
        int n;
        cin >> n;
        vector<int> Arr(n);
        for (auto &x : Arr) {
            cin >> x;
        }
        vector<int> LIS(n + 4, 1), LDS(n + 4, 1);
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (Arr[i] > Arr[j] and LIS[i] < LIS[j] + 1) {
                    LIS[i] = LIS[j] + 1;
                }
            }
        }

        for (int i = n - 2; i >= 0; i--) {
            for (int j = n - 1; j > i; j--) {
                if (Arr[i] > Arr[j] and LDS[i] < LDS[j] + 1) {
                    LDS[i] = LDS[j] + 1;
                }
            }
        }

        int res = 0;
        for (int i = 0; i < n; i++) {
            res = max(res, LIS[i] + LDS[i] - 1);
        }

        cout << res << '\n';
    };Longest_Bitonic_Subsequence();
    
    return 0;
}