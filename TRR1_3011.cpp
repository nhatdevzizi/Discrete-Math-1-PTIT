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
ll n, k, a, b, x, y, l, r, t;

int32_t main(){
    boost;
    cin >> n >> t;
    for(int i = 1; i <= n ; ++i){
        cin >> arr[i];
    }
    while(t--){
        bool flag = false;
        for(int i = n; i >= 1; --i){
            if(arr[i] < arr[i+1]){
                flag = true;
                for(int j = n; j >= i; --j){
                    if(arr[j] > arr[i]){
                        swap(arr[j], arr[i]);
                        reverse(arr + i + 1, arr + n + 1);
                        break;
                    }
                }
                break;
            }
        }
        if(!flag) cout << "0";
        else for(int i = 1; i <= n; ++i){
            cout << arr[i] << ' ';
        }
        cout << endl;
    }
    return 0;
}