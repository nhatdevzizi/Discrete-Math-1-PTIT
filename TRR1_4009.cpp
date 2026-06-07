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

ll arr[1000005], mat[20][20], chosen[20], bestChosen[20], suffMax[20];
ll n, k, a, b, x, y, l, r;
ll maxVal = -1e18;
bool visited[20];

void backtrack(int pos, ll currentVal){
    if(currentVal + suffMax[pos] <= maxVal) return;
    if(pos > n){
        if(currentVal > maxVal){
            maxVal = currentVal;
            for(int i = 1; i <=n;++i){
                bestChosen[i] = chosen[i];
            }
            return;
        }
    }
    for(int i = 1; i <=n;++i){
        if(!visited[i]){
            visited[i] = true;
            chosen[pos] = i;
            backtrack(pos + 1, currentVal + mat[pos][i]);
            visited[i] = false;
        }
    }
}

int32_t main(){
    boost;
    cin >> n;
    for (int i = 1; i <= n; ++i){
        ll currentMaxRow = -1e18;
        for (int j = 1; j <= n; ++j){
            cin >> mat[i][j];
            currentMaxRow = max(currentMaxRow, mat[i][j]);
        }
        suffMax[i] = currentMaxRow;
    }
    for(int i = n - 1; i >= 1; --i){
        suffMax[i] = suffMax[i+1] + suffMax[i];
    }
    backtrack(1,0);
    cout << maxVal << endl;
    for(int i = 1; i <=n;++i){
        cout << bestChosen[i] << ' ';
    }
    cout << endl;
    return 0;
}