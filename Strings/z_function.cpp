// https://cp-algorithms.com/string/z-function.html
#include <bits/stdc++.h>
using namespace std;

vector<int> z_function(string s) {
    int n = (int)s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        if (i < r) {
            z[i] = min(r - i, z[i - l]);
        }

        while (i + z[i] < n and s[z[i]] == s[i + z[i]]) {
            z[i] += 1;
        }

        if (i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}

int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);
    cin.exceptions(ios :: badbit | ios :: failbit);

    string s;
    cin >> s;
    auto z = z_function(s);
    for (int i = 0; i < (int)s.size(); i++) {
        cout << z[i] << " \n"[i == (int)s.size() - 1];
    }
    return 0;
}