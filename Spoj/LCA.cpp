#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define gc getchar
//_unlocked
int read() {
  char c = gc();
  while(c<'0' || c>'9') c = gc();
  int ret = 0;
  while(c>='0' && c<='9') {
    ret = 10 * ret + c - 48;
    c = gc();
  }
  return ret;
}
int level[1010],visited[1010],u,vi,qr;
int n,i,m,y;
vector <int>v[1010];
int lgn=14;
int par[1010][14];
int main()
{
    int t,cnt=1;
    t=read();
    //scanf("%d",&t);
    while(t--)
    {
        for(i=0;i<=n;i++)
        {
            for(int j=0;j<lgn;j++)
                par[i][j]=-1;
        }
       printf("Case %d:\n",cnt);
       cnt++;
        n=read();
        for(i=0;i<=n;i++)
                {
                    v[i].clear();
                    visited[i]=0;
                    level[i]=0;
                }
        for(i=1;i<=n;i++)
        {
            m=read();
            while(m--)
            {
                y=read();
                par[y][0]=i;
                v[i].pb(y);
                v[y].pb(i);
            }
        }
        level[1]=1;
        list <int >q;
        q.pb(1);
        visited[1]=1;
        while(!q.empty())
        {
            int x;
            x = q.front();
            q.pop_front();
            for(i=0;i<v[x].size();i++)
            {
                if(visited[v[x][i]]!=1)
                {
                    q.pb(v[x][i]);
                    visited[v[x][i]]=1;
                    level[v[x][i]]=level[x]+1;
                }
            }
        }
        for(i=1;i<=n;i++)
        {
            for(int j=1;j<lgn;j++)
            {
                if(par[i][j-1]!=-1)
                {
                    par[i][j]=par[par[i][j-1]][j-1];
                }
            }
        }
       qr=read();
        while(qr--)
        {
           u=read();vi=read();
           if(level[u]<level[vi])
           {
               int tmp=u;
               u=vi;
               vi=tmp;
           }
           for(i=lgn-1;i>=0;i--)
           {
               if(level[u]-(1<<i)>=level[vi])
                u=par[u][i];
           }
           int ans=0;
           if(u!=vi)
           {
               for(i=lgn-1;i>=0;i--)
               {
                   if(par[u][i]!=par[vi][i]&&par[u][i]!=-1)
                   {
                       u=par[u][i];
                       vi=par[vi][i];
                   }
               }
               ans=par[u][0];
           }
           else
            ans=u;
           cout<<ans<<"\n";
        }
    }
    return 0;
}
