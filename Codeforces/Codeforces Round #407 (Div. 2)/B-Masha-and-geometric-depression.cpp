#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define sc(x) scanf("%lld",&x)
ll a[100010];
map<ll,int> mp;
int main()
{
    ll b1,q,m,l;
    sc(b1); sc(q); sc(l); sc(m);
    for(int i=0;i<m;i++)
    {
        sc(a[i]);
        mp[a[i]]++;
    }
    if(abs(b1) > l)
        {
            cout<<"0\n";
            return 0;
        }
    if(b1==0)
    {
        if(mp.count(0LL))
        {
            cout<<"0\n";
            return 0;
        }
        cout<<"inf\n";
        return 0;
    }
    if(abs(q)==1)
    {
        if(mp.count(b1)&&mp.count(q*b1))
            cout<<"0\n";
        else
            cout<<"inf\n";
        return 0;
    }
    ll ans=0;
    if(q==0)
    {
        if(!mp.count(b1))
            ans++;
        if(mp.count(0))
        {
            cout<<ans<<"\n";
            return 0;
        }
        else
            cout<<"inf\n";
        return 0;
    }
    ll f =  b1;
    while(abs(f) <= l)
    {
        if(!mp.count(f))
            ans++;
        f = f*q;
    }
    cout<<ans<<"\n";
}