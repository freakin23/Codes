#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct FenwickTree {
    int n;
    vector<T> bit;

    FenwickTree(int n = 0) {
        init(n);
    }

    void init(int n) {
        this -> n = n;
        bit.assign(n, T());
    }

    void update(int idx, T val) {
        for (; idx < n; idx = idx | (idx + 1)) {
            bit[idx] += val;
        }
    }

    T sum(int idx) {
        auto res = T();
        for (; idx >= 0; idx = (idx & (idx + 1)) - 1) {
            res += bit[idx];
        }
        return res;
    }

    T rangeSum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

};

int main() {
    int n;
    cin >> n;
    FenwickTree<int> f(n + 4);
    for (int i = 0; i <= n; i++) {
        f.update(i, i); // 1 - indexing
    }

    for (int i = 0; i <= n; i++) {
        cout << f.sum(i) << " \n"[i == n];
    }

    cout << f.rangeSum(5, 9) << '\n';
}