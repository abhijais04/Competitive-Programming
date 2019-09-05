#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
vector<int> v[1010],v2[1010];
bool visited[1010][1010];
void dfs(int x,int y)
{
    if(visited[x][y])
    {
        return ;
    }
    visited[x][y]=1;
    for(int i=0;i<v[x].size();i++)
    {
        if(v[x][i]!=y)
        dfs(x,v[x][i]);
    }
    for(int i=0;i<v2[y].size();i++)
    {
        if(v2[y][i]!=x)
        dfs(v2[y][i],y);
    }
}
vector<pair<int,int> > tmp;
int main()
{
    int n;
    cin>>n;
    int ans=0;
    while(n--)
    {
        int x,y;
        cin>>x>>y;
        v[x].pb(y);
        v2[y].pb(x);
        tmp.pb({x,y});
    }
    //sort(v.begin(),v.end());
    for(int i=0;i<tmp.size();i++)
    {
        int x=tmp[i].first;
        int y=tmp[i].second;
        if(visited[x][y]==0)
        {
            ans++;
            dfs(x,y);
        }
    }
    ans--;
    cout<<ans<<"\n";
    return 0;
}