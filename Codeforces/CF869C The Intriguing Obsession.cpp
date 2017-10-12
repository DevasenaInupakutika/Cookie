#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5000 + 5;
const int MOD = 998244353;

long long fact[MAXN];

long long modPow(long long x, long long y) {
    if (y == 0) {
        return 1;
    }
    long long ret = modPow(x * x % MOD, y >> 1);
    if (y & 1) {
        ret = ret * x % MOD;
    }
    return ret;
}

long long modRev(long long x) {
    return modPow(x, MOD - 2);
}

long long modCom(int n, int m) {
    return fact[n] * modRev(fact[n - m] * fact[m] % MOD) % MOD;
}

int main() {
    long long a, b, c;
    cin >> a >> b >> c;
    fact[0] = 1;
    for (int i = 1; i < MAXN; ++i) {
        fact[i] = fact[i - 1] * i % MOD;
    }
    long long ans = 1;
    for (auto p : vector<pair<int, int>>({{a, b}, {b, c}, {a, c}})) {
        long long num = 0;
        auto x = p.first;
        auto y = p.second;
        for (int k = 0; k <= min(x, y); ++k) {
            num += modCom(x, k) * modCom(y, k) % MOD * fact[k] % MOD;
        }
        ans = ans * (num % MOD) % MOD;
    }
    cout << ans << endl;
    return 0;
}
