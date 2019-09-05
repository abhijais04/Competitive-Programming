#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
int dp[510][3];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<3;j++)
        {
            dp[i][j]=100000;
        }
    }
    string str[n];
    for(int i=0;i<n;i++)
    {
        cin>>str[i];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(str[i][j]>='0'&&str[i][j]<='9')
            {
                dp[i][0]=min(dp[i][0],min(j,m-j));
            }
            else if(str[i][j]>='a'&&str[i][j]<='z')
            {
                dp[i][1]=min(dp[i][1],min(j,m-j));
            }
            else
            {
                dp[i][2]=min(dp[i][2],min(j,m-j));
            }
        }
    }
    int ans=100000;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            for(int k=j+1;k<n;k++)
            {
                ans=min(ans,dp[i][0]+dp[j][1]+dp[k][2]);
                ans=min(ans,dp[i][0]+dp[j][2]+dp[k][1]);
                ans=min(ans,dp[i][1]+dp[j][0]+dp[k][2]);
                ans=min(ans,dp[i][1]+dp[j][2]+dp[k][0]);
                ans=min(ans,dp[i][2]+dp[j][0]+dp[k][1]);
                ans=min(ans,dp[i][2]+dp[j][1]+dp[k][0]);
            }
        }
    }
    cout<<ans<<"\n";
}