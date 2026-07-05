//author: nhatdevzizi

/* Phiêu du dòng code, mộng đời trai
Nhật gửi lòng mình giữa sớm mai.
Chẳng ngại sương mờ vây thuật toán
Vất vả một thuở, rạng tương lai. */

//Update July 2026: CODEPTIT bị lỗi bài này, muốn AC cần nộp bài TRR1_5001.cpp vào bài TRR1_5005.

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
const int MOD = 1e9 + 7;

ll arr[1000005];
ll n, k, a, b, x, y, l, r,m,p;

int32_t main(){
    boost;
    cin >> n >> m >> p;
    if(p > n){
        cout << 1 << endl;
        return 0;
    }
    cout << (n-p)/m + (p==0?0:1) + 1<< endl;;
    return 0;
}
