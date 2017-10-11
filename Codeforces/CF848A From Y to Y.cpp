#include <bits/stdc++.h>
using namespace std;

int main() {
    int k;
    cin >> k;
    if (k == 0) {
        cout << 'a' << endl;
        return 0;
    }
    vector<int> nums = {0};
    string ans = "";
    for (int i = 1; *nums.rbegin() < k; ++i) {
        nums.push_back(i * (i - 1) / 2);
    }
    char alpha = 'a';
    while (k) {
        for (int i = nums.size() - 1; i >= 0; --i) {
            if (nums[i] <= k) {
                k -= nums[i];
                while (i) {
                    ans += alpha;
                    --i;
                }
                break;
            }
        }
        ++alpha;
    }
    cout << ans << endl;
    return 0;
}
