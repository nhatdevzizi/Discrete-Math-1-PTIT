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
#define pb push_back
const int MOD = 1e9 + 7;

ll arr[1000005];
ll n, k, y, l, r;

int32_t main(){
    boost;
    cin >> n;
    set<int> a,b;
    vector<int> res;
    for(int i = 1; i <= n; ++i){
        int x; cin >> x;
        if(x== 1) a.insert(i);
    }
    for(int i = 1; i <= n; ++i){
        int x; cin >> x;
        if(x == 1) b.insert(i);
    }
    for(int i = 1; i <= n; ++i){
        if(a.find(i) != a.end() && b.find(i) != b.end()){
            res.pb(i);
        }
    }
    cout << res.size() << endl;
    for(auto i : res) cout << i << ' ';
    return 0;
}