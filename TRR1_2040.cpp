//author: nhatdevzizi

/* Phiêu du dòng code, mộng đời trai
Nhật gửi lòng mình giữa sớm mai.
Chẳng ngại sương mờ vây thuật toán
Vất vả một thuở, rạng tương lai. */

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
const int MOD = 1e9 + 7;

ll arr[1000005];
vector<int> v;
ll n, k,s, a, b, x, y, l, r;
int res = 0, sum  =0;

ll C(ll n, ll k){
    if(k > n) return 0;
    k = min(k, n-k);
    ll ans = 1;
    for(int i  =1; i <= k; ++i){
        ans = ans * (n-i + 1)/i;
    }
    return ans;
}

int32_t main(){
    boost;
    cin >> n >> s;
    // backtrack(0,0);
    cout << C(n,s);
    return 0;
}
