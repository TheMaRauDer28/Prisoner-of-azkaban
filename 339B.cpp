#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
#define ll long long

int main()
{
    fast;
    ll n, m;
    cin >> n >> m;

    ll idx = 1, cnt = 0;
    while (m--)
    {
        ll x;
        cin >> x;

        if (x > idx)
        {
            cnt += (x - idx);
        }
        else if (x < idx)
        {
            cnt += (n - idx + x);
        }

        idx = x;
    }

    cout << cnt;
    return 0;
}