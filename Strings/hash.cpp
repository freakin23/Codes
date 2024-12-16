#include <bits/stdc++.h>

long long compute_hash(std::string st) {
	const int p = 31;
	const int m = 1e9 + 9;
	long long p_pow = 1, hash_value = 0;
	for (auto c : st) {
		hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
		p_pow = (p_pow * p) % m;
	}
	return hash_value;
}

std::vector<std::vector<int>> group_identical_strings(std::vector<std::string> arr) {
	int n = (int)arr.size();
	std::vector<std::pair<long long, int>> hashes(n);
	for (int i = 0; i < n; i++) {
		hashes[i] = {compute_hash(arr[i]), i};
	}
	std::sort(begin(hashes), end(hashes));
	std::vector<std::vector<int>> groups;

	for (int i = 0; i < n; i++) {
		if (i == 0 or (hashes[i].first != hashes[i - 1].first)) {
			groups.emplace_back();
		}
		groups.back().push_back(hashes[i].second);
	}

	return groups;
}

int count_unique_substrings(std::string const& s) {
    int n = (int)s.size();

    const int p = 31;
    const int m = 1e9 + 9;
    std::vector<long long> p_pow(n);
    p_pow[0] = 1;
    for (int i = 1; i < n; i++) {
        p_pow[i] = (p_pow[i - 1] * p) % m;
    }

    std::vector<long long> h(n + 1, 0);
    for (int i = 0; i < n; i++) {
        h[i + 1] = (h[i] + (s[i] - 'a' + 1) * p_pow[i]) % m;
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        std::unordered_set<long long> hs;
        for (int j = 0; j <= n - i; j++) {
            long long curr_h = (h[j + 1] + m - h[j]) % m;
            curr_h = (curr_h * p_pow[n - j - 1]) % m;
            hs.insert(curr_h);
        }
        cnt += (int)hs.size();
    }
    return cnt;
}