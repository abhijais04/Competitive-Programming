#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define sc(x) scanf("%d",&x)
vector<int> v[150010];
bool visited[150010];
ll dfs(int x,int par)
{
    if(visited[x])
        return 0;
       visited[x]=1;
    ll cnt=0;
    for(int i=0;i<v[x].size();i++)
    {
        if(par!=v[x][i])
        cnt+=dfs(v[x][i],x);
    }
    return cnt+1;
}
int main()
{
    int n,m;
    cin>>n>>m;

    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        v[a].pb(b);
        v[b].pb(a);
    }
    ll need=0;
    for(int i=1;i<=n;i++)
    {
        if(!visited[i])
        {
             ll pp = dfs(i,0);
             need += pp*(pp-1)/2;
        }
    }

    if(m!=need)
        cout<<"NO\n";
    else
        cout<<"YES\n";
    return 0;
}