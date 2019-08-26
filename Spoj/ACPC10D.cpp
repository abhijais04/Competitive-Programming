#include <bits/stdc++.h>
using namespace std;
int n;
int a[100000][3];
int dp[100000][3];
int val(int i,int j)
{
    if(i>n-1||j>2||i<0||j<0)
        return INT_MAX;
    if(dp[i][j]!=0)
        return dp[i][j];
    if(j==0)
    {
        if(i==n-1)
            dp[i][j]=a[i][j]+a[i][j+1];
        else
        dp[i][j]=a[i][j]+min(min(val(i,j+1),val(i+1,j)),val(i+1,j+1));
    }
    else if(j==2)
    {
        if(i==n-2)
            dp[i][j]=a[i][j]+a[i+1][j-1];
        else
        dp[i][j]=a[i][j]+min(val(i+1,j),val(i+1,j-1));
    }
    else if(j==1)
    {
        if(i==n-1)
            dp[i][j]=a[i][j];
        else if(i==n-2)
            dp[i][j]=a[i][j]+min(min(val(i+1,j-1),val(i+1,j)),val(i,j+1));
        else
        dp[i][j]=a[i][j]+min(min(val(i+1,j-1),val(i+1,j)),min(val(i,j+1),val(i+1,j+1)));
    }
    return dp[i][j];
}
int main()
{
    int c=1;
    while(1)
    {
        scanf("%d",&n);
        if(n==0)
            break;
        else
        {
            int i,j;
            for(i=0;i<n;i++)
            {
                for(j=0;j<3;j++)
                {
                    scanf("%d",&a[i][j]);
                    dp[i][j]=0;
                }
            }
            int ans=val(0,1);
            printf("%d. %d\n",c,ans);
            c++;
        }
    }

    return 0;
}
