#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
int m=1000000007;
int dp[2011][2011];
int solve(int n,int k)
{
   // cout<<n<<" "<<k<<"\n";
    if(n==0)
        return 0;
    if(k==0)
        return 1;
        if(k==1)
        {
            int cnt=0;
            for(int j=n;j>=1;j--)
                if(n%j==0)
                cnt++;
            return cnt;
        }
    if(n==1)
    {
        //if(k==1)
            return 1;
        //2 1return 0;
    }
    if(dp[n][k]!=0)
        return dp[n][k];
    int ans=0;
    for(int j=n;j>0;j--)
    {
        if(n%j==0)
        {
            ans=ans+solve(j,k-1);
            ans%=m;
        }
    }
    return dp[n][k]=ans;
}
int main()
{
    //for(int i=1;i<=n;i++)
    dp[1][0]=1;
    for(int i=1;i<=2010;i++)
    {
        for(int j=i;j<=2010;j+=i)
        {
            for(int l=1;l<=2010;l++)
            {
                dp[j][l]+=dp[i][l-1];
                dp[j][l]%=m;
            }
        }
    }
   // while(1)
    {
    int n,k;
    cin>>n>>k;
    int ans=0;
    for(int i=1;i<=n;i++)
        {
            ans+=dp[i][k];
            ans%=m;
        }
    cout<<ans<<"\n";
    }
}