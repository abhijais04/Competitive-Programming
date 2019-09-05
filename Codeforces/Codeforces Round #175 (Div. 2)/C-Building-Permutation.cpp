#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
ll b[300010],a[300010];
vector<ll> v,v1;
int main()
{
    int n;
    cin>>n;
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]<=n&&a[i]>=1&&b[a[i]]==0)
        {
            b[a[i]]=1;
        }
        else
        {
            v.pb(a[i]);
        }
    }
    for(ll i=1;i<=n;i++)
    {
        if(b[i]==0)
            v1.pb(i);
    }
    //for(ll i=0;i<v1.size();i++)
    //    cout<<v1[i]<<" ";
    //cout<<"\n";
    sort(v.begin(),v.end());
    ll ans=0;
    int nn = min(v.size(),v1.size());
    for(ll i=nn-1;i>=0;i--)
    {
    //    cout<<v[i]<<" "<<v1[i]<<"\n";
        ans+=abs(v[i]-v1[i]);
    }
    cout<<ans<<"\n";
    return 0;

}