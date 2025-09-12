#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;

int n;
vector<int> a, prefix;
vector<vector<int>> dp;

int sum(int l, int r) {
    return prefix[r+1] - prefix[l];
}

int rec(int l, int r) {
    if (l == r) return 0; 
    if (dp[l][r] != -1) return dp[l][r];

    int ans = INF;
    for (int k = l; k < r; k++) {
        ans = min(ans, rec(l, k) + rec(k+1, r) + sum(l, r));
    }
    return dp[l][r] = ans;
}

void solve() {
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    prefix.assign(n+1, 0);
    for (int i = 0; i < n; i++) prefix[i+1] = prefix[i] + a[i];

    dp.assign(n, vector<int>(n, -1));

    cout << rec(0, n-1) << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
