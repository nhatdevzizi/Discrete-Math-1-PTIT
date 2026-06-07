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

int32_t main(){
    boost;
    cin >> n >> k;
    for(int i = 1; i <= k; ++i){
        cin >> arr[i];
    }
    bool flag = false;
    for(int i = k; i >= 1; --i){
        if(arr[i] - 1 != arr[i-1]){
            arr[i] -= 1;
            flag = true;
            break;
        }
    }
    if(!flag) cout << "0" << endl;
    else
        for (int i = 1; i <= k; ++i)
        {
            cout << arr[i] << ' ';
        }
    cout << endl;
    return 0;
}