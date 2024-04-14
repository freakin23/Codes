#include <bits/stdc++.h>
using namespace std;

class Mex {
private:
    map<int, int> frequency;
    set<int> missing_numbers;
    vector<int> A;

public:
    Mex(vector<int> const& A) : A(A) {
        for (int i = 0; i <= A.size(); i++)
            missing_numbers.insert(i);

        for (int x : A) {
            ++frequency[x];
            missing_numbers.erase(x);
        }
    }

    int mex() {
        return *missing_numbers.begin();
    }

    void update(int idx, int new_value) {
        if (--frequency[A[idx]] == 0)
            missing_numbers.insert(A[idx]);
        A[idx] = new_value;
        ++frequency[new_value];
        missing_numbers.erase(new_value);
    }
};

int find_mex(vector<int> A) {
    set<int> b(A.begin(), A.end());

    int result = 0;
    while (b.count(result))
        ++result;
    return result;
}



int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);
    cin.exceptions(ios :: badbit | ios :: failbit);

    int n, Q;
    cin >> n >> Q;
    vector<int> Arr(n);
    for (auto &x : Arr) {
        cin >> x;
    }

    Mex M(Arr);
    for (int i = 1; i <= Q; i++) {
        int pos, x;
        cin >> pos >> x;
        pos -= 1;
        // Arr[pos] = x;
        M.update(pos, x);
        cout << M.mex() << '\n';
        
    }
    return  0;
}