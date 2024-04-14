#include <bits/stdc++.h>

struct lex_compare {
    bool operator() (const int64_t& lhs, const int64_t& rhs) const {
        std::stringstream s1, s2;
        s1 << lhs;
        s2 << rhs;
        return s1.str() < s2.str();
    }
};

int main() {
    std::set<int64_t, lex_compare> st = {1, 2, 3, 4, 11, 22, 33, 44, 111, 222, 333, 444}; // Sorts lexicographically
    for (auto x : st) {
        std::cout << x << " ";
    }
    std::cout << '\n';

    auto cmp = [] (int a, int b) {
        return a > b;
    };

    std::set<int, decltype(cmp)> s(cmp); // Sorts in descending order
    for (int i = 1; i <= 10; i++) {
        s.insert(i);
    }
    for (auto x : s) {
        std::cout << x << " ";
    }
    std::cout << '\n';

}