#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n;
    cin>>n;
    ll ans=1;
    ll pre=3;
    for(ll i=4;i<=n;i++)
    {
        ans+=pre;
        pre=pre+2;
    }
    cout<<ans<<"\n";
}