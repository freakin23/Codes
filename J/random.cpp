#include <bits/stdc++.h>
using namespace std;

vector<int> factor(int n) {
    vector<int> res;
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            res.push_back(i);
            n /= i;
        }
    }
    if (n > 1) {
        res.push_back(n);
    }
    return res;
}

vector<pair<int, int>> prime_factor(int n) {
    vector<pair<int, int>> res;
    for (int i = 2; i * i <= n; i++) {
        int cnt = 0;
        if (n % i == 0) {
            res.push_back({i, 0});
            while (n % i == 0) {
                res.back().second += 1;
                n /= i;
            }
        }
    }
    if (n > 1) {
        res.push_back({n, 1});
    }
    return res;
}

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b); 
}

int main() {
    vector<int> p = factor(252);
    for (auto x : p) {
        cout << x << " ";
    }
    cout << '\n';

    auto P = prime_factor(252);
    for (auto x : P) {
        cout << x.first << " " << x.second << '\n';
    }

    cout << gcd(10, 15) << '\n';
}