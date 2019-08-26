#include <bits/stdc++.h>
using namespace std;
int dp[15][110];
int main()
{
    int i,j,k;
    for(i=0;i<14;i++)
    {
        dp[i][0]=1;
    }
    for(i=0;i<=98;i++)
    {
        dp[0][i]=0;
    }
    for(i=1;i<=12;i++)
    {
        for(k=1;k<=98;k++)
        {
            if(k>(i*(i-1))/2)
                dp[i][k]=0;
            else
            for(j=0;k-j>=0&&j<i;j++)
            {
                dp[i][k]+=dp[i-1][k-j];
            }

        }
    }
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        cout<<dp[n][k]<<"\n";
    }
    return 0;
}
