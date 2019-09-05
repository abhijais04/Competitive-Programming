#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sc(x) scanf("%lld",&x)
#define scd(y) scanf("%lf",&y);
const int sz = 1e5+5;
ll a[sz],b[sz];
ll n,m;
ll check(ll x)
{
	ll ans=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]<x)
		ans+=(x-a[i]);
	}
	for(int i=0;i<m;i++)
	{
		if(b[i]>x)
		ans+=(b[i]-x);
	}
	return ans;
}
int main()
{
    sc(n); sc(m);
    for(int i=0;i<n;i++) sc(a[i]);
    for(int i=0;i<m;i++) sc(b[i]);
    ll l=1,h=1e9;
    ll ans = 1e18;
    for(int i=0;i<100;i++)
    {
        ll m1 = l + ((h-l)/3);
        ll m2 = h - ((h-l)/3);
     //   ans = min(ans,check(m1));
       // ans = min(ans,check(m2));
        if(check(m1) < check(m2))
            h = m2;
        else
            l = m1;
    }
    for(ll i=l;i<=h;i++)
        ans = min(ans,check(i));
    cout<<ans<<"\n";
}