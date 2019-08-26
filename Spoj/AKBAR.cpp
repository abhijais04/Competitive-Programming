#include <bits/stdc++.h>
using namespace std;
#define ll long long
inline ll read()
{
  ll ret = 0;
   ll c = getchar_unlocked();
  while(c<'0' || c>'9')
    c = getchar_unlocked();
  while(c>='0' && c<='9')
  {
    ret = (ret<<3) + (ret<<1) + c - '0';
    c = getchar_unlocked();
  }
        return ret;
}
vector <ll>v[1000010];
ll p[1000010],dist[1000010];
list <pair<ll,ll> >q;
bool visited[1000100];
int main()
{
    ll t;
    t=read();
    while(t--)
    {
        ll n,r,m,i;
        n=read();
        r=read();
        m=read();

        for(i=1;i<=n;i++)
            {
                p[i]=0;
                v[i].clear();
            }

        while(r--)
        {
            ll a,b;
            a=read();
            b=read();
            v[a].push_back(b);
            v[b].push_back(a);
        }
        ll city[m+1],st[m+1];
        for(i=0;i<m;i++)
        {
            city[i]=read();
            st[i]=read();
        }
        ll flag=1;
        	 for(i=0;i<=n;i++)
    		 visited[i]=0;
    		ll cnt=0;
        //while(m--)
        for(int j=0;j<m;j++)
        {

            ll a,b;
            a=city[j];
            b=st[j];
            p[a]++;
           // dist[a]=0;
            q.push_back({a,b});
            visited[a]=1;
            cnt++;
        //    count++;
            while(flag==1&&b>0&&!q.empty())
            {
                ll x=q.front().first;
                ll y=q.front().second;
                if(y==0)
                break;
                q.pop_front();
                for(i=0;i<v[x].size();i++)
                {
                    if(visited[v[x][i]]==0)
                    {
                        q.push_back({v[x][i],y-1});
                        p[v[x][i]]++;
                        if(p[v[x][i]]>1)
                        {
                        	flag=0;
                        	break;
                        }
                        visited[v[x][i]]=1;
                        cnt++;
                    }
                }
             }
             if(cnt>=n&&j<m-1)
             {
             	flag=0;
             	break;
             }
             q.clear();
        }
        for(i=1;i<=n;i++)
        {
            if(p[i]!=1)
               break;
        }
        if(i!=n+1||flag==0)
            cout<<"No\n";
        else
            cout<<"Yes\n";
    }
    return 0;
}
