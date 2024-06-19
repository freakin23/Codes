#include <bits/stdc++.h>
using namespace std;

int eggDrop(vector<vector<int>> &dp, int eggs, int floors) { // TC -> O(eggs * floors * floors)
    if (dp[eggs][floors] != -1) {
        return dp[eggs][floors];
    }

    if (floors == 1 or floors == 0) {
        return floors;
    }

    if (eggs == 1) {
        return floors;
    }

    int mn = INT_MAX, res = 0;
    for (int floor = 1; floor <= floors; floor++) {
        res = max(eggDrop(dp, eggs - 1, floor - 1), eggDrop(dp, eggs, floors - floor));
        if (res < mn) {
            mn = res;
        }
    }
    return dp[eggs][floors] = mn + 1;
}

int eggDrop(int eggs, int floors) { // TC -> O(eggs * floors)
    vector<vector<int>> dp(floors + 1, vector<int> (eggs + 1, 0));
    int res = 0;
    while (dp[res][eggs] < floors) {
        res++;
        for (int x = 1; x <= eggs; x++) {
            dp[res][x] = 1 + dp[res - 1][x - 1] + dp[res - 1][x];
        }
    }
    return res;
}

int main() {
    int eggs, floors;
    cin >> eggs >> floors;
    vector<vector<int>> dp(eggs + 1, vector<int> (floors + 1, -1));
    cout << eggDrop(dp, eggs, floors) << '\n';
    cout << eggDrop(eggs, floors) << '\n';
}