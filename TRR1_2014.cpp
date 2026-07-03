//author: nhatdevzizi

/* Phiêu du dòng code, mộng đời trai
Nhật gửi lòng mình giữa sớm mai.
Chẳng ngại sương mờ vây thuật toán
Vất vả một thuở, rạng tương lai. */

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define pb push_back
#define all(x) x.begin(),x.end()
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
const int MOD = 1e9 + 7;

ll arr[1000005];
ll n, k, a, b, x, y, l, r;

int32_t main(){
    boost;
    cin >> n >> k;
    vector<ll> dp(n+2,0);
    for(int i = 1; i <= n; ++i){
        if(i < k) dp[i] = (1LL << i);
        else if(i == k) dp[i] = ((1LL << i)-1);
        else {
            for(int j = 1; j <= k; ++j){
                dp[i] += dp[i-j];
            }
        }
    }
    cout << ((1LL << n) - dp[n]) << endl;
    return 0;
}
