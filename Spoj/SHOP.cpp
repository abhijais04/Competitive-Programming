#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sc(x) scanf("%lld",&x)
int arrx[4]={1,-1,0,0};
int arry[4]={0,0,1,-1};
int n,m;
string s[25];
int dis[30][30];
bool valid(int x,int y)
{
    return (x<n&&y<m&&x>=0&&y>=0&&s[x][y]!='X');
}
void bfs(int x,int y)
{
    dis[x][y]=0;
    queue<pair<int,int> > q;
    q.push({x,y});
    while(!q.empty())
    {
        pair<int,int> tmp = q.front();
        q.pop();
        int tx = tmp.first;
        int ty = tmp.second;
        for(int i=0;i<4;i++)
        {
            int xx = tx + arrx[i];
            int yy = ty + arry[i];
            if(valid(xx,yy) && (dis[xx][yy] > dis[tx][ty] + (s[xx][yy] - '0')))
            {
                dis[xx][yy] = dis[tx][ty] + s[xx][yy] - '0';
                q.push({xx,yy});
            }
        }
    }
}
void solve()
{
    for(int i=0;i<n;i++)
        cin>>s[i];
    int x=-1,y=-1,tx,ty;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            {
                if(s[i][j]=='S')
                    {
                        dis[i][j]=0;
                        x = i;y =j;
                    }
                else
                    dis[i][j]=1e9;
                if(s[i][j]=='D')
                {
                    s[i][j]='0';
                    tx = i;
                    ty = j;
                }
            }
    }
    bfs(x,y);
    cout<<dis[tx][ty]<<"\n";
}
int main()
{
    while(1)
    {
        cin>>m>>n;
        if(n==0 && m==0)
            return 0;
        else
            solve();
    }
}
