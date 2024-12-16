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

class Z_function {
    public:
    std::vector<int> occurence;
    std::vector<int> z;
    std::string s, t;
    int n, f = 0, pat_sz = 0;

    Z_function(std::string const& s, std::string const& t = "") { // s -> pattern, t -> text
        f = (int)t.size();
        this->s = s;
        if (f) {
            this->t = t;
            pat_sz = (int)s.size();
        }
        this->n = (f ? (int)t.size() + (int)s.size() + 1 : (int)s.size());
        z = std::vector<int> (n, 0);
    }

    void z_function(std::string const& s) {
        int l = 0, r = 0;
        for (int i = 1; i < n; i++) {
            if (i < r) {
                z[i] = std::min(r - i, z[i - l]);
            }
            while (i + z[i] < n and s[z[i]] == s[i + z[i]]) {
                z[i]++;
            }
            if (i + z[i] > r) {
                l = i;
                r = i + z[i];
            }
        }

        if (f) {
            for (int i = pat_sz + 1; i < n; i++) {
                if (z[i] == pat_sz) {
                    occurence.push_back(i + 1 - (pat_sz + 1));
                }
            }
        }
        
    }

    void build() {
        s = (f ? s + '#' + t : s);
        z_function(s);
    }
};

int main() {

    ios_base ::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);
    cin.exceptions(ios :: badbit | ios :: failbit);

    std::string pat = "abc", text = "avcfabcagsgabcagaabcasgegsrgabc";
    
    Z_function z_func = Z_function(pat, text);
    z_func.build();
    auto p = z_func.occurence;
    for (auto x : p) {
        std::cout << x << " \n"[x == p.back()];
    }

    Z_function a = Z_function("aabaaab");
    a.build();
    for (int i = 0; i < a.n; i++) {
        std::cout << a.z[i] << " \n"[i == (int)a.n - 1];
    }
    
    return 0;
}