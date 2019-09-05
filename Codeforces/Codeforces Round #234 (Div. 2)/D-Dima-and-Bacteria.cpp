#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define sc(x) scanf("%d",&x)
int cost[511][511];
int type[100010];
int sz[100010];
vector<int> gr[100010];
bool visited[100010];
int ss;
int rt;
void dfs(int x)
{
    if(visited[x]) return ;
    visited[x]=1;
    for(int i=0;i<gr[x].size();i++)
        dfs(gr[x][i]);
    if(type[x]==rt)
        ss++;
    return ;
}
int main()
{
    int n,m,k;
    sc(n); sc(m); sc(k);
    int cur=1;
    for(int i=1;i<=k;i++)
    {
        for(int j=1;j<=k;j++)
            cost[i][j]=1e8;
    }
    for(int i=1;i<=k;i++)
    {
        cost[i][i]=0;
        sc(sz[i]);
        for(int j=0;j<sz[i];j++)
        {
            type[cur]=i;
            cur++;
        }
    }

    while(m--)
    {
        int a,b,c;
        sc(a); sc(b); sc(c);
        if(c==0)
            {

                gr[a].pb(b);
                gr[b].pb(a);
            }
        int ta = type[a];
        int tb = type[b];
        cost[ta][tb]=min(cost[ta][tb],c);
        cost[tb][ta]=cost[ta][tb];
    }

    int f=1;
    int sum=0;
    for(int i=1;i<=k;i++)
    {
        ss = 0;
        int x = sum+1;
        rt=i;
        for(int j=0;j<=n;j++)
        visited[j]=0;
        dfs(x);
        if(ss!=sz[i])
        {
            cout<<"No\n";
            return 0;
        }
        sum+=sz[i];
    }

    for(int x=1;x<=k;x++)
    {
        for(int i=1;i<=k;i++)
        {
            for(int j=1;j<=k;j++)
            {
                cost[i][j] = min(cost[i][j],cost[i][x]+cost[x][j]);
            }
        }
    }
    cout<<"Yes\n";
    for(int i=1;i<=k;i++)
    {
        for(int j=1;j<=k;j++)
        {
            if(cost[i][j]>=1e8)
                printf("-1 ");
            else
                printf("%d ",cost[i][j]);
        }
        printf("\n");
    }
    return 0;
}