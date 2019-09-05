#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define sc(x) scanf("%lld",&x)
ll sum(ll x)
{
    return (x*(x+1))/2;
}
int main()
{
    ll n,m;
    sc(n); sc(m);
    ll ans=m+1;
    ll lo = 1,h = 1e9;


    if(n<=m+1)
    {
        cout<<n<<"\n";
        return 0;
    }
    lo = 1,h = 1500000000;
    while(lo<=h)
    {
        ll mid = (lo+h)/2;

        if(n-sum(mid) <= m+1+mid)
            {
                h=mid-1;
            }
        else
            {
                lo=mid+1;

            }
    }
    ans+=lo;
    //cout<<lo<<"\n";
    cout<<ans<<"\n";
}