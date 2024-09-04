// Link: https://cp-algorithms.com/algebra/phi-function.html

#include <bits/stdc++.h>
using namespace std;

// runs in O(sqrt(n))
int phi(int n) {
    int res = n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0) {
                n /= i;
            }
            res -= res / i;
        }
    }
    if (n > 1) {
        res -= res / n;
    }
    return res;
}

// runs in O(n log log n)
void phi_1_to_n(int n) {
    vector<int> phi(n + 1);
    for (int i = 0; i <= n; i++) {
        phi[i] = i;
    }

    for (int i = 2; i <= n; i++) {
        if (phi[i] == i) {
            for (int j = i; j <= n; j += i) {
                phi[j] -= phi[j] / i;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << phi[i] << " \n"[i == n];
    }
}

int main() {
    cout << phi(6) << '\n'; //  2
    cout << phi(12) << '\n'; //  4
    cout << phi(15) << '\n'; //  8

    phi_1_to_n(15); // 1 1 2 2 4 2 6 4 6 4 10 4 12 6 8

}