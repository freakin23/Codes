#include <bits/stdc++.h>
using namespace std;
#define i23 long long

struct sieve {
    vector<i23> primes;
    vector<bool> is_prime;
    vector<i23> min_factor;

    sieve(i23 MAX = 1 << 20) { 
        is_prime = vector<bool>(MAX, true);
        min_factor = vector<i23>(MAX);
        is_prime[0] = is_prime[1] = false;
        min_factor[0] = min_factor[1] = 1;
        for (i23 i = 2; i < MAX; i++) {
            if (!is_prime[i]) {
                continue;
            }
            primes.emplace_back(i);
            min_factor[i] = i;
            if ((long long) i * i >= MAX) {
                continue;
            }
            for (i23 j = i * i; j < MAX; j += i) {
                if (is_prime[j]) {
                    is_prime[j] = false;
                    min_factor[j] = i;
                }
            }
        }
    }

    
    vector<pair<int, int>> factor(int n) { //si.factor(n)
        vector<pair<int, int>> res;
        while (n != 1) {
            int p = min_factor[n];
            res.emplace_back(p, 0);
            while (p == min_factor[n]) {
                n /= p;
                res.back().second++;
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }

    vector<int> divisor(int n) { //si.divisor(n)
        vector<int> res(1, 1);
        for (const auto& p : factor(n)) { 
            for (int i = (int) res.size() - 1; i >= 0; i--) {
                int c = res[i];
                for (int j = 0; j < p.second; j++) {
                    c *= p.first;
                    res.emplace_back(c);
                }
            }
        }
        sort(res.begin(), res.end());
        return res;
    }

    vector<int> mu_table() {
        vector<int> res(min_factor.size());
        for (int i = 1; i < (int) min_factor.size(); i++) {
            if (i == 1) {
                res[i] = 1;
            } else if ((i / min_factor[i]) % min_factor[i] == 0) {
                res[i] = 0;
            } else {
                res[i] = -res[i / min_factor[i]];
            }
        }
        return res;
    }

    // zeta: add
    // mobius: subtract
    // zeta <-> mobius
    template <typename T>
    void divisor_zeta(vector<T>& a) {
        int n = (int) a.size();
        for (int p : primes) {
            if (p >= n) {
                break;
            }
            for (int i = 1; p * i < n; i++) {
                a[p * i] += a[i];
            }
        }
    }

    template <typename T>
    void divisor_mobius(vector<T>& a) {
        int n = (int) a.size();
        for (int p : primes) {
            if (p >= n) {
                break;
            }
            for (int i = (n - 1) / p; i >= 1; i--) {
                a[p * i] -= a[i];
            }
        }
    }

    template <typename T>
    void multiple_zeta(vector<T>& a) {
        int n = (int) a.size();
        for (int p : primes) {
            if (p >= n) {
                break;
            }
            for (int i = (n - 1) / p; i >= 1; i--) {
                a[i] += a[p * i];
            }
        }
    }

    template <typename T>
    void multiple_mobius(vector<T>& a) {
        int n = (int) a.size();
        for (int p : primes) {
            if (p >= n) {
                break;
            }
            for (int i = 1; p * i < n; i++) {
                a[i] -= a[p * i];
            }
        }
    }
};

template<typename T>
vector<pair<T,int>> prime_factor(T n){
    n = abs(n);
    vector<pair<T,int>> res;
    for(T i = 2; i * i <= n; i++){
        if(n % i == 0){
            res.push_back({i,0});
            while(n % i == 0){
                n /= i;
                res.back().second++;
            }
        }
    }
    if(n > 1){
        res.push_back({n, 1});
    }
    return res;
}
