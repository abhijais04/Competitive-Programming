#include <bits/stdc++.h>
using namespace std;
#define pb push_back
int mark[100010];
vector <int>v[100010];
int visited[100010];
void dfs(int a)
{
    //visited[a]=1;
    if(v[a].size()==0)
        return ;
    for(int i=0;i<v[a].size();i++)
    {
        if(visited[v[a][i]]==0)
        {
            visited[v[a][i]]=1;
            dfs(v[a][i]);
            if(mark[a]==0&&mark[v[a][i]]==0)
            {
                mark[a]=1;
            }
        }

    }
    return ;
}
int main()
{
    int n,i;
    cin>>n;
    for(i=1;i<n;i++)
    {
        mark[i]=0;
        visited[i]=0;
        int a,b;
        cin>>a>>b;
        v[b].pb(a);
        v[a].pb(b);
    }
    mark[n]=0;
    visited[n]=0;
    for(i=1;i<=n;i++)
    {
        if(v[i].size()>1)
        {
            visited[i]=1;
            dfs(i);
            break;
        }
    }
    int cnt=0;
    for(i=1;i<=n;i++)
    {
        if(mark[i]==1)
        {
            cnt++;
        }
    }
    if(n<=2)
        cnt=1;
    cout<<cnt<<"\n";
    return 0;
}
