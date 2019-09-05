#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
int main()
{
    ll n,m;
    cin>>n>>m;
    ll ans=0;
    for(int i=0;i<=max(n,m);i++)
    {
        for(int j=0;j<=max(n,m);j++)
        {
            if((i*i)+j==n &&((j*j)+i==m))
                ans++;
        }
    }
    cout<<ans<<"\n";
    return 0;
}