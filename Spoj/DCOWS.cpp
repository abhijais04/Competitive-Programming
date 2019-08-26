#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll a[5010],b[5010],cost[5010];
int main()
{
    ll n,m,i,j;
    cin>>n>>m;
    for(i=0;i<n;i++)
        cin>>a[i];
    for(i=0;i<m;i++)
        cin>>b[i];
    sort(a,a+n);
    sort(b,b+m);
    ll ans=0;
    ll pos=m-1;
    ll mn=LONG_LONG_MAX;
    for(i=n-1;i>=0;i--)
    {
        mn=LONG_LONG_MAX;
        for(j=m-n;j>=0;j--)
        {
            ll tmp=(abs(a[i]-b[j+i])+cost[j]);
            mn=min(mn,tmp);
            cost[j]=mn;
        }
    }
    cout<<mn<<"\n";
    return 0;
}
