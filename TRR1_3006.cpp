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
vector<int> res;

int32_t main(){
    boost;
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> arr[i];
    }
    bool changed = false;
    for(int i = n-1; i >= 1; --i){
        if(arr[i] > arr[i+1]){
            swap(arr[i], arr[i+1]);
            sort(arr + i, arr + n + 1);
            changed = true;
            break;
        }
    }
    if(!changed) cout << 0 << endl;
    else
    {
        for (int i = 1; i <= n; ++i)
        {
            cout << arr[i] << ' ';
        }
        cout << endl;
    }
    return 0;
}