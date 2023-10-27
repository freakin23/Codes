#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

int add(int x, int y) {
    if ((x += y) >= MOD) {
        x -= MOD;
    }
    return x;
}

int mul(int x, int y) {
    return x * y % MOD;
}

vector<vector<int>> mul(vector<vector<int>> &a, vector<vector<int>> &b) {
    const int m = a.size(), n = a[0].size(), p = b[0].size();
    vector<vector<int>> res(m, vector<int>(p));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < p; k++) {
                res[i][k] = add(res[i][k], mul(a[i][j], b[j][k]));
            }
        }
    } 
    return res;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);
    cin.exceptions(ios :: badbit | ios :: failbit);

    vector<vector<int>> a = {{1, 2}, {3, 4}};
    vector<vector<int>> b = {{5, 6}, {7, 8}};
    vector<vector<int>> res;

    res = mul(a, b);
    for (int i = 0; i < (int)res.size(); i++) {
        for (int j = 0; j < (int)res[i].size(); j++) {
            cout << res[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}