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
ll n;

void euler(ll n, vector<ll>& phi){
    for (int i = 0; i <= n; ++i){
        phi[i] = i;
    }
    for (int i = 2; i <= n; ++i){
        if (phi[i] == i){
            for (int j = i; j <= n; j += i){
                phi[j] -= phi[j] / i;
            }
        }
    }
}

int32_t main(){
    boost;
    cin >> n;
    vector<ll> phi(n + 2, 0);
    euler(n, phi);
    ll t = 1;
    for (int b = 1; b <= n; ++b){
        t += phi[b];
    }
    cout << t << endl;
    return 0;
}
