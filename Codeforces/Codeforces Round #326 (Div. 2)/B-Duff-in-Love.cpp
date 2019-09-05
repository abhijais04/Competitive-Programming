#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool isp(ll n)
{
    if(n<=3)
    return true;
    for(ll i=2;i*i<=n;i++)
    {
        if(n%i==0)
        return false;
    }
    return true;
}
int main()
{
    ll n;
    cin>>n;
    ll ans=1;
    ll x=n;
    for(ll i=2;i*i<=n;i++)
    {
        if(x%i==0)
        {
            ans*=i;
            while(x>1&&x%i==0)
            x/=i;
        }
    }
    if(x>1)
    {
        if(isp(x))
        ans*=x;
    }
    cout<<ans<<"\n";
}