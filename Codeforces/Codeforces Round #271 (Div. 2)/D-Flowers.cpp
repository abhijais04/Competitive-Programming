#include<bits/stdc++.h>
using namespace std;
int dp[100010];
int sum[100010];
int mod = 1e9 +7;
int main()
{
    int t,k;
    cin>>t>>k;
    dp[0]=1;
    sum[0]=1;
    for(int i=1;i<=100004;i++)
    {
        if(i<k)
        dp[i]=1;
        else
        dp[i]=(dp[i-1]%mod+dp[i-k]%mod)%mod;
        sum[i]=(sum[i-1]%mod+dp[i]%mod)%mod;
    }
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        int ans=(sum[b]-sum[a-1]+mod)%mod;

        cout<<ans<<"\n";
    }
    return 0;
}