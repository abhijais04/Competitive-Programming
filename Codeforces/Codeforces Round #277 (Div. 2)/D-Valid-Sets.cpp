#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define sc(x) scanf("%d",&x)
ll dp[2001];
int val[2001];
ll m = 1e9+7;
int d,root;
vector<int> v[2001];
void dfs(int x,int par)
{
    dp[x] = 1;
    for(int i=0;i<v[x].size();i++)
    {
        int to = v[x][i];
        if(val[to] < val[root] || val[to] > val[root]+d|| to==par) continue;
        if(val[to]==val[root]&& to < root) continue;
        dfs(to,x);
        dp[x] = dp[x]*(dp[to]+1);
        dp[x]%=m;
    }
    return ;
}
int main()
{
    int n;
    sc(d); sc(n);
    for(int i=1;i<=n;i++) sc(val[i]);
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        sc(a); sc(b);
        v[a].pb(b);
        v[b].pb(a);
    }
    ll ans = 0;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=n;j++) dp[j]=1;
        root = i;
        dfs(i,0);
        ans += dp[i];
        ans%=m;
    }
    cout<<ans<<"\n";
}