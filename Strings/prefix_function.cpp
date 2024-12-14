#include <bits/stdc++.h>

class Prefix_Function {
    public:
    std::vector<int> pi;
    std::vector<int> occurence;
    std::string s, t; // s -> pattern, t -> text
    int n, pat_sz = 0, f = 0;
    Prefix_Function(std::string const& s, std::string const& t = "") {
        f = (int)t.size();
        this->s = s;
        if (f) {
            pat_sz = (int)s.size();
            this->t = t;
        }
        this->n = (f ? (int)t.size() + (int)s.size() + 1 : (int)s.size());
        pi = std::vector<int> (n, 0);
    }

    void prefix_function(std::string const& s) {
        int n = (int)s.size();
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

        if (f) {
            for (int i = 0; i < n; i++) {
                if (pi[i] == pat_sz) {
                    occurence.push_back(i - 2 * pat_sz + 1);
                }
            }
        }
    }

    void build() {
        s = (f ? s + '#' + t : s);
        prefix_function(s);
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
    std::string s, t;
    std::cin >> s >> t;
    Prefix_Function pf = Prefix_Function(s, t);
    pf.build();
    for (int i = 0; i < (int)pf.occurence.size(); i++) {
        std::cout << pf.occurence[i] << " \n"[i == (int)pf.occurence.size() - 1];
    }

    std::string a = "aabaaab";
    Prefix_Function A = Prefix_Function(a);
    A.build();
    for (int i = 0; i < (int)A.pi.size(); i++) {
        std::cout << A.pi[i] << " \n"[i == (int)A.pi.size() - 1];
    }
}