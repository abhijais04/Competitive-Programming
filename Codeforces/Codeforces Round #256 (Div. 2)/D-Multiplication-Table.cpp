#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sc(x) scanf("%lld",&x)
int main()
{
    ll n,m,k;
    sc(n); sc(m); sc(k);
    ll l=1,h=n*m;
    while(l<=h)
    {
        ll cnt=0;
        ll mid = (l+h)/2;
        for(int i=1;i<=n;i++)
            cnt+=min(mid/i,m);
        if(cnt<k)
            l=mid+1;
        else
            h=mid-1;
    }
    cout<<l<<"\n";
}