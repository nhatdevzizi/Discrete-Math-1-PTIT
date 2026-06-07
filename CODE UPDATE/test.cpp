#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

ll arr[1000005];
ll n, k, t;
bool flag = false;

void backtrack(int pos) {
    if (pos > k) {
        flag = true;
        for (int i = 1; i <= k; ++i) {
            cout << arr[i] << ' ';
        }
        cout << endl;
        return;
    }
    
    // Chỉ cần chạy đến n, vì điều kiện t ở main đã đảm bảo đủ phần tử
    for (int i = arr[pos - 1] + 1; i <= n; ++i) {
        arr[pos] = i;
        backtrack(pos + 1);
    }
}

int32_t main() {
    boost;
    
    if (!(cin >> n >> k >> t)) return 0;
    
    // Kiểm tra xem từ t có đủ k phần tử tăng dần đến n hay không
    if (t > n - k + 1 || k > n || t < 1) {
        cout << 0 << endl;
        return 0;
    }
    
    arr[1] = t;
    backtrack(2);
    
    return 0;
}