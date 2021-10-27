#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n;
    cin >> n;

    if (n >= 0)
    {
        /* code */
        cout << n;
        return 0;
    }
    else
    {
        /* code */
        stringstream a;
        a << n;

        string s = a.str();
        char x, y, z;
        x = s[s.length() - 1];
        y = s[s.length() - 2];
        z = max(x, y);

        if (z == x)
        {
            /* code */
            s.erase(s.begin() + (s.length() - 1));
            if (s == "-" || s == "-0")
            {
                /* code */
                cout << 0;
                return 0;
            }
            cout << s;
            return 0;
        }

        else if (z == y)
        {
            /* code */
            s.erase(s.begin() + (s.length() - 2));
            if (s == "-" || s == "-0")
            {
                /* code */
                cout << 0;
                return 0;
            }
            cout << s;
            return 0;
        }
    }

    return 0;
}