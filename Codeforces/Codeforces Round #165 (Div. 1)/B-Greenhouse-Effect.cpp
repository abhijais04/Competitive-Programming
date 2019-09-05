#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
int dp[5010];
int a[5010];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        float x;
        cin>>a[i];
        cin>>x;
    }
    dp[0]=1;
    int ans=1;
    for(int i=1;i<n;i++)
    {
        dp[i]=1;
        for(int j=0;j<i;j++)
        {
            if(a[i]>=a[j])
                dp[i]=max(dp[i],dp[j]+1);
        }
        ans=max(ans,dp[i]);
    }
    cout<<n-ans<<"\n";
}