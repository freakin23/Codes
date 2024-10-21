#include <bits/stdc++.h>

std::vector<int> rabin_karp(std::string st, std::string pattern) {
	const int p = 31;
	const int m = 1e9 + 9;

	int a = (int)st.size(), b = (int)pattern.size();

	std::vector<long long> p_pow(std::max(a, b));
	p_pow[0] = 1;
	for (int i = 1; i < (int)p_pow.size(); i++) {
		p_pow[i] = (p_pow[i - 1] * p) % m;
	}

	std::vector<long long> h(a + 1, 0);
	for (int i = 0; i < a; i++) {
		h[i + 1] = (h[i] + (st[i] - 'a' + 1) * p_pow[i]) % m;
	}

	long long h_pattern = 0;
	for (int i = 0; i < b; i++) {
		h_pattern = (h_pattern + (pattern[i] - 'a' + 1) * p_pow[i]) % m;
	}

	std::vector<int> occurrences;
	for (int i = 0; i + b - 1 < a; i++) {
		long long curr_h = (h[i + b] + m - h[i]) % m;
		if (curr_h == h_pattern * p_pow[i] % m) {
			occurrences.push_back(i);
		}
	}

	return occurrences;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    std::cin.exceptions(std::ios::badbit|std::ios::failbit);
    
	std::string st, pattern;
	std::cin >> st >> pattern;
	std::vector<int> res = rabin_karp(st, pattern);

	for (auto x : res) {
		std::cout << x << " \n"[x == res.back()];
	}

    return 0;
}
