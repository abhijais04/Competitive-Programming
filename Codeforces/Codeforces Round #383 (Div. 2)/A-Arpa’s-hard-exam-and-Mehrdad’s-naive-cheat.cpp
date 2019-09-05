#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
int mod(ll a,ll b,ll c)
{
    ll ans=1;
    while(b)
    {
        if(b&1)
        {
            ans = (ans*a)%c;
        }
        b=b/2;
        a=(a*a)%c;
    }
    return ans;
}
int main()
{
    ll n;
    cin>>n;
    ll ans = mod(1378,n,10);
    cout<<ans<<"\n";
    return 0;
}