#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, l, r;
    ios::sync_with_stdio(false);
    cin >> n;
    vector<pair<int, int>> pts;
    while (n--) {
        cin >> l >> r;
        pts.push_back({l, 1});
        pts.push_back({r + 1, -1});
    }
    sort(pts.begin(), pts.end());
    int cnt = 0;
    bool flag = true;
    for (auto pt : pts) {
        cnt += pt.second;
        if (cnt > 2) {
            flag = false;
            break;
        }
    }
    puts(flag ? "YES" : "NO");
    return 0;
}
