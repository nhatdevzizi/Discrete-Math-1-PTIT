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
    cin >> n;
    set<int> s;
    for(int i = 1; i <= n; ++i){
        int x;
        cin >> x;
        if(x == 1) s.insert(i);
    }
    for(int i = 1; i <= n; ++i){
        int x;
        cin >> x;
        if(x == 1) s.insert(i);
    }
    cout << s.size() << endl;
    for(auto x :s){
        cout << x << ' ';
    }
    cout << endl;
    return 0;
}