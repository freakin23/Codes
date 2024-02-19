#include <bits/stdc++.h>
using namespace std;

int main() {
    
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);
    cin.exceptions(ios :: badbit | ios :: failbit);

    auto Tiling = [&] () { // 3 x n Board with 2 x n Dominoes
        int n;
        cin >> n;
        vector<int> a(n + 1), b(n + 1);
        a[0] = 1, a[1] = 0;
        b[0] = 0, b[1] = 1;

        for (int i = 2; i <= n; i++) {
            a[i] = a[i - 2] + 2 * b[i - 1];
            b[i] = a[i - 1] + b[i - 2];
        }

        cout << a[n] << '\n';
    };Tiling();
    
    return 0;
}