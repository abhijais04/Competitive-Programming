#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define sc(x) scanf("%lld",&x)
ll a[100010];
int main()
{
    ll n,k;
    sc(n); sc(k);
    for(int i=0;i<n;i++)
        sc(a[i]);
    ll ans=0;
    for(int i=0;i<n;i++)
    {
        ans+=(a[i]/k);
        if(a[i]%k)
            ans++;
    }
    if(ans%2)
        ans++;
    ans=ans/2;
    cout<<ans<<"\n";
}