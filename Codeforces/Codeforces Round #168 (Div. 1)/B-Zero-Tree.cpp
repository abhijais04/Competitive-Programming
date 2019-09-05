#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
ll inc[100010];
ll de[100010];
vector<int> v[100010];
ll val[100010];
void dfs(int x,int par)
{
    for(int i=0;i<v[x].size();i++)
    {
        int y=v[x][i];
        if(par!=y)
        {
            dfs(y,x);
            inc[x]=max(inc[x],inc[y]);
            de[x]=max(de[x],de[y]);
        }
    }
    ll tmp = val[x]-inc[x]+de[x];
    if(tmp>0)
        inc[x]+=tmp;
    else
        de[x]-=tmp;

}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        v[a].pb(b);
        v[b].pb(a);
    }
    for(int i=1;i<=n;i++)
        cin>>val[i];
    dfs(1,0);
    cout<<de[1]+inc[1]<<"\n";
}