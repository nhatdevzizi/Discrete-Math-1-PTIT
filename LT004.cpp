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

ll arr[1000005], mat[105][105], chosen[105];
bool visited[105];
ll n, k, a, b, x, y, l, r;
ll currentMinCost = 1e18, minCost = 1e18;
vector<vector<ll>> optimalPaths;

void backtrack(int pos, ll currentCost){
    if(currentCost + minCost*(n-pos +2) > currentMinCost) return;
    if(pos > n){
        ll totalCost = currentCost + mat[chosen[n]][1];
        vector<ll> tempPath(n+2);
        if(totalCost < currentMinCost){
            currentMinCost = totalCost;
            optimalPaths.clear();
            for(int i = 1; i <=n; ++i) tempPath[i] = chosen[i];
            optimalPaths.push_back(tempPath);
        }
        else if(totalCost == currentMinCost){
            for(int i = 1; i <=n; ++i) tempPath[i] = chosen[i];
            optimalPaths.push_back(tempPath);
        }
        return;
    }
    for(int i = 2; i <=n;++i){
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
    for(int i = 1; i <=n ; ++i){
        for(int j  = 1; j <=n ; ++j){
            cin >> mat[i][j];
            if(i != j && mat[i][j] > 0){
                minCost = min(minCost, mat[i][j]);
            }
        }
    }
    chosen[1]= 1;
    visited[1] = true;
    backtrack(2,0);
    if(optimalPaths.size() == 1){
        cout << currentMinCost << endl;
        for(int i = 1; i <= n; ++i) cout << optimalPaths[0][i] << ' ';
        cout << endl;
    }
    else {
        cout << currentMinCost << ' ' << optimalPaths.size() << endl;
        for(const auto& path : optimalPaths){
            for(int i = 1; i <= n; ++i){
                cout << path[i] << ' ';
            }
            cout << endl;
        }
    }
    return 0;
}
