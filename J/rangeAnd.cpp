#include <bits/stdc++.h>
using namespace std;

const int bit = 32;
const int MAX = 100000;
int main() {
    int n;
    cin >> n;
    vector<int> Arr(n);
    for (auto &x : Arr) {
        cin >> x;
    }   
    vector<vector<int>> prefAnd(bit, vector<int> (MAX, 0));
    auto P = [&] () -> void {
        for (int i = 0; i < bit; i++) {
            prefAnd[i][0] = ((Arr[0] >> i) & 1);
            for (int j = 1; j <  n; j++) {
                prefAnd[i][j] = ((Arr[j] >> i) & 1);
                prefAnd[i][j] += prefAnd[i][j - 1];
            }
        }
    };
    P();

    auto rangeAnd = [&] (int L, int R) -> int {
        int res = 0;
        for (int i = 0; i < bit; i++) {
            int x = 0;
            if (L == 0) {
                x = prefAnd[i][R];
            } else {
                x = prefAnd[i][R] - prefAnd[i][L - 1];
            }

            if (x == R - L + 1) {
                res = (res | (1 << i));
            }
        }
        return res;
    };
    int Q;
    cin >> Q;

    for (int i = 1; i <= Q; i++) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        cout << rangeAnd(l, r) << '\n';
    }

}