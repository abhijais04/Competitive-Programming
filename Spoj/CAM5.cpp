#include <bits/stdc++.h>
using namespace std;
bool visited[100011];
vector<vector<int> >v(100010);

void dfs(int i)
{
    if(visited[i])
    return ;
    visited[i]=true;
    for(vector <int>::iterator it=v[i].begin();it!=v[i].end();it++)
    {
        if(!visited[*it])
        dfs(*it);
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,e,i;
        scanf("%d%d",&n,&e);
        for(i=1;i<=n;i++)
        {
            visited[i]=false;
           v[i].clear();
        }
       
        for(i=0;i<e;i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            v[a+1].push_back(b+1);
            v[b+1].push_back(a+1);
        }
        int count=0;
        for(i=1;i<=n;i++)
        {
            if(!visited[i])
            count++;
            dfs(i);
        }
        printf("%d\n",count);
    }
    return 0;
}