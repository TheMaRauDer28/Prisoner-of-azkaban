#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> a(m);
    for (int i = 0; i < m; i++)
    {
        /* code */
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    int ans = 0, min = INT_MAX;
    for (int i = 0; i <= m - n; i++)
    {
        /* code */
        ans = a[i + n - 1] - a[i];
        if (min > ans)
        {
            /* code */
            min = ans;
        }
    }
    cout << min;

    return 0;
}