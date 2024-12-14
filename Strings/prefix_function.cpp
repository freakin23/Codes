#include <bits/stdc++.h>

class Prefix_Function {
    public:
    std::vector<int> pi;
    std::string s;
    int n;
    Prefix_Function(std::string s) {
        this->s = s;
        this->n = (int)s.size();
        pi = std::vector<int> (n, 0);
    }

    void prefix_function() {
        for (int i = 1; i < n; i++) {
            int j = pi[i - 1];
            while (j > 0 and s[i] != s[j]) {
                j = pi[j - 1];
            }
            if (s[i] == s[j]) {
                j++;
            }
            pi[i] = j;
        }
    }

    void build() {
        prefix_function();
    }
};

std::vector<int> prefix_function(std::string const& s) {
    int n = (int)s.size();
    std::vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 and s[i] != s[j]) {
            j = pi[j - 1];
        }
        if (s[i] == s[j]) {
            j++;
        }
        pi[i] = j;
    }
    return pi;
}

int main() {
    std::string s;
    std::cin >> s;
    int n = (int)s.size();
    std::vector<int> pi = prefix_function(s);
    for (int i = 0; i < n; i++) {
        std::cout << pi[i] << " \n"[i == n - 1];
    }

    Prefix_Function pf = Prefix_Function(s);
    pf.build();
    for (int i = 0; i < n; i++) {
        std::cout << pf.pi[i] << " \n"[i == n - 1];
    }
}