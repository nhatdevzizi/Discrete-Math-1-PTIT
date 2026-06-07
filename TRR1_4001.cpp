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

ll arr[1000005], chosen[25], bestChosen[25];
ll n, k, a, b, x, y, l, r;
ll maxSum = -1e18;

struct Item{
    ll w,v;
};
Item items[105];

void backtrack(int pos, ll currentSum, ll currentWeight){
    if(pos > n){
        if(currentSum > maxSum){
            maxSum = currentSum;
            for(int i = 1; i <=n;++i){
                bestChosen[i] = chosen[i];
            }
        }
        return;
    }
    if(currentWeight + items[pos].w <= b){
        chosen[pos] = 1;
        backtrack(pos + 1, currentSum + items[pos].v, currentWeight + items[pos].w);
        chosen[pos] = 0;
    }
    backtrack(pos + 1, currentSum, currentWeight);
}

int32_t main(){
    boost;
    cin >> n >> b;
    for(int i = 1; i <= n; ++i){
        cin >> items[i].w >> items[i].v;
    }
    backtrack(1,0,0);
    cout << maxSum << endl;
    for(int i = 1; i <= n; ++i){
        cout << bestChosen[i] << ' ';
    }
    cout << endl;
    return 0;
}