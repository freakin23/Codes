#include <bits/stdc++.h>
using namespace std;

int main() {
    
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);
    cin.exceptions(ios :: badbit | ios :: failbit);

    auto Coins_III = [&] () {
        const int md = 1'000'000'007;
        int n, target;
        cin >> n >> target;
        vector<int> coins(n), count(target + 4);

        for (auto &x : coins) {
            cin >> x;
        }

        count[0] = 1;
        for (int x = 1; x <= target; x++) {
            for (auto c : coins) {
                if (x - c >= 0) {
                    (count[x] += count[x - c]) %= md;
                }
            }
        }
        cout << "Number of solutions to form target " << target << " with permutation: " << count[target] << '\n';
    };Coins_III();

    return 0;
}