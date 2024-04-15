// https://usaco.guide/plat/sweep-line?lang=cpp

#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<pair<int, int>> Arr {{6, 12}, {10, 15}, {14, 16}, {5, 13}};
    vector<int> a(20, 0);

    for (auto x : Arr) {
        a[x.first]++; // -> start 
        a[x.second + 1]--; // -> end + 1
    }

    int res = 0, curr = 0;
    for (auto x : a) {
        curr += x;
        res = max(res, curr);
    }
    cout << res << '\n';
}