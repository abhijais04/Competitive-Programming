#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define sc(x) scanf("%d",&x)
int dp[200010];
vector<pair<int,int> > v[200010];
int dfs1(int x,int par)
{
    int ans=0;
    for(int i=0;i<v[x].size();i++)
    {
        int to = v[x][i].first;
        int cost = v[x][i].second;
        if(to!=par)
        {
            ans+=cost;
            ans+=dfs1(to,x);
        }
    }
    return dp[x] = ans;
}

void dfs2(int x,int par,int cst)
{
    if(par!=0)
    {
        if(cst==0)
        dp[x] = dp[par] +1;
        else
            dp[x] = dp[par] -1;
    }
    for(int i=0;i<v[x].size();i++)
    {
        int to = v[x][i].first;
        int cost = v[x][i].second;
        if(to!=par)
        {
            dfs2(to,x,cost);
        }
    }
}
int main()
{
    int n;
    sc(n);
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        sc(a); sc(b);
        v[a].pb({b,0});
        v[b].pb({a,1});
    }
    dp[1] = dfs1(1,0);
    dfs2(1,0,0);
    int mn = INT_MAX;
    for(int i=1;i<=n;i++)
    {
        mn = min(mn,dp[i]);
    }
    cout<<mn<<"\n";
    for(int i=1;i<=n;i++)
    {
        if(dp[i]==mn)
            printf("%d ",i);
    }
    cout<<"\n";
    return 0;

}