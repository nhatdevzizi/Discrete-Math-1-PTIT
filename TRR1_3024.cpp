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
bool visited[1000005];
ll n, k, u, v, x, y, l, r;
bool flag = false;

void backtrack(int pos){
    if(pos > n){
        if(!flag){
            for (int i = 1; i <= n; ++i)
            {
                cout << arr[i] << ' ';
            }
            cout << endl;
            return;
        }
    }
    for(int i = 1; i <= n; ++i){
        if(!visited[i]){
            flag = true;
            arr[pos] = i;
            visited[i] = true;
            backtrack(pos + 1);
            visited[i] = false;
        }
    }
}

int32_t main(){
    boost;
    cin >> n >> k;
    for(int i = 1; i <= k; ++i){
        cin >> u >> v;
        arr[u] = v;
        visited[v] = true;
    }
    backtrack(k+1);
    if(flag) cout << 0 << endl;
    return 0;
}
