#include <bits/stdc++.h>

class Prefix_Function {
    public:
    std::vector<int> pi;
    std::vector<int> occurence;
    std::string s, t;
    int n, pat_sz = -1, f = 0;
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

    std::vector<int> prefix_occurence() {
        std::vector<int> res(n + 1);
        for (int i = pat_sz + 1; i < n; i++) {
            res[pi[i]]++;
        }
        for (int i = n - 1; i > pat_sz + 1; i--) {
            res[pi[i - 1]] += res[i]; 
        }

        if (pat_sz == -1) {
            for (int i = 0; i <= n; i++) {
                res[i]++;
            }
        }
        
        return res;
    }

    void build() {
        s = (f ? s + '#' + t : s);
        prefix_function(s);
    }
};

int main() {
    std::string s, t;
    std::cin >> s >> t;
    // std::string s = "abc", t = "aaaabccbabcrgsgabcccca";
    Prefix_Function pf = Prefix_Function(s, t);
    pf.build();
    for (int i = 0; i < (int)pf.occurence.size(); i++) {
        std::cout << pf.occurence[i] << " \n"[i == (int)pf.occurence.size() - 1];
    }

    std::vector<int> pf_res = pf.prefix_occurence();
    for (int i = 1; i <= pf.pat_sz; i++) {
        std::cout << pf_res[i] << " \n"[i == pf.pat_sz];
    }

    std::string a = "aabaaab";
    Prefix_Function A = Prefix_Function(a);
    A.build();
    for (int i = 0; i < (int)A.pi.size(); i++) {
        std::cout << A.pi[i] << " \n"[i == (int)A.pi.size() - 1];
    }

    std::vector<int> A_res = A.prefix_occurence();
    for (int i = 1; i <= A.n; i++) {
        std::cout << A_res[i] << " \n"[i == A.n];
    }
}