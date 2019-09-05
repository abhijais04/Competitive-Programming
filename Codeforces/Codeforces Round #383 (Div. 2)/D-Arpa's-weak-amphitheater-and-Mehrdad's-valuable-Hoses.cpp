#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
ll visited[1010];
ll b[2010],w[2010];
vector<ll> v[1010];
ll dp[1010];
vector<ll> forest[1010];
ll n;
void dfs(ll x,ll g)
{
    if(visited[x])
        return ;
    visited[x]=1;
    forest[g].pb(x);
    b[n+g]+=b[x];
    w[n+g]+=w[x];
    for(ll i=0;i<v[x].size();i++)
    {
        ll y=v[x][i];
        if(!visited[y])
        {
            dfs(y,g);
        }
    }
    return ;
}
int main()
{
    ll m,ww;
    cin>>n>>m>>ww;
    for(ll i=1;i<=n;i++)
    {
        cin>>w[i];
    }
    for(ll i=1;i<=n;i++)
    {
        cin>>b[i];
    }
    for(ll i=0;i<m;i++)
    {
        ll x,y;
        cin>>x>>y;
        v[x].pb(y);
        v[y].pb(x);
    }
    ll cnt=0;
    for(ll i=1;i<=n;i++)
    {
        if(!visited[i])
        {
            cnt++;
            dfs(i,cnt);
        }
    }
    for(ll i=1;i<=cnt;i++)
    {
        forest[i].pb(n+i);
    }
    for(ll g=1;g<=cnt;g++)
    {
        for(ll j=ww;j>=0;j--)
        {
            for(ll i=0;i<forest[g].size();i++)
            {
                ll x = forest[g][i];
                if(w[x]<=j)
                {
                    dp[j]=max(dp[j],dp[j-w[x]]+b[x]);
                }
            }
        }
    }
    cout<<dp[ww]<<"\n";
}