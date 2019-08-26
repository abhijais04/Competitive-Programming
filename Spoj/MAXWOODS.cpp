#include <bits/stdc++.h>
using namespace std;
char ch[210][210];
int dp[210][210];
int n,m;
int rec(int i,int j)
{
    if(i>n-1||j>m-1||i<0||j<0)
        return 0;
    if(ch[i][j]=='#')
        return 0;
    if(dp[i][j]>=0)
        return dp[i][j];
    dp[i][j]=0;
    if(i%2==1)
    {
        {
          if(ch[i][j]=='T')
          {
              dp[i][j]=1+max(rec(i,j-1),rec(i+1,j));
          }
          else if(ch[i][j]=='0')
          {
              dp[i][j]=max(rec(i,j-1),rec(i+1,j));
          }
        }
    }
    else
    {
          if(ch[i][j]=='T')
          {
              dp[i][j]=(1+max(rec(i+1,j),rec(i,j+1)));
          }
          else if(ch[i][j]=='0')
          {
              dp[i][j]=(max(rec(i+1,j),rec(i,j+1)));
          }
    }
    return dp[i][j];
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
      scanf("%d%d",&n,&m);
      for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        dp[i][j]=-1;
      for(int i=0;i<n;i++)
        scanf("%s",&ch[i]);
      int ans=rec(0,0);
      cout<<ans<<"\n";
    }
    return 0;
}
