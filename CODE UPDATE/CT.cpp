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

ll arr[1000005], weight[10005];
ll n, k, a, b, x, y, l, r;
ll bestVal = 0;
vector<pair<ll,ll>> best, current;
ll res = -1e19;

void backtrack(int pos, ll w, ll c){
    if(pos > n){
        if(c > bestVal){
            bestVal = c;
            best = current;
        } 
        return;
    }
    if(w + arr[pos] <= b){
        current.push_back({arr[pos],weight[pos]});
        backtrack(pos  + 1, w + arr[pos], c + weight[pos]);
        current.pop_back();
    }
    backtrack(pos  + 1, w, c);
}

int32_t main(){
    boost;
    cin >> n >> b;
    for(int i = 1; i <= n; ++i){
        cin >> arr[i] >> weight[i]; 
    }
    backtrack(1,0,0);
    cout << bestVal << endl;
    cout << best.size() << endl;
    for(auto &i : best) cout << i.first << ' ' << i.second << endl;
    return 0;
}