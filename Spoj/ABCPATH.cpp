#include <bits/stdc++.h>
using namespace std;
string s[55];
int h,w;
int va;
int a[8]={1,1,1,-1,-1,-1,0,0};
int b[8]={-1,0,1,-1,0,1,-1,1};
int dist[51][51];
void dfs(int i,int j,int d)
{
    dist[i][j]=1;
   va=max(va,d);
        for(int k=0;k<8;k++)
        {
            int u=i+a[k],v=j+b[k];
            if(u<h&&v<w&&u>=0&&v>=0)
            {
                if((s[u][v]==s[i][j]+1)&&dist[u][v]==0)
                {
                    dfs(u,v,d+1);
                }
            }
        }
    return ;
}
int main()
{
    int cnt=1;
    while(1)
    {
        int i,j;
        for(i=0;i<50;i++)
        {
            for(j=0;j<50;j++)
                dist[i][j]=0;
        }
        va=0;
        cin>>h>>w;
        if(h==0&&w==0)
            break;
        for(i=0;i<h;i++)
        {
            cin>>s[i];
        }
        for(i=0;i<h;i++)
        {
            for(j=0;j<w;j++)
            {
                if(s[i][j]=='A')
                {
                    dfs(i,j,1);
                }
            }
        }
        cout<<"Case "<<cnt<<": "<<va<<"\n";
        cnt++;
    }
    return 0;
}
