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
bool flag = false;

void backtrack(int pos){
    if(pos > k){
        flag = true;
        for (int i = 1; i <= k; ++i){
            cout << arr[i] << ' ';
        }
        cout << endl;
        return;
    }
    for(int i = arr[pos-1] + 1; i <= n -k  + pos;++i){
        arr[pos] = i;
        backtrack(pos + 1);
    }
}

int32_t main(){
    boost;
    cin >> n >> k >> t;
    arr[1] = t;
    backtrack(2);
    if(!flag) cout << 0 << endl;
    return 0;
}