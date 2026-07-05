//author: nhatdevzizi

/* Phiêu du dòng code, mộng đời trai
Nhật gửi lòng mình giữa sớm mai.
Chẳng ngại sương mờ vây thuật toán
Vất vả một thuở, rạng tương lai. */

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define pb push_back
#define all(x) x.begin(),x.end()
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
const int MOD = 1e9 + 7;

ll arr[1000005], chosen[105], bestChosen[105];
ll n, k, a, b, x, y, l, r;
ll maxVal = -1e18;

struct ITEM{
    ll w,v, orgIdx;
    double ratio;
} items[105];

bool cmp(const ITEM &a, const ITEM &b){
    return a.ratio > b.ratio;
}

double upperbound(int pos, ll currentWeight, ll currentVal){
    double bound = currentVal;
    ll cap = b - currentWeight;
    ll j = pos;
    while(j <= n && items[j].w <= cap){
        cap -= items[j].w;
        bound += items[j].v;
        j++;
    }
    if(j <= n){
        bound += 1.0 * items[j].ratio * cap;
    }
    return bound;
}

void backtrack(int pos, ll currentWeight, ll currentVal){
    if(upperbound(pos, currentWeight, currentVal) <= maxVal) return;
    if(pos > n){
        if(currentVal > maxVal){
            maxVal = currentVal;
            for(int i = 1; i <= n; ++i) bestChosen[i] = chosen[i];
        }
        return;
    }
    if(currentWeight + items[pos].w <= b){
        chosen[pos] = 1;
        backtrack(pos + 1, currentWeight + items[pos].w, currentVal + items[pos].v);
        chosen[pos] = 0;
    }
    backtrack(pos + 1, currentWeight, currentVal);
}

int32_t main(){
    boost;
    cin >> n >> b;
    for (int i = 1; i <= n; ++i){
        cin >> items[i].w >> items[i].v;
        items[i].ratio = 1.0 * items[i].v / items[i].w;
        items[i].orgIdx = i;
    }
    sort(items, items + n + 1, cmp);
    backtrack(1, 0, 0);
    cout << maxVal << endl;
    ll res[105];
    for(int i = 1; i <= n; ++i){
        res[items[i].orgIdx] = bestChosen[i];
    }
    for(int i = 1; i <= n; ++i){
        cout << res[i]  << endl;
    }
    return 0;
}