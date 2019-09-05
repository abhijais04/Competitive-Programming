#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define sc(x) scanf("%d",&x)
char str[501][501];
int n,m;
int arrx[4]={0,0,1,-1};
int arry[4]={1,-1,0,0};
bool visited[501][501];
int tx,ty;
bool valid(int x,int y)
{
    return (x>=0&&x<n&&y>=0&&y<m);
}
int f=0;
void dfs(int x,int y)
{

    if(f) return ;
    if(visited[x][y]) return ;
   if(x==tx&&y==ty)
    {
        f=1;
        return ;
    }
    visited[x][y]=1;
    for(int i=0;i<4;i++)
        {
            if(valid(x+arrx[i],y+arry[i]))
                {
                    if(str[x+arrx[i]][y+arry[i]]=='.')
                    dfs(x+arrx[i],y+arry[i]);
                    else
                    {
                        if(x+arrx[i]==tx&&y+arry[i]==ty)
                        {
                            f=1;
                            return ;
                        }
                    }
                }
        }
}
int main()
{

    sc(n); sc(m);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>str[i][j];
    int ix,iy;
    sc(ix); sc(iy);
    sc(tx); sc(ty);
    ix--; iy--; tx--; ty--;
    int cnt=0;
    for(int i=0;i<4;i++)
    {
        if(valid(tx+arrx[i],ty+arry[i])&&(str[tx+arrx[i]][ty+arry[i]]=='.'||(tx+arrx[i]==ix&&ty+arry[i]==iy)))
            cnt++;
    }
    if(ix==tx&&iy==ty)
    {
        if(cnt)
            cout<<"YES\n";
        else
            cout<<"NO\n";
        return 0;
    }
    //cout<<ix<<" "<<iy<<"\n";
    dfs(ix,iy);
    if(f&&(str[tx][ty]=='X'||(cnt>1)))
        cout<<"YES\n";
    else
        cout<<"NO\n";
    return 0;
}