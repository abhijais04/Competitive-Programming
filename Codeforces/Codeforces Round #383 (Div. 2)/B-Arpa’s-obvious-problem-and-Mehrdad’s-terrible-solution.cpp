#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
int main()
{
    ll n,x;
    cin>>n>>x;
    ll a[n];
    map<ll,ll> mp;
    ll ans=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        ans+=mp[a[i]^x];
        mp[a[i]]++;
    }
    cout<<ans<<"\n";
    return 0;
}