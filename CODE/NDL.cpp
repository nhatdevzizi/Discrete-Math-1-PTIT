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

ll arr[1000005], bestChosen[35], chosen[35];
ll mat[105][105];
ll n, k, a, b, x, y, l, r;
ll currentMinCost = 1e18, minCost = 1e18;
bool visited[35];

void backtrack(int pos, ll currentCost){
    if(currentCost + (n - pos + 1)*minCost >= currentMinCost) return;
    if(pos > n){
        if(currentCost + mat[chosen[n]][1] < currentMinCost){
            currentMinCost = currentCost + mat[chosen[n]][1];
            for(int i = 1; i <= n; ++i) bestChosen[i] = chosen[i];
        }
        return;
    }
    for(int i = 2; i <= n; ++i){
        if(!visited[i]){
            visited[i] = true;
            chosen[pos] = i;
            backtrack(pos + 1, currentCost + mat[chosen[pos-1]][i]);
            visited[i] = false;
        } 
    }
}

int32_t main(){
    boost;
    cin >> n;
    for(int i = 1; i <= n;++i){
        for(int j = 1; j <=n; ++j){
            cin >> mat[i][j];
            if(i != j && mat[i][j] > 0) minCost = min(minCost,mat[i][j]);
        }
    }
    chosen[1] = 1;
    visited[1]= true;
    backtrack(2,0);
    cout << currentMinCost << endl;
    for(int i = 1; i <=n ; ++i){
        cout << bestChosen[i] << ' ';
    }
    cout << endl;
    return 0;
}
