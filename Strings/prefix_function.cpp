#include <bits/stdc++.h>

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
    std::vector<int> pi = prefix_function(s);
    for (int i = 0; i < (int)s.size(); i++) {
        std::cout << pi[i] << " \n"[i == (int)s.size() - 1];
    }
}