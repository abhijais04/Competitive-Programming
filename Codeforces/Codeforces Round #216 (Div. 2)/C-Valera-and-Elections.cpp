#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
vector<pair<int,int> > v[100100];
bool visited[100010];
vector<int> ans;
bool isleaf(int x)
{
    if(v[x].size()>1)
        return false;
    for(int i=0;i<v[x].size();i++)
    {
        if(!visited[v[x][i].first])
            return false;
    }
    return true;
}
int dfs(int x,int y)
{
    if(visited[x])
        return 0;
    //cout<<x<<"\n";
    visited[x]=true;
    if(isleaf(x))
    {
        if(y==2)
        {
            ans.pb(x);
            return 1;
        }
        return 0;
    }
    int tans=0;
    int flag=0;
    for(int i=0;i<v[x].size();i++)
    {
        tans=dfs(v[x][i].first,v[x][i].second);
        if(tans==1)
            flag=1;
    }
    if(y==2)
    {
        if(flag==0)
        {
            ans.push_back(x);
        }
        return 1;
    }
    return flag;

}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<n;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        v[a].pb({b,c});
        v[b].pb({a,c});
    }
    int tmp=dfs(1,0);
    cout<<ans.size()<<"\n";
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
    cout<<"\n";
}