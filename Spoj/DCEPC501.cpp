#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,a[100010],dp[100010];
ll max(ll a,ll b)
{
    if(a>b)
        return a;
    return b;
}
ll fn(int i)
{
    if(i>=n)
        return 0;
    if(n-i<=3)
    {
        ll sum=0;
        for(int j=i;j<n;j++)
            sum+=a[j];
        return sum;
    }
    if(dp[i]!=0)
    return dp[i];
    return dp[i]=max(a[i]+fn(i+2),max(a[i]+a[i+1]+fn(i+4),a[i]+a[i+1]+a[i+2]+fn(i+6)));
}
int main()
{
    int t;
   scanf("%d",&t);
   // cin>>t;
    while(t--)
    {
    	scanf("%lld",&n);
        //cin>>n;
        for(int i=0;i<n;i++)
        dp[i]=0;
        for(int i=0;i<n;i++)
        {
            scanf("%lld",&a[i]);
        }
        cout<<fn(0)<<"\n";
    }
    return 0;
}
