#include <bits/stdc++.h>
using namespace std;
int n,m;
bool visited[40010];
vector <int>v[40010];
void dfs(int i)
{
    if(visited[i])
        return ;
    visited[i]=true;
    for(int j=0;j<v[i].size();j++)
    {
        if(!visited[v[i][j]])
            dfs(v[i][j]);
    }
}
int main()
{
   // int n,m;
    cin>>n>>m;
    int i;
    for(i=1;i<n;i++)
    {
        int a;
        cin>>a;
        v[i].push_back(a+i);
    }
    dfs(1);
    if(visited[m])
        cout<<"YES\n";
    else
        cout<<"NO\n";
}