#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll int
vector<ll> dv;
map<ll,vector<ll> > mp;
int main()
{
    ios_base::sync_with_stdio(NULL);
    ll n;
    cin>>n;
    for(ll i=1;i*i<=n;i++)
    {
        if(n%i==0)
        {
            if(n/i >= 3)
                dv.pb(i);
                if(i*i!=n)
            if(i>=3)
                dv.pb(n/i);
        }
    }
    for(ll i=0;i<dv.size();i++)
    {
        vector<ll> tmp(dv[i],0);
        mp[dv[i]]=tmp;
    }
    ll a[n];
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
        for(ll j=0;j<dv.size();j++)
        {
            ll tmp=dv[j];
            mp[tmp][i%tmp]+=a[i];
        }
    }
    ll ans=INT_MIN;
    for(ll i=0;i<dv.size();i++)
    {
        vector<ll> tmp=mp[dv[i]];
        for(ll j=0;j<tmp.size();j++)
        {
            ans=max(ans,tmp[j]);
        }
    }
    cout<<ans<<"\n";
    return 0;
}