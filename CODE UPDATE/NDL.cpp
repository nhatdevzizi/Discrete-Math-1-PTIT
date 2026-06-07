#include <bits/stdc++.h>
using namespace std;

int n;
int a[20][20];
int fopt = 1e9;
bool visited[20];
vector<int> v, kq;

void duyet(int cost, vector<int>& v, int cur) {
    if (cost >= fopt) return;
    if ((int)v.size() == n) {
        int total = cost + a[cur][1];
        if (total < fopt) {
            fopt = total;
            kq = v;
        }
        return;
    }
    for (int i = 2; i <= n; ++i) {
        if (!visited[i]) {
            visited[i] = true;
            v.push_back(i);
            duyet(cost + a[cur][i], v, i);
            visited[i] = false;
            v.pop_back();
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> a[i][j];

    visited[1] = true;
    v.push_back(1);
    duyet(0, v, 1);

    cout << fopt << '\n';
    for (int x : kq) cout << x << ' ';
    cout << '\n';
    return 0;
}