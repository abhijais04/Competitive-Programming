#include <bits/stdc++.h>
using namespace std;
vector <int>v[100010];
bool visited[100010];
int cc=0;
void dfs(int i,int par)
{
    if(visited[i])
    return ;
    visited[i]=true;
    for(int j=0;j<v[i].size();j++)
    {
        if(visited[v[i][j]]&&v[i][j]!=par)
        {
            cc=1;
           // return ;
        }
        else
        dfs(v[i][j],i);
    }
    return ;
}
int main() {
    int n,m,i;
    cin>>n>>m;
    while(m--)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int c=0;
    for(i=1;i<=n;i++)
    {
        if(!visited[i])
        {
            cc=0;
             dfs(i,0);
             if(cc==0)
             c++;
        }
    }
    cout<<c<<"\n";
	return 0;
}