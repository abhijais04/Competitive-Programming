#include<bits/stdc++.h>
using namespace std;
long long n;
long long dp[11000],a[11000];
long long val(long long i)
{
    if(i>=n)
        return 0;
    if(dp[i]!=0)
        return dp[i];
    else
    {
        dp[i]=max(a[i]+val(i+2),val(i+1));
        return dp[i];
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    int c=1;
    while(t--)
    {
        scanf("%lld",&n);
        long long i;
        if(n==0)
        scanf("\n");
        for(i=0;i<=10010;i++)
        {
            dp[i]=0;
            a[i]=0;
        }
        for(i=0;i<n;i++)
        {
            dp[i]=0;
            scanf("%lld",&a[i]);
        }
        long long ans=val(0);
        printf("Case %d: %lld \n",c,ans);
        c++;
    }
    return 0;
}
