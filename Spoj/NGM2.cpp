#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
int cnt[1010];
ll sb(ll i)
{
    ll ans=0;
    while(i)
    {
        i&=(i-1);
        ans++;
    }
    return ans;
}
ll flcm(ll a,ll b)
{
    ll gc=__gcd(a,b);
    return (ll)(a*b)/gc;

}
int main()
{
    //cout<<(1<<4)<<"\n";
    ll n,k;
    cin>>n>>k;
    ll a[k];
    for(ll i=0;i<k;i++)
        cin>>a[i];
    ll ans=0;
    for(ll i=1;i<=k;i++)
    {
        ll lcm=1;
        ll total=0;
        for(ll j=0;j<(1<<k);j++)
        {
            ll tmp=sb(j);
            if(tmp==i)
            {
                lcm=1;
                for(ll x=0;x<k;x++)
                {
                    if((1<<x)&j)
                    {
                        if(lcm==1)
                            lcm=a[x];
                        else
                            lcm=flcm(lcm,a[x]);
                    }
                }
                total+=(n/lcm);
            }
        }
        if(i%2==1)
        {
            ans+=total;
        }
        else
            ans-=total;
        //cout<<ans<<"\n";
    }
    cout<<n-ans<<"\n";
    return 0;
}
