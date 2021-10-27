#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
#define ll long long

int main()
{
    fast;
    int n;
    cin >> n;

    int a[n], total = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        total += a[i];
    }

    int s, t;
    cin >> s >> t;
    s = s - 1;
    t = t - 1;

    if (s == t)
    {
        cout << "0";
        return 0;
    }

    int x, y;
    x = max(s, t);
    y = min(s, t);
    int cv_dis = 0, anticv_dis = 0;
    for (int i = y; i < x; i++)
    {
        cv_dis += a[i];
    }
    anticv_dis = total - cv_dis;

    int ans;
    ans = min(cv_dis, anticv_dis);
    cout << ans;

    return 0;
}