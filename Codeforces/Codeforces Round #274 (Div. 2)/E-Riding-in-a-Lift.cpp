#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define sc(x) scanf("%lld",&x)
ll m = 1e9+7;
ll b,n;
int main()
{
    ll a,k;
    sc(n); sc(a); sc(b); sc(k);
    vector<ll> dp(n+1,0),sum(n+1,0);
    for(int i=1;i<=n;i++)
    {
        if(i!=a)
        if(abs(i-a) < abs(a-b))
            dp[i] = 1;
        sum[i] = sum[i-1] + dp[i];
    }
    for(int j=2;j<=k;j++)
    {
        vector<ll> ndp(n+1,0),nsum(n+1,0);
        for(int i=1;i<=n;i++)
        {
            if(i<b)
            {
                ll h = (b-i-1)/2;
                h+=i;
                ndp[i] = sum[h];
                if(h>=i)
                ndp[i] -= dp[i];
            }
            else if(i>b)
            {
                ll l = (i-b-1)/2;
                l = i-l;
                ndp[i] = sum[n] - sum[l-1];
                if(l<=i)
                ndp[i] -= dp[i];
            }
            ndp[i]=(ndp[i]+m)%m;
            nsum[i] = ndp[i] + nsum[i-1];
            nsum[i]=(nsum[i]+m)%m;
        }
        dp = ndp;
        sum = nsum;
    }
    cout<<(sum[n]+m)%m<<"\n";
    return 0;
}