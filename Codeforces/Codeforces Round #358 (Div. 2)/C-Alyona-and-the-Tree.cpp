#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define ll long long
#define pb push_back
vector <pair <int,int> >v[100010];
int dist[1000010];
bool visited[100010]={false};
int child[100010];
int a[100010];
int dfs(int b,int x)
{

    if(visited[b]==true)
        return 0;
      //  cout<<b<<"\n";
    visited[b]=true;
    for(int i=0;i<v[b].size();i++)
    {
        int tmp1=v[b][i].first;
        int tval = v[b][i].second;
        if(!visited[tmp1])
        {
            dist[tmp1]=max(tval,x+tval);
            child[b]+=dfs(tmp1,dist[tmp1]);
        }
    }
    child[b]++;
    return child[b];
}
int ans=0;
bool visited2[100010];
void dfs2(int b)
{
    if(visited2[b]==true)
        return ;
    visited2[b]=true;
    if(dist[b]>a[b])
    {
        ans+=child[b];
        return ;
    }
    for(int i=0;i<v[b].size();i++)
    {
        int tmp1=v[b][i].first;
        //int tval = v[b][i].second;
        if(!visited2[tmp1])
        {
            //dist[b]=max(dist[b],dist[b]+tval);
            dfs2(tmp1);
        }
    }
    return ;
}
int main()
{
    int n;
    cin>>n;
    int i=0;
    for(i=1;i<=n;i++)
        cin>>a[i];
    for(i=1;i<n;i++)
    {
        int aw,b;
        cin>>aw>>b;
        v[i+1].pb({aw,b});
        v[aw].pb({i+1,b});
    }
    dfs(1,0);
    dfs2(1);
   // for(i=1;i<=n;i++)
     //   cout<<dist[i]<<" "<<a[i]<<" "<<child[i]<<"\n";
    cout<<ans<<"\n";
   // cout<<r<<endl;
}