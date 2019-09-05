#include<bits/stdc++.h>
using namespace std;
int n,m,k;
char ch[100][100];
int visited[60][60];
int visited2[60][60];
int xx[4]={0,0,-1,1};
int yy[4]={1,-1,0,0};
priority_queue<pair<int,pair<int,int> > > pq;
int dfs(int a,int b,int c)
{
    if(ch[a][b]!='.')
        return 0;
    if(visited[a][b]!=0)
        return 0;
    visited[a][b]=c;
    int ans=0;
    for(int i=0;i<4;i++)
    {
        int x = a+xx[i];
        int y = b+yy[i];
        if(x>=0&&y>=0&&x<n&&y<m&&ch[x][y]=='.')
        {
            if(visited[x][y]==0)
            {
                ans+=dfs(x,y,c);
            }
        }
    }
    return 1+ans;
}
void fn(int a,int b)
{
    if(visited2[a][b]==1)
        return ;
    visited2[a][b]=1;
    ch[a][b]='*';
    for(int i=0;i<4;i++)
    {
        int x = a+xx[i];
        int y = b+yy[i];
        if(x>=0&&y>=0&&x<n&&y<n)
        {
            if(ch[x][y]=='.')
            {
                fn(x,y);
            }
        }
    }

    return ;
}
int main()
{
    cin>>n>>m>>k;
    int i,j;
    for(i=0;i<n;i++)
        cin>>ch[i];
    for(i=0;i<n;i++)
    {
        if(visited[i][0]==0)
        {
            int tt=dfs(i,0,-1);
        }
    }
    for(i=0;i<m;i++)
    {
        if(visited[0][i]==0)
            int tt=dfs(0,i,-1);
    }
    for(i=0;i<m;i++)
    {
        if(visited[n-1][i]==0)
            int tt=dfs(n-1,i,-1);
    }
    for(i=0;i<n;i++)
    {
        if(visited[i][m-1]==0)
            int tt=dfs(i,m-1,-1);
    }
    int total=0;
    for(i=1;i<n-1;i++)
    {
        for(j=1;j<m-1;j++)
        {
            if(ch[i][j]=='.'&&visited[i][j]==0)
            {
                int tmp = dfs(i,j,1);
                if(tmp>0)
                {
                pq.push({-tmp,{i,j}});
                total++;
                }
            }
        }
    }
    int ans=0;
    for(i=0;i<total-k;i++)
    {
        if(pq.empty()==false)
        {
        int sz = -pq.top().first;
        int a = pq.top().second.first;
        int b = pq.top().second.second;
        pq.pop();
        fn(a,b);
        ans+=sz;
        }
    }
    cout<<ans<<"\n";
    for(i=0;i<n;i++)
    {
        cout<<ch[i]<<"\n";
    }
}