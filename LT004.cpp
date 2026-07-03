#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n, c[35][35], mn = 1e18, ans = 1e18;
ll a[35], b[35];
bool vs[35];
vector<ll>vc;
void dq(int step, int u, ll sum)
{
    if (sum + mn * (n - step + 1) > ans)
        return;
    if (step > n)
    {
        if (sum + c[u][1] < ans)
        {
            vc.clear();
            ans = sum + c[u][1];
 
            for (int j=1; j<=n; j++)
                vc.push_back(a[j]);
        }
        else if (sum + c[u][1] == ans)
        {
            for (int j=1; j<=n; j++)
                vc.push_back(a[j]);
        }
        return;
    }
    for (int v=1; v<=n; v++)
    {
        if (!vs[v])
        {
            vs[v] = true;
            a[step] = v;
            dq(step + 1, v, sum + c[u][v]);
            vs[v] = false;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=n; j++)
        {
            cin >> c[i][j];
            if (i != j)
                mn = min(mn, c[i][j]);
        }
    }
    a[1] = 1;
    vs[1] = true;
    dq(2, 1, 0);
    cout << ans;
    if (vc.size()/n == 1)
        cout << '\n';
    else
    {
        cout << " ";
        cout << vc.size()/n << '\n';
    }
 
    for (int i=0; i<vc.size(); i++)
    {
        cout << vc[i] << " ";
        if (i%n == n-1)
            cout << '\n';
    }
    return 0;
}
