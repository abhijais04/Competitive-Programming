#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define sc(x) scanf("%d",&x)
int val(char ch)
{
    return ch=='.';
}
int dp[1001][1001][2];
int cost[1001][2];
int n,m,x,y;
int fn(int pos,int pre,int cl)
{
    if(pos>=m)
    {
        if((pre < x)|| (pre>y))
            return 1e8;
        return 0;
    }
    if(dp[pos][pre][cl]!=-1)
        return dp[pos][pre][cl];
    int ans=0;
    if(pre<x)
    {
        ans+=cost[pos][cl]+fn(pos+1,pre+1,cl);
    }
    else
    {
        if(pre<y)
        ans+=min(cost[pos][cl]+fn(pos+1,pre+1,cl),cost[pos][(cl+1)%2]+fn(pos+1,1,(cl+1)%2));
        else
        ans+=cost[pos][(cl+1)%2]+fn(pos+1,1,(cl+1)%2);
    }
    return dp[pos][pre][cl] = ans;

}
int main()
{
    memset(dp,-1,sizeof(dp));
    sc(n); sc(m); sc(x); sc(y);
    string str[n];
    for(int i=0;i<n;i++) cin>>str[i];
    for(int i=0;i<m;i++)
    {
        int s=0;
        for(int j=0;j<n;j++)
        {
            s+=val(str[j][i]);
        }
        cost[i][0]=s;
        cost[i][1]=n-s;
    }
    cout<<min(fn(0,0,0),fn(0,0,1));
}