#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
int main()
{
    ll n;
    ll mx=0;
    cin>>n;
    ll sum=0;
    for(ll i=0;i<n;i++)
    {
        ll tmp;
        cin>>tmp;
        mx=max(mx,tmp);
        sum+=tmp;
    }
    ll ans=sum/(n-1);
    if(sum%(n-1)>0)
        ans++;
    if(ans<mx)
    ans=mx;
    cout<<ans<<"\n";


}