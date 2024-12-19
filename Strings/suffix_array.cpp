// Problem Link: https://leetcode.com/problems/longest-duplicate-substring/description/

#include <bits/stdc++.h>

class Suffix_Array {
public:
    std::vector<int> p;
    std::vector<int> cnt;
    std::vector<std::vector<int>> c;
    std::vector<int> logs;
    const int alphabet = 256;
    int n;
    std::string s;
    Suffix_Array(std::string s) {
        this->n = (int)s.size();
        this->s = s;
        p = std::vector<int>(n, 0);
        cnt = std::vector<int>(std::max(alphabet, n), 0);
        logs = std::vector<int>(n + 5, 0);
        for (int i = 2; i <= n; ++i) {
            logs[i] = logs[i / 2] + 1;
        }
        
        c = std::vector<std::vector<int>>(logs[n] + 2, std::vector<int>(n + 1, 0));
    }

    void sort_cyclic_shifts() {
        for (int i = 0; i < n; i++) {
            cnt[(int)s[i]]++;
        }
        for (int i = 1; i < alphabet; i++) {
            cnt[i] += cnt[i - 1];
        }
        for (int i = 0; i < n; i++) {
            p[--cnt[(int)s[i]]] = i;
        }
        c[0][p[0]] = 0;
        int classes = 1;
        for (int i = 1; i < n; i++) {
            if (s[p[i]] != s[p[i - 1]]) {
                classes++;
            }
            c[0][p[i]] = classes - 1;
        }

        std::vector<int> pn(n), cn(n);
        for (int h = 0; (1 << h) < n; ++h) {
            for (int i = 0; i < n; i++) {
                pn[i] = p[i] - (1 << h);
                if (pn[i] < 0) {
                    pn[i] += n;
                }
            }
            fill(cnt.begin(), cnt.begin() + classes, 0);
            for (int i = 0; i < n; i++) {
                cnt[c[h][pn[i]]]++; 
            }
            for (int i = 1; i < classes; i++) {
                cnt[i] += cnt[i - 1];
            }
            for (int i = n - 1; i >= 0; i--) {
                p[--cnt[c[h][pn[i]]]] = pn[i];
            }
            cn[p[0]] = 0;
            classes = 1;
            for (int i = 1; i < n; i++) {
                std::pair<int, int> cur = {c[h][p[i]], c[h][(p[i] + (1 << h)) % n]};
                std::pair<int, int> prev = {c[h][p[i - 1]], c[h][(p[i - 1] + (1 << h)) % n]};
                if (cur != prev) {
                    ++classes;
                }
                cn[p[i]] = classes - 1;
            }
            
            for (int i = 0 ; i < n; ++i) {
                c[h + 1][i] = cn[i];
            }   
        }
    }

    void generate() {
        sort_cyclic_shifts();
        for (int i = 0 ; i < (int) s.size() - 1; ++i) {
            p[i] = p[i + 1];
        }
    }

    // k = floor(log l), l = length, {i, j} = starting indexes
    int compare(int i, int j, int l, int k) { 
        std::pair<int, int> a = {c[k][i], c[k][(i + l - (1 << k)) % n]};
        std::pair<int, int> b = {c[k][j], c[k][(j + l - (1 << k)) % n]};
        return a == b ? 0 : a < b ? -1 : 1;
    }

    // Longest common prefix of two substrings with additional memory
    int lcp(int i, int j) {
        int res = 0;
        for (int k = logs[n]; k >= 0; k--) {
            if (c[k][i % n] == c[k][j % n]) {
                res += 1 << k;
                i += 1 << k;
                j += 1 << k;
            }
        }
        return res;
    }

    // Longest common prefix of two substrings without additional memory
    std::vector<int> lcp_construction() {
        int n = s.size();
        std::vector<int> rank(n, 0);
        for (int i = 0; i < n; i++)
            rank[p[i]] = i;

        int k = 0;
        std::vector<int> lcp(n - 1, 0);
        for (int i = 0; i < n; i++) {
            if (rank[i] == n - 1) {
                k = 0;
                continue;
            }
            int j = p[rank[i] + 1];
            while (i + k < n && j + k < n && s[i + k] == s[j + k]) {
                k++;
            }
            lcp[rank[i]] = k;
            if (k) {
                k--;
            }
        }
        return lcp;
    }

    // No. of different substrings = (n^2 + n) / 2 - sigma(i = 0 to n - 2)lcp[i]    
};

int main() {
    std::string t;
    std::cin >> t;
    int n = (int)t.size();
    t += '#';
    Suffix_Array sa = Suffix_Array(t);
    sa.generate();
    int len = 0;
    int pos = -1;
    for (int i = 0; i < n - 1; i++) {
        int curr_len = sa.lcp(sa.p[i], sa.p[i + 1]);
        if (len < curr_len) {
            len = curr_len;
            pos = sa.p[i];
        }
    }

    std::cout << (pos == -1 ? "" : t.substr(pos, len)) << '\n';
}