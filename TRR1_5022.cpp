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
ll n, k, a, b, x, y, l, r;

ll nCr(ll n, ll k){
    if(k < 0 || k > n) return 0;
    if(k == 0 || k == n) return 1;
    k = min(k, n-k);
    ll res = 1;
    for(int i = 1; i <=k;++i){
        res = res*(n-i+1)/i;
    }
    return res;
}

int32_t main(){
    boost;
    cin >> n >> k;
    cout << (1LL << n) - nCr(n,k) + 1 << endl;
    return 0;
}