#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<vector<ll>> dp(n + 1, vector<ll>(k, 0));
    dp[1][0] = 1; 
    if (k > 1) {
        dp[1][1] = 1; 
    }
    for (int i = 2; i <= n; ++i) {
        for (int j = 0; j < k; ++j) {
            dp[i][0] += dp[i - 1][j];
        }
        for (int j = 1; j < k; ++j) {
            dp[i][j] = dp[i - 1][j - 1];
        }
    }
    ll ans = 0;
    for (int j = 0; j < k; ++j) {
        ans += dp[n][j]; 
    }

    ll total = 0;
    for (int j = 0; j < k; ++j) {
        total += dp[n][j];
    }

    cout << total << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}