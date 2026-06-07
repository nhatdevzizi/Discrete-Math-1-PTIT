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
bool found = false;


int32_t main(){
    boost;
    cin >> n >> k;
    ll res = 0;
    ll c4 = n/4;
    ll c2 = n/2 - n/4;
    ll c1 = n - n/2;
    res = (c1*c1) + 2*(c1*c2);
    if(res < k) cout << 0 << endl;
    else cout << res + k << endl;
    return 0;
}