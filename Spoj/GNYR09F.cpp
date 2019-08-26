#include <bits/stdc++.h>
using namespace std;
int n;
int dp[110][2][110];
int fn(int idx , int pre , int rmn)
{
    if(idx==n)
    {
        if(rmn==0)
            return 1;
        return 0;
    }
    if(rmn>=n-idx+1)
        return 0;
    if(dp[n-idx][pre][rmn]!=-1)
        return dp[n-idx][pre][rmn];
    if(pre==0)
    {
        return dp[n-idx][pre][rmn] = fn(idx+1,1,rmn)+fn(idx+1,0,rmn);
    }
    if(pre==1)
    {
        return dp[n-idx][pre][rmn] = fn(idx+1,1,rmn-1)+fn(idx+1,0,rmn);
    }
}
int main()
{
    int i,j,k;
    for(i=0;i<110;i++)
    {
        for(j=0;j<2;j++)
        {
            for(k=0;k<108;k++)
            {
                dp[i][j][k]=-1;
            }
        }
    }
  //  dp[100][1][]
    int t;
    cin>>t;
    while(t--)
    {
        int k,a;
        cin>>a>>n>>k;
        cout<<a<<" "<<fn(1,0,k)+fn(1,1,k)<<"\n";
    }
    return 0;
}
