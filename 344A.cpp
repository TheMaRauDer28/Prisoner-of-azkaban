#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int a[n], cnt = 1;

    for (int i = 0; i < n; i++)
    {
        /* code */
        cin >> a[i];
    }

    for (int i = 0; i < n - 1; i++)
    {
        /* code */
        if (a[i] != a[i + 1])
        {
            /* code */
            cnt++;
        }
    }

    cout << cnt;
    return 0;
}