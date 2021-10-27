#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main()
{
    ll n,k;
    cin>>n>>k;

    if (k<=(n+1)/2)
    {
        /* code */
        cout<<(k*2)-1;
    }
    else
    {
        /* code */
        cout<<(k-(n+1)/2)*2;
    }
    
 return 0;
}