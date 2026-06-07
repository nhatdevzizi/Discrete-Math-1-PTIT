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
ll n, k, a, b, x, y, l, r,t;

int32_t main(){
    boost;
    cin >> n >> k >> t;
    for(int i = 1; i <=n;++i){
        cin >> arr[i];
    }
    for (int cnt = 1; cnt <= t; ++cnt){
        for (int i = k; i >= 1; --i){
            if (i == 0){
                cout << 0 << endl;
                break;
            }
            if (arr[i] != n - k + i){
                arr[i] += 1;
                for (int j = i + 1; j <= k; ++j){
                    arr[j] = arr[j - 1] + 1;
                }
                for (int j = 1; j <= k; ++j){
                    cout << arr[j] << ' ';
                }
                cout << endl;
                break;
            }
        }
    }
    return 0;
}