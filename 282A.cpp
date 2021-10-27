#include<bits/stdc++.h>
using namespace std;

int main(){

    int n,x=0;
    string s;

    cin>>n;

    for (int i = 0; i < n; i++)
    {
        /* code */
        cin>>s;

        if (s=="++X" || s=="X++")
        {
            /* code */
            x++;
        }

            if (s=="--X" || s=="X--")
            {
                /* code */
                x--;
            }
    }

    cout<<x;
    return 0;
}