#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define sc(x) scanf("%lld",&x)
ll a[5001],sum[5001];
ll add(ll l,ll r) {return sum[r]-sum[l-1];}
int main()
{
    ll n,m,k;
    sc(n); sc(m); sc(k);
    for(int i=1;i<=n;i++) sc(a[i]),sum[i]=sum[i-1]+a[i];
    vector<ll> dp(n+1,0);
    for(int i=m;i<=n;i++)
    {
        dp[i]=max(dp[i-1],add(i-m+1,i));
    }
    for(int j=2;j<=k;j++)
    {
        vector<ll> ndp(n+1,0);
        for(int i=j*m;i<=n;i++)
        {
            ndp[i]=max(ndp[i-1],add(i-m+1,i)+dp[i-m]);
        }
        dp=ndp;
    }
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
        ans=max(ans,dp[i]);
    }
    cout<<ans<<"\n";
    return 0;
}