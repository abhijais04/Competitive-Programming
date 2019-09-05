#include <bits/stdc++.h>
using namespace std;
long long sum[100010];
int main()
{
   int n;
   int i;
   cin>>n;
   //int a[n];
   for(i=0;i<n;i++)
   {
       long long tmp;
       cin>>tmp;
       sum[tmp]+=tmp;
   }
   //long long ans=0;
    long long dp[100010];
    dp[0]=sum[0];
    dp[1]=sum[1];
    for(i=2;i<=100005;i++)
    {
        dp[i]=max(sum[i]+dp[i-2],dp[i-1]);
    }
    cout<<dp[100005]<<"\n";
    return 0;
}