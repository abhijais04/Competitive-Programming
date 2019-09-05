#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
int visited[1010];
bool know[110][110];
vector<int> v[110],v2[110];
void dfs(int x)
{
    if(visited[x]!=0)
        return ;
    visited[x]=1;
    for(int i=0;i<v[x].size();i++)
    {
        int ln = v[x][i];
        for(int j=0;j<v2[ln].size();j++)
        {
            if(v2[ln][j]!=x)
                dfs(v2[ln][j]);
        }
    }
}
int main()
{

    int n,m;
    cin>>n>>m;
    int flag=0;
    for(int i=0;i<n;i++)
    {
        int k;
        cin>>k;
        if(k)
            flag=1;
        while(k--)
        {
            int tmp;
            cin>>tmp;
            know[i][tmp]=1;
            v[i].pb(tmp);
            v2[tmp].pb(i);
        }
    }
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(visited[i]==0)
            {
                dfs(i);
                ans++;
            }
    }
    if(flag)
    ans--;
    cout<<ans<<"\n";
    return 0;
}