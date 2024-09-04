// Link: https://cp-algorithms.com/algebra/phi-function.html

#include <bits/stdc++.h>
using namespace std;

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

int main() {
    cout << phi(6) << '\n'; //  2
    cout << phi(12) << '\n'; //  4
    cout << phi(15) << '\n'; //  8
}