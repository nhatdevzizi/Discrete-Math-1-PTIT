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
ll n, k, a, b, x, y, l, m,r;

ll gcd(ll a, ll b){
    if(b == 0) return a;
    return gcd(b, a % b);
}

ll lcm(ll a, ll b){
    return a/gcd(a,b) * b;
}

int32_t main(){
    boost;
    cin >> a >> b >> k >> m;
    ll kMultiplier = b/k - (a-1)/k;
    ll mMultiplier = b/m - (a-1)/m;
    ll kmLCM = lcm(k,m);
    ll res = kMultiplier + mMultiplier - (b/kmLCM - (a-1)/kmLCM);
    cout << res << endl; 
    return 0;
}