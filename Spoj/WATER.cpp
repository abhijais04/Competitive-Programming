#include<bits/stdc++.h>
using namespace std;
#define sc(x) scanf("%d",&x)
int ax[4] = {1,-1,0,0};
int ay[4] = {0,0,1,-1};
int n,m;
int mat[101][101],fin[101][101],visited[101][101];
struct node
{
    int x,y,h;
    node(){}
    node(int _x,int _y,int _h)
    {
        this->h = _h;
        this->x = _x;
        this->y = _y;
    }
    bool operator<(node n1)const
    {
        return this->h > n1.h;
    }
};
int valid(int x,int y)
{
    return (x<n && x>=0 && y<m && y>=0);
}
priority_queue<node> pq;

void dfs(int x,int y,int h)
{
    if(visited[x][y])
        return ;
    if(mat[x][y] > h)
    {
        pq.push(node(x,y,mat[x][y]));
        return ;
    }

    visited[x][y]=1;
    fin[x][y]=h;
    for(int i=0;i<4;i++)
    {
        int tx = x + ax[i];
        int ty = y + ay[i];
        if(valid(tx,ty) && !visited[tx][ty])
        {
            dfs(tx,ty,h);
        }
    }
    return ;
}
void solve(int t)
{
    while(pq.size())
        pq.pop();
    sc(n); sc(m);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            visited[i][j]=0;
            fin[i][j] = 0;
            sc(mat[i][j]);
            if(i==0||i==n-1||j==0||j==m-1)
                pq.push(node(i,j,mat[i][j]));
        }
    }
    while(pq.size())
    {
        node n1 = pq.top();
        pq.pop();
        dfs(n1.x,n1.y,n1.h);
    }
    int ans=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            ans+=(fin[i][j] - mat[i][j]);
    }
    printf("%d\n",ans);

}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int t;
    sc(t);
    for(int i=1;i<=t;i++)
        solve(i);
    return 0;
}
