#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
int cat[100010];
vector<int> v[100010];
int n,m;
int ans;
bool visited[100010];
bool isleaf(int x)
{
    if((v[x].size()>1)||x==1)
        return false;
    return true;
}
void dfs(int x,int cur,int pre)
{
    if(visited[x])
        return ;
    //cout<<x<<" \n";
    visited[x]=true;

    if(pre==0)
        cur=0;
    if(cat[x])
        cur++;
    if(cur>m)
        return ;
    if(isleaf(x))
    {
        if(cur<=m)
        ans++;
        return ;
    }
    for(int i=0;i<v[x].size();i++)
    {
        if(!visited[v[x][i]])
            dfs(v[x][i],cur,cat[x]);
    }
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>cat[i];
    }
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        v[a].pb(b);
        v[b].pb(a);
    }
    dfs(1,0,0);
    cout<<ans<<"\n";
    return 0;
}