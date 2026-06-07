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
ll n, k, a, b, x, y, l, r, h, m, t;

int32_t main(){
    boost;
    cin >> h >> m >> n >> t;
    ll res = (t-1)*m*n+1;
    if(res > h){
        cout << 0 << endl;
    }
    else{
        cout << res << endl;
    }
    return 0;
}