#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;

    cin>>s;

    if (s.length()==1)
    {
        /* code */
        cout<<s;
    }
    
    else
    {
        /* code */
        sort(s.begin(),s.end());
        s.erase(0, ((s.length()/2)));

        for (int i = 0; i < s.length(); i++)
        {
            /* code */
            if (i==(s.length()-1))
            {
                /* code */
                cout<<s[i];
                break;
            }
            
            cout<<s[i]<<'+';
        }

    }
    
    return 0;

}