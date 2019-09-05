#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
bool ar[1010][1010];
ll nc2(ll x)
{
    return (x*(x-1))/2;
}
int main()
{
    ll n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        ar[x][y]=1;
    }
    ll ans = 0;
    n=1000;
    for(int k=1;k<=n;k++)
    {
        ll cnt=0;
        int i=1,j=k;
        while(i<=n&&j<=n)
        {
            if(ar[i][j])
                cnt++;
            i++;
            j++;
        }
        ans+=nc2(cnt);
    }
    for(int k=2;k<=n;k++)
    {
        int i=k,j=1;
        ll cnt=0;
        while(i<=n&&j<=n)
        {
            if(ar[i][j])
                cnt++;
            i++;
            j++;
        }
        ans+=nc2(cnt);
    }
    for(int k=n;k>=1;k--)
    {
        int i=1,j=k;
        ll cnt=0;
        while(i<=n&&j>=1)
        {
            if(ar[i][j])
                cnt++;
            i++;
            j--;
        }
        ans+=nc2(cnt);
    }
    for(int k=2;k<=n;k++)
    {
        int i=k,j=n;
        ll cnt=0;
        while(i<=n&&j>=1)
        {
            if(ar[i][j])
                cnt++;
            i++;
            j--;
        }
        ans+=nc2(cnt);
    }
    cout<<ans<<"\n";
    return 0;
}