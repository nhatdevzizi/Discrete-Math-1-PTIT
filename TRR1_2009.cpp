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
ll n;

int32_t main(){
    boost;
    cin >> n;
    vector<bool> isPrime(n + 1, true);
    vector<int> prime;
    vector<int> phi(n + 1);
    int res = 1;
    phi[1] = 1;
    for(int i = 2; i <= n; ++i){
        if(isPrime[i]){
            prime.push_back(i);
            phi[i] = i- 1;
        }
        for(auto p : prime){
            if(i * p > n) break;
            isPrime[i * p] = false;
            if(i % p == 0){
                phi[i*p] = phi[i] * p;
                break; 
            }
            else phi[i*p] = phi[i] * (p-1);
        }
    }
    for(int i = 1; i <= n; ++i){
        res += phi[i];
    }
    cout << res;
    return 0;
}