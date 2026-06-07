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

ll arr[1000005], chosen[105], bestChosen[105], mat[105][105];
ll n, k, a, b, x, y, l, r;
ll maxVal = -1e18;
bool taken[105];

void backtrack(int pos, ll currentVal){
    if(pos > n){
        if(currentVal > maxVal){
            maxVal = currentVal;
            for(int i = 1; i <= n; ++i){
                bestChosen[i] = chosen[i];
            }
            return;
        }
    }
    for(int i = 1; i <= n; ++i){
        if(!taken[i]){
            taken[i] = true;
            chosen[pos] = i;
            backtrack(pos + 1, currentVal + mat[pos][i]);
            taken[i] = false;
        }
    }
    
}

int32_t main(){
    boost;
    cin >> n;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            cin >> mat[i][j];
        }
    }
    backtrack(1,0);
    cout << maxVal << endl;
    for(int i = 1; i <= n; ++i){
        cout << bestChosen[i] << ' ';
    }
    cout << endl;
    return 0;
}